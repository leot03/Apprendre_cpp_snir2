#include <iostream>
#include "carton.h"
#include "caissedebouteilles.h"

using namespace std;

int main()
{
    CaisseDeBouteilles uneCaisse(50,40,30,6,33);
    Carton leCarton(50,40,30,500);

    cout << "Volume de la caisse : " << uneCaisse.CalculerVolume() << " cl" << endl;

    Contenant * ptrContenant = static_cast<Contenant *>(&uneCaisse);
    cout << "Volume brute de la caisse : " << ptrContenant->CalculerVolume() << endl;

    cout << "Autre sokution : " << uneCaisse.Contenant::CalculerVolume() << endl;

    return 0;
}
