
#include <iostream>
#include "barrecarree.h"
#include "barreronde.h"

using namespace std;

int main()
{
    barreCarree uneBarre("00003", 200, 8.92, "Barre 2x2 en Cuivre", 2);
        uneBarre.AfficherCaracteristiques();
        cout << "Le poids de la barre est : " << uneBarre.CalculerMasse();
        cout << endl;

    BarreRonde uneBarreRonde("00004", 200, 8.92, "Barre ronde diamètre", 2);
        uneBarreRonde.AfficherCaracteristiques();
        cout << "Le poids de la barre est : " << uneBarreRonde.CalculerMasse();
        cout << endl;

        return 0;
}
