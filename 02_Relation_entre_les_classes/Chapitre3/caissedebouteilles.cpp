#include "caissedebouteilles.h"
#include <iostream>

using namespace std;

CaisseDeBouteilles::CaisseDeBouteilles(const int _largeur, const int _hauteur, const int _profondeur, const int _nbBouteilles, const int _contenance):
    Contenant(_largeur, _hauteur, _profondeur),
    nbBouteilles(_nbBouteilles),
    contenance(_contenance)
{
    cout << "Consutructeur de la classe CaisseDeBouteills" << endl;
}


int CaisseDeBouteilles::calculerVolumes(){
    return nbBouteilles * contenance;
}
