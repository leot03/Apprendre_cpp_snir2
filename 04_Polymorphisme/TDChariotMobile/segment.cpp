#include "segment.h"
#include <iostream>
#include <iomanip>
using namespace std;

Segment::Segment(const double _longueur, const double _angle):
    longueur(_longueur),
    angle(_angle)
{

}

void Segment::Afficher()
{
    cout << "Trajectoire :" << endl;
    cout << "SEGMENT L = " <<  longueur << setw(12) << "A = " << angle << endl;
}
