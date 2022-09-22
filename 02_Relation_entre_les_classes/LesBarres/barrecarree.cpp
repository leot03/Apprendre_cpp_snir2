#include "barrecarree.h"
#include "barre.h"

#include <iostream>

using namespace std;

barreCarree::barreCarree(const string _reference, const int _longueur, const float _densite, const string _nomAlliage, const unsigned int _cote):
    Barre (_reference,_longueur,_densite,_nomAlliage),
    cote(_cote)
{
    cout << "Constructeur de la Classe Barre Carrée \n" << endl;
}

barreCarree::~barreCarree()
{
    cout << "Destructeur de la Classe Barre Carrée" << endl;
}

double barreCarree::CalculerSection()
{

    return cote*cote;
}

float barreCarree::CalculerMasse()
{
    float masse = 0;

    masse = longueur*CalculerSection()*densite;


    return masse;
}

void barreCarree::AfficherCarateristique()
{

    Barre::AfficherCaracteristiques();
    cout << "Côté du carré : " << cote << " cm" << endl;

}
