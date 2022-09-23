#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H
#include "comptebancaire.h"

/**
 * @file compteepargne.h
 * @author Léo THOMAS
**/

class CompteEpargne : public CompteBancaire
{
public:
    void CalculerInterets();
    CompteEpargne(const float _montant_initial);
    CompteEpargne();
    ~CompteEpargne();
private:
    float tauxPourcentage;
};

#endif // COMPTEEPARGNE_H
