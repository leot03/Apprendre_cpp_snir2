#ifndef BARRERONDE_H
#define BARRERONDE_H
#include "barre.h"
#include <math.h>


class BarreRonde : public Barre
{
public:
    BarreRonde(const string _reference, const int _longueur, const float _densite, const string _nomAlliage,const double diametre);
    ~BarreRonde();
    double CalculerSection();
    float CalculerMasse();
    void AfficherCarateristique();
protected:
    double diametre;
};

#endif // BARRERONDE_H
