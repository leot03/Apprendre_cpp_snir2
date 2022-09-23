#include "compteepargne.h"

/**
 * @file comptebancaire.cpp
 * @author Léo THOMAS
**/

void CompteEpargne::CalculerInterets()
{
    solde = solde + (tauxPourcentage * solde/100);
}

CompteEpargne::CompteEpargne(const float _montant_initial):
    CompteBancaire(_montant_initial),
    tauxPourcentage(2)
{
    cout << "Constructeur de la classe CompteEpargne" << endl;
}

CompteEpargne::CompteEpargne()
{
    //cout << "Constructeur de la classe CompteEpargne" << endl;
}

CompteEpargne::~CompteEpargne()
{
    cout << "Destructeur de la classe CompteEpargne" << endl;
}



/**
* @author Léo THOMAS
**/
