#include "chariot.h"
#include <iostream>

using namespace std;


void Chariot::DeplacerChariot(const bool _sens, const int _rangee, const int _colonne)
{
    if(_sens == VERS_MAGASIN) {
        cout << "Transfert du rouleau vers le magasin" << endl;
        cout << "Dans l'alvéole" << _rangee << " - " << _colonne << endl;
    } else {
        cout << "Transfert du rouleau vers l'enceinte" << endl;
        cout << "À partir de l'alvéole" << _rangee << " - " << _colonne << endl;
    }
}
