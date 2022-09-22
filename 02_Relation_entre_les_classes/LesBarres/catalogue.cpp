#include "catalogue.h"
#include <iostream>

using namespace std;

Catalogue::Catalogue(const int _nbBarres):
    nbBarres(_nbBarres)
{

    lesBarres = new Barre *[nbBarres];
    index = 0;
}

Catalogue::~Catalogue()
{
    delete [] lesBarres;
}

bool Catalogue::AjouterBarre(Barre *ptrBarre)
{

    bool retour = true;
    if (index < nbBarres)
        lesBarres[index++] = ptrBarre;
    else
        retour = false;
    return retour;
}



void Catalogue::AfficherCatalogue()
{
    for (int i = 0; i < nbBarres; i++)
    {

        lesBarres[i]->AfficherCaracteristiques();
        cout << lesBarres[i]->CalculerMasse() << endl;

    }
}
