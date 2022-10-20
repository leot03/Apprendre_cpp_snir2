#ifndef STOCK_H
#define STOCK_H

#include <set>
#include <iostream>

#include "rouleau.h"

typedef multiset< Rouleau > multisetRouleau;


class Stock: public multisetRouleau
{
public:
    void AjouterRouleau(const Rouleau &_nouveauRouleau);
    int RechercherSerie(Stock::iterator &_positionDebut);
    bool SortirRouleau(const Stock::iterator &_positionRouleau);

    void Visualiser();
};

#endif // STOCK_H
