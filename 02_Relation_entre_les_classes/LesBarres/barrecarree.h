#ifndef BARRECARREE_H
#define BARRECARREE_H
#include "barre.h"
#include <math.h>

class BarreCarree : public Barre
{
public:
    BarreCarree(const string _reference, const int _longueur, const float _densite, const string _nomAlliage,const int _largeur, const unsigned int _cote=5);
    ~BarreCarree();
    double CalculerSection();
    float CalculerMasse();
    void AfficherCarateristique();
private:
    int largeur;
    unsigned int cote;
};

#endif // BARRECARREE_H
