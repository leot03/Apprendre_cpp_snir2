#include "barreronde.h"


BarreRonde::BarreRonde(const string _reference, const int _longueur, const float _densite, const string _nomAlliage, const double _diametre):
    Barre(_reference,_longueur,_densite,_nomAlliage),
    diametre(_diametre)
{
    cout << "Constructeur de la Classe barreRonde \n" << endl;
}

BarreRonde::~BarreRonde()
{
    cout << "Destructeur de la Classe barreRonde" << endl;
}

double BarreRonde::CalculerSection()
{
    return (M_PI*(diametre*diametre)/4);
}

float BarreRonde::CalculerMasse()
{
    float masse = 0;

    masse = longueur*CalculerSection()*densite;


    return masse;
}

float BarreRonde::AfficherCarateristique()
{

    Barre::AfficherCaracteristiques();
    cout << "Côté du carré : " << diametre << " cm" << endl;

}
