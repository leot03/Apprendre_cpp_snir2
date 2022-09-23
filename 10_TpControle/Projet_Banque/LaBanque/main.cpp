#include <iostream>
#include "menu.h"
#include "comptebancaire.h"
#include "compteepargne.h"

using namespace std;

/**
 * @author Léo THOMAS
 * @date 23 septembre 2022
 * @file main.cpp
**/

enum CHOIX_MENU
{
    OPTION_1 = 1,
    OPTION_2,
    OPTION_3,
    OPTION_4,
    QUITTER
};

int main() {
    CompteBancaire Compte;
    CompteEpargne Epargne;
    int choix;
    float valDepot;
    float valRetrait;
    float valInteret;

    Menu menuCompteDepot("../LaBanque/menuCompteDepot.txt");
    Menu menuCompteBancaire("../LaBanque/compteBancaire.txt");
    Menu menuCompteEpargne("../LaBanque/compteEpargne.txt");

    try {
        do
        {
            choix = menuCompteBancaire.Afficher();
            // choix = menuCompteEpargne.Afficher();
            switch (choix)
            {
            case OPTION_1:
                Compte.ConsulterSolde();
                menuCompteDepot.AttendreAppuiTouche();
                break;
            case OPTION_2:
                cout << "Entrez la valeur du depôt que vous souhaitez faire : " << endl;
                cin >> valDepot;
                Compte.Deposer(valDepot);
                cout << "Vous venez de déposer : " << valDepot << "€ sur votre compte en banque." << endl;
                break;
            case OPTION_3:
                cout << "Entrez la valeur du retrait que vous souhaitez faire : " << endl;
                cin >> valRetrait;
                Compte.Retirer(valRetrait);
                cout << "Vous venez de déposer : " << valRetrait << "€ sur votre compte en banque." << endl;
                break;
            }

        } while(choix != QUITTER);
    } catch (std::runtime_error e) {
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}




/**
* @author Léo THOMAS
**/
