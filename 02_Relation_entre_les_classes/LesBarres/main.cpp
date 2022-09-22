
#include <iostream>
#include "barrecarree.h"
#include "barreronde.h"

using namespace std;

int main()
{
    BarreCarree uneBarre("00003","Barre 2x2 en Cuivre", 200, 8.920, 2);
        uneBarre.AfficherCaracteristiques();
        cout << "Le poids de la barre est : " << uneBarre.CalculerMasse();
        cout << endl;

    BarreRonde uneBarreRonde("00004", "Barre ronde diamètre");
        uneBarreRonde.AfficherCaracteristiques();
        cout << "Le poids de la barre est : " << uneBarreRonde.CalculerMasse();
        cout << endl;

        return 0;
}
