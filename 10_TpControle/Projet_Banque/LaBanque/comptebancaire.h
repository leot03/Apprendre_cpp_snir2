#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H
#include <iostream>

/**
 * @file comptebancaire.h
 * @author Léo THOMAS
**/

using namespace std;

class CompteBancaire {
public:
    void ConsulterSolde();
    void Deposer(const float _montant);
    void Retirer(const float _montant);
    ~CompteBancaire();
    CompteBancaire(const float _montant_initial);
    CompteBancaire();
protected:
    float solde;
};



#endif // COMPTEBANCAIRE_H
