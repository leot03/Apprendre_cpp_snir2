#include "alveoleslibres.h"
#include "menu.h"
#include "magasin.h"
#include <iostream>

using namespace std;


enum CHOIX_MENU
{
    ENTREE_ROULEAU = 1,
    SORTIR_SERIE,
    VISUALISER,
    QUITTER
};

int main()
{
    cout << "Gestion du magasin " << endl << endl;
    Magasin leMagasin;
    int choix;
    Menu leMenu("../magasinDeRouleau/menumagasin.txt");
    do
    {
        choix = leMenu.Afficher();
        switch (choix)
        {
        case ENTREE_ROULEAU:
            cout << endl;
            leMagasin.EntrerRouleau();
            Menu::AttendreAppuiTouche();
            break;

        case SORTIR_SERIE:
            cout << endl;
            leMagasin.SortirRouleaux();
            Menu::AttendreAppuiTouche();
            break;

        case VISUALISER:
            cout << endl;
            leMagasin.Visualiser();
            Menu::AttendreAppuiTouche();
            break;
        }

    } while(choix != QUITTER);
    return 0;
}
