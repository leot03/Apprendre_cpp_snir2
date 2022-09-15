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

protected:
    string reference;
};

#endif // BARRE_H
