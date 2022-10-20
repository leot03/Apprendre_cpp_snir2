#include "stock.h"
#include <iostream>

using namespace std;


void Stock::AjouterRouleau(const Rouleau &_nouveauRouleau)
{
    insert(_nouveauRouleau);
}

int Stock::RechercherSerie(Stock::iterator &_positionDebut)
{
    int nbRouleau = (int) size();
    Stock::iterator positionPremier = begin();
    _positionDebut = positionPremier;
    if (nbRouleau > 6) {
        nbRouleau = 6;
        Stock::iterator positionDernier = begin();

        for(int indice = 1; indice < 6; indice++)
            positionDernier++;

        int valeurRetenue = *positionDernier - *positionPremier;
        while (positionDernier != end()) {
            if(valeurRetenue > (*positionDernier - *positionPremier)) {
                _positionDebut = positionPremier;
                valeurRetenue = *positionDernier - *positionPremier;
            }
            positionDernier++;
            positionPremier++;
        }
    }
    return nbRouleau;
}

void Stock::Visualiser()
{
    Stock::iterator it;

    int nbRouleau = 0;

    for (it = begin(); it != end(); it++) {
        it->Visualiser();
        nbRouleau++;
    }
    if (nbRouleau == 0)
        cout << "Le magasin est vide" << endl;
}

bool Stock::SortirRouleau(const Stock::iterator &_positionRouleau)
{
    bool rouleauSuppr = false;
    if(_positionRouleau != end()) {
        rouleauSuppr = true;
        erase(_positionRouleau);
    }
    return rouleauSuppr;
}
/*
int Stock::RechercherSerie(Stock::iterator &_positionDebut)
{
    int nbRouleau = (int) size();
    Stock::iterator positionPremier = begin();

    _positionDebut = positionPremier;
    if(nbRouleau > 6) {
        nbRouleau = 6;
        Stock::interator positionDernier = begin();

        for(int indice = 1; indice < 6; indice++)
            positionDernier++;
        int valeurRetenue = *positionDernier - *positionPremier;
        while (positionDernier != end()) {
            if(ValeurRetenue > (*positionDernier - *positionPremier)) {
                _positionDebut = positionPremier;
                valeurRetenue = *positionDernier - *positionPremier;
            }
            positionDernier ++;
            positionPremier ++;
        }
    }
    return nbRouleau;
}

*/
