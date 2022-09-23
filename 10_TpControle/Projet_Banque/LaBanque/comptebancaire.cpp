/**
 * @file comptebancaire.cpp
 * @author Léo THOMAS
**/

#include "comptebancaire.h"

// Permet de consulter le solde en disponible
void CompteBancaire::ConsulterSolde()
{
    cout << "Le solde de votre compte est de : " << solde << "€" << endl;
}

// Permet de déposer un montant pour qu'il soit ajouter sur le solde
void CompteBancaire::Deposer(const float _montant)
{
    float montant = _montant;
    solde += montant;
}

// Permet de retirer un montant pour qu'il soit retirer du solde
void CompteBancaire::Retirer(const float _montant)
{
    float montant = _montant;
    if(solde > montant) {
        solde -= montant;
    }
}

// Desctructeur de la classe
CompteBancaire::~CompteBancaire()
{
    cout << "Destructeur de la classe CompteBancaire" << endl;
}

// Reprend le solde défini
CompteBancaire::CompteBancaire(const float _montant_initial):
    solde(_montant_initial)
{
    //cout << "Constructeur de la classe CompteBancaire" << endl;
}

// Défini le solde à la valeur qui a été indiquée
CompteBancaire::CompteBancaire():
    solde(150)
{
    //cout << "Constructeur de la classe CompteBancaire" << endl;
}



/**
* @author Léo THOMAS
**/
