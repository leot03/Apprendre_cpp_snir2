#ifndef BARRECARREE_H
#define BARRECARREE_H
#include "barre.h"
#include <math.h>

class barreCarree : public Barre
{
public:
    barreCarree(const string _reference, const int _longueur, const float _densite, const string _nomAlliage, const unsigned int _cote=5);
    ~barreCarree();
    double CalculerSection();
    float CalculerMasse();
    void AfficherCarateristique();
private:
    unsigned int cote;
};

#endif // BARRECARREE_H
