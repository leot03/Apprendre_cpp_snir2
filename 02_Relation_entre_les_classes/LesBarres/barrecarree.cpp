#include "barrecarree.h"
#include "barre.h"
#include <iostream>


BarreCarree::BarreCarree(const string _reference, const int _longueur, const float _densite, const string _nomAlliage, const int _largeur):
    Barre (_reference,_longueur,_densite,_nomAlliage),
    largeur(_largeur)
{
    cout << "Constructeur de la Classe Barre Carrée \n" << endl;
}

BarreCarree::~BarreCarree()
{
    cout << "Destructeur de la Classe Barre Carrée" << endl;
}

double BarreCarree::CalculerSection()
{

    return cote*cote;
}

float BarreCarree::CalculerMasse()
{
    float masse = 0;

    masse = longueur*CalculerSection()*densite;


    return masse;
}

float BarreCarree::AfficherCarateristique()
{

    Barre::AfficherCaracteristiques();
    cout << "Côté du carré : " << cote << " cm" << endl;

}
