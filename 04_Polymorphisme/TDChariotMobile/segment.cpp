#include "segment.h"
#include <iostream>
#include <iomanip>
using namespace std;

Segment::Segment(const double _longueur, const double _angle, const double _vitesse):
    longueur(_longueur),
    angle(_angle),
    vitesse(_vitesse)
{

}

void Segment::Afficher()
{
    cout << "SEGMENT L = " <<  longueur << setw(6) << "A = " << setw(6) << "V = " << vitesse << endl;
    // cout << "SEGMENT L = " <<  longueur << setw(12) << "A = " << angle << endl;
}
