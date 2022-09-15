#include "caissedebouteilles.h"

using namespace std;

CaisseDeBouteilles::CaisseDeBouteilles(const int _largeur, const int _hauteur, const int _profondeur, const int _nbBouteilles, const int _contenance):
    Contenant(_largeur, _hauteur, _profondeur, _nbBouteilles, _contenance),
    nbBouteilles(_nbBouteilles),
    contenance(_contenance)
{
    cout << "Consutructeur de la classe CaisseDeBouteills" << endl;
}

CaisseDeBouteilles::~CaisseDeBouteilles() {
    cout << "Consutructeur de la classe CaisseDeBouteills" << endl;
}

int CaisseDeBouteilles::calculerVolumes(){
    return nbBouteilles * contenance;
}
