#ifndef BARRE_H
#define BARRE_H
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class Barre
{
public:
    Barre(const string _reference,const int _longueur,const float _densite,const string nomAlliage);
    virtual ~Barre();
    virtual void AfficherCaracteristiques();
    virtual float CalculerMasse() = 0;
protected:
    string reference;
    float longueur;
    float densite;
    string nomAlliage;
};

#endif // BARRE_H
