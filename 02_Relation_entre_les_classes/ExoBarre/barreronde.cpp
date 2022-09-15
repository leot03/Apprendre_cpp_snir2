#include "barreronde.h"

BarreRonde::BarreRonde()
{

}

BarreRonde::BarreRonde(const string _reference, const string _nom, const unsigned int _longueur, const double _densite, const unsigned int _diametre):
    reference(_reference),
    nom(_nom),
    longueur(_longueur),
    densite(_densite),
    diametre(_diametre)
{

}

double BarreRonde::calculerSection()
{
    return ((M_1_PI * diametre * diametre)/ 4)
}

double BarreRonde::calculerMasse()
{
    return calculerSection() * longueur * densite;
}
