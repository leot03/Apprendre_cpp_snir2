#ifndef BARRERONDE_H
#define BARRERONDE_H

#include <iostream>
#include <math.h>

using namespace std;

class BarreRonde
{
public:
    BarreRonde(const string _reference,
               const string _nom,
               const unsigned int _longueur,
               const double _densite,
               const unsigned int _diametre);
    double calculerSection();
    double calculerMasse();
};

#endif // BARRERONDE_H
