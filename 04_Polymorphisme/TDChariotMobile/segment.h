#ifndef SEGMENT_H
#define SEGMENT_H

#include "element.h"

class Segment : public Element
{
public:
    Segment(const double _longueur, const double _angle, const double _vitesse);
    void Afficher();
private:
    double longueur;
    double angle;
};

#endif // SEGMENT_H
