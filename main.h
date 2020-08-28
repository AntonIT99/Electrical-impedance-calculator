#ifndef MAIN_H
#define MAIN_H

typedef struct Impedance Impedance;
struct Impedance {

    double Re;
    double Im;
    double Module;
    double Argument;

};

typedef struct Circuit Circuit;
struct Circuit {

    int IDCircuit;
    int IDComposants;
    double Capacite1;
    double Capacite2;
    double Inductance1;
    double Inductance2;
    double Resistance1;
    double Resistance2;
};

void definirGrandeurs(Circuit* circuit);
void definirFrequences(double* fmin, double* fmax, int* nbFrequences);
void definirCircuit(Circuit* circuit);

Impedance definirResistance(double R);
Impedance definirIndutance(double frequence, double L);
Impedance definirCapacite(double frequence, double C);

#endif // MAIN_H
