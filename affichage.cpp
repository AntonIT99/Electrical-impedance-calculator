#include <iostream>
#include <iomanip>
#include <fstream>
#include "main.h"

using namespace std;

void afficherValeurs(Impedance* Z, double* frequences, int nbvaleurs)
{
    cout << "\n\nValeurs :\n" << endl;
    cout << "Frequence \t\t Module \t\t Phase" << endl;

    for (int i = 0; i<nbvaleurs; i++)
    {
        cout << fixed << setprecision(6) << frequences[i] << " Hz\t\t" << Z[i].Module << " Ohms\t\t" << Z[i].Argument << " rad" << endl;
    }
}

void createDATFile(Impedance* Z, double* frequences, int nbvaleurs)
{
    fstream file;

    file.open ("Impedance.dat", fstream::in | fstream::out | fstream::trunc);

    if(file.fail())
    {
        cout << "Echec de la creation du fichier Impedance.dat" << endl;
    }
    else
    {
        for (int i = 0; i<nbvaleurs; i++)
        {
            file << frequences[i] << " " << Z[i].Module << " " << Z[i].Argument << endl;
        }

        cout << "\n\nGeneration du fichier Impedance.dat terminee" << endl;
    }

    file.close();
}
