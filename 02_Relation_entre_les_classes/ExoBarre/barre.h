#ifndef BARRE_H
#define BARRE_H

#include <string>
#include <iostream>

using namespace std;

class Barre
{
public:
    Barre(const string _reference,
          const string _nom,
          const unsigned int _longueur,
          const double _densite);

    ~Barre();

    void AfficherCaracteristique();

private:
    string reference;
    string nom;
    unsigned int longueur;
    double densite;
};

#endif // BARRE_H
