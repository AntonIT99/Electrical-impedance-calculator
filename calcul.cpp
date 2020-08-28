#include <math.h>
#include "main.h"

double Module (Impedance Z)
{
    return sqrt(pow(Z.Re,2) + pow(Z.Im,2));
}

double Argument (Impedance Z)
{
    return 2*atan(Z.Im/(Z.Re + Module(Z)));
}

Impedance ImpedanceCircuit (Impedance Z1, Impedance Z2, int IDCircuit)
{
    Impedance Z3, ZCircuit; //Z3 = Z1 + Z2

    Z3.Re = Z1.Re + Z2.Re;
    Z3.Im = Z1.Im + Z2.Im;
    Z3.Module = Module(Z3);
    Z3.Argument = Argument(Z3);

    if (IDCircuit == 1) //Circuit en serie
    {
        ZCircuit = Z3;
    }

    if (IDCircuit == 2) //Circuit en parallele
    {
        Impedance Z4;
        Z4.Module = (Module(Z1) * Module(Z2)) / Z3.Module;
        Z4.Argument = Argument(Z1) + Argument(Z2) - Z3.Argument;
        Z4.Re = Z4.Module * cos(Z4.Argument);
        Z4.Im = Z4.Module * sin(Z4.Argument);
        ZCircuit = Z4;
    }

    return ZCircuit;
}

double* calculFrequences (double fmin, double fmax, int nbfrequences)
{
    double* frequences = new double [nbfrequences];
    double pas = (fmax - fmin)/(nbfrequences - 1);
    frequences[0] = fmin;
    for (int i = 1; i<nbfrequences; i++)
    {
        frequences[i] = frequences[i-1] + pas;
    }
    return frequences;
}

Impedance* calculImpedances (int nbfrequences, double* frequences, Circuit circuit)
{
    Impedance* Z = new Impedance[nbfrequences];
    Impedance Z1, Z2;

    if((circuit.IDComposants == 1) || (circuit.IDComposants == 2) || (circuit.IDComposants == 3)) //circuits avec au moins une resistance
    {
        Z1 = definirResistance(circuit.Resistance1);

        if(circuit.IDComposants == 1) //circuit avec 2 resistances
        {
            Z2 = definirResistance(circuit.Resistance2);
        }
    }

    for(int i = 0; i<nbfrequences; i++)
    {
        switch (circuit.IDComposants) //calcul des impedances dependant de la frequence en fonction du circuit choisi
        {
            case 2:
                Z2 = definirIndutance(frequences[i], circuit.Inductance1);
                break;

            case 3:
                Z2 = definirCapacite(frequences[i], circuit.Capacite1);
                break;

            case 4:
                Z1 = definirIndutance(frequences[i], circuit.Inductance1);
                Z2 = definirIndutance(frequences[i], circuit.Inductance2);
                break;

            case 5:
                Z1 = definirIndutance(frequences[i], circuit.Inductance1);
                Z2 = definirCapacite(frequences[i], circuit.Capacite1);
                break;

            case 6:
                Z1 = definirCapacite(frequences[i], circuit.Capacite1);
                Z2 = definirCapacite(frequences[i], circuit.Capacite2);
                break;
        }

        Z[i] = ImpedanceCircuit(Z1, Z2, circuit.IDCircuit);
    }

    return Z;
}
