#include <iostream>
#include "stock.h"
#include "rouleau.h"
#include "menu.h"

using namespace std;

enum CHOIX_MENU {
    AJOUTER_ROULEAU = 1,
    RECHERCHER_ROULEAU,
    VISUALISER,
    QUITTER
};

int main()
{

    cout << "Gestion du stocké" <<endl<<endl;


    try {
        Menu leMenu("../magasinDeRouleau/menu.txt");

        int choix;
        string reference;
        int diametre;
        Rouleau *nouvRouleau;
        Stock leStock;
        int nbRouleaux = 0;
        Stock::iterator posDebut;
        Stock::iterator memoDebut;
        char rep;

        do {
            choix = leMenu.Afficher();
            switch (choix) {
            case AJOUTER_ROULEAU:
                cout << "Indiquer les caratéristiques du rouleau à ajouter" << endl;
                cout << "Référence du rouleau : ";
                cin >> reference;
                cout << "Diamètre du rouleau : ";
                cin >> diametre;
                nouvRouleau = new Rouleau(reference, diametre);
                leStock.AjouterRouleau(*nouvRouleau);
                Menu::AttendreAppuiTouche();
                break;
            case RECHERCHER_ROULEAU:
                nbRouleaux = leStock.RechercherSerie(posDebut);
                memoDebut = posDebut;

                cout << "Nombre de rouleaux retenu : " << nbRouleaux << endl;
                for (int indice = 0; indice < nbRouleaux; indice++) {
                    posDebut->Visualiser();
                    posDebut++;
                }

                if(nbRouleaux > 0) {
                    cout << "Voulez vous sortir de la série rouleau du stock O(o)/N(n) ?";
                    cin >> rep;
                    if (rep == '0' || rep == 'o') {
                        for (int indice = 0; indice < nbRouleaux && memoDebut != leStock.end(); ++indice) {
                            leStock.SortirRouleau(memoDebut++);
                        }
                    }
                }
                Menu::AttendreAppuiTouche();
                break;

            case VISUALISER:
                cout << endl << "Affichage des rouleaux" << endl;
                leStock.Visualiser();
                Menu::AttendreAppuiTouche();
                break;
            }
        } while(choix != QUITTER);
    }
    catch (Exception except) {
        cout << "Erreur : " << except.ObtenirCodeErreur() << endl;
        cout << "Message d'erreur : " << except.ObtenirMessage() << endl;
        cout << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
