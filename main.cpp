#include <iostream>
#include <math.h>
#include <cstdlib>
#include "calcul.h"
#include "affichage.h"

using namespace std;

int main()
{
    int nbFrequences;
    double fmin, fmax;
    double* frequences;
    Circuit circuit;
    Impedance* Z;

    definirCircuit(&circuit);
    definirGrandeurs(&circuit);
    definirFrequences(&fmin, &fmax, &nbFrequences);

    frequences = calculFrequences(fmin, fmax, nbFrequences);
    Z = calculImpedances(nbFrequences, frequences, circuit);

    afficherValeurs(Z, frequences, nbFrequences);
    createDATFile(Z, frequences, nbFrequences);

    system("gnuplot graph.p");
    cin.sync();
    cin.get();

    return 0;
}

void definirCircuit(Circuit* circuit)
{
    do {
    cout << "Entrez l'identifiant du type du circuit :\n\t1. Circuit en serie\n\t2. Circuit en parallele" << endl;
    cin >> (circuit->IDCircuit);
    } while ((circuit->IDCircuit < 1) || (circuit->IDCircuit > 2));

    do {
    cout << "Entrez l'identifiant des composants du circuit :\n\t1. RR\n\t2. LR\n\t3. RC\n\t4. LL\n\t5. LC\n\t6. CC" << endl;
    cin >> (circuit->IDComposants);
    } while ((circuit->IDComposants < 1) || (circuit->IDComposants > 6));
}

void definirGrandeurs(Circuit* circuit)
{
    do {
        switch (circuit->IDComposants)
        {
            case 1:
                cout << "Entrez la valeur de la premiere resistance en Ohms :" << endl;
                cin >> (circuit->Resistance1);
                cout << "Entrez la valeur de la deuxieme resistance en Ohms :" << endl;
                cin >> (circuit->Resistance2);
                break;

            case 2:
                cout << "Entrez la valeur de la resistance en Ohms :" << endl;
                cin >> (circuit->Resistance1);
                cout << "Entrez la valeur de l'inductance en Henrys :" << endl;
                cin >> (circuit->Inductance1);
                break;

            case 3:
                cout << "Entrez la valeur de la resistance en Ohms :" << endl;
                cin >> (circuit->Resistance1);
                cout << "Entrez la valeur de la capacite en Farads :" << endl;
                cin >> (circuit->Capacite1);
                break;

            case 4:
                cout << "Entrez la valeur de la premiere inductance en Henrys :" << endl;
                cin >> (circuit->Inductance1);
                cout << "Entrez la valeur de la deuxieme inductance en Henrys :" << endl;
                cin >> (circuit->Inductance2);
                break;

            case 5:
                cout << "Entrez la valeur de l'inductance en Henrys :" << endl;
                cin >> (circuit->Inductance1);
                cout << "Entrez la valeur de la capacite en Farads :" << endl;
                cin >> (circuit->Capacite1);
                break;

            case 6:
                cout << "Entrez la valeur de la premiere capacite en Farads :" << endl;
                cin >> (circuit->Capacite1);
                cout << "Entrez la valeur de la deuxieme capacite en Farads :" << endl;
                cin >> (circuit->Capacite2);
                break;
        }
    } while ((circuit->Capacite1 < 0) || (circuit->Capacite2 < 0) || (circuit->Inductance1 < 0) || (circuit->Inductance2 < 0) || (circuit->Resistance1 < 0) || (circuit->Resistance2 < 0));
    //les valeurs doivent etre positives pour que cela ait physiquement un sens
}

void definirFrequences(double* fmin, double* fmax, int* nbFrequences)
{
    do {
    cout << "Entrez le nombre de frequences :" << endl;
    cin >> (*nbFrequences);
    } while (*nbFrequences <= 0);

    if (*nbFrequences > 1)
    {
        cout << "Entrez la frequence minimale :" << endl;
        cin >> (*fmin);
        cout << "Entrez la frequence maximale :" << endl;
        cin >> (*fmax);
    }
    else if (*nbFrequences == 1)
    {
        cout << "Entrez la frequence:" << endl;
        cin >> (*fmin);
        *fmax = *fmin;
    }
}

Impedance definirResistance(double R)
{
    Impedance Z;
    Z.Re = R;
    Z.Im = 0;
    return Z;
}

Impedance definirIndutance(double frequence, double L)
{
    Impedance Z;
    Z.Re = 0;
    Z.Im = L * 2*M_PI * frequence;
    return Z;
}

Impedance definirCapacite(double frequence, double C)
{
    Impedance Z;
    Z.Re = 0;
    Z.Im = -1 / (C * 2*M_PI * frequence);
    return Z;
}
