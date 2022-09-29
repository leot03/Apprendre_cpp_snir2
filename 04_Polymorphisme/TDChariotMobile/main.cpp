#include <iostream>
#include "trajectoire.h"
#include "segment.h"
#include "element.h"

using namespace std;

int main() {
    Trajectoire laTrajectoire(2);
    laTrajectoire.Ajouter(new Segment(9,0));
    laTrajectoire.Ajouter(new Segment(5,0.48676876));
    laTrajectoire.Afficher();

    return 0;
}
