#ifndef CALCUL_H
#define CALCUL_H

#include <math.h>
#include "main.h"

double Module (Impedance Z);
double Argument (Impedance Z);
double* calculFrequences (double fmin, double fmax, int nbfrequences);

Impedance ImpedanceCircuit (Impedance Z1, Impedance Z2, int IDCircuit);
Impedance* calculImpedances (int nbfrequences, double* frequences, Circuit circuit);

#endif // CALCUL_H
