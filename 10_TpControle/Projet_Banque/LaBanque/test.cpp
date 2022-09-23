int main()
{
    int choixMenuPrincipal;
    int choixMenuCompteDepot;
    int choixMenuCompteEpargne;
    int choixMenuComptePayant;

    Menu menuPrincipal("menuPrincipal.txt");
    Menu menuCompteEpargne("menuCompteEpargne.txt");
    Menu menuCompteDepot("menuCompteDepot.txt");
    Menu menuComptePayant("menuComptePayant.txt");

    Compte unCompte;
    CompteEpargne unCompteEpargne(0);
    ComptePayant unComptePayant(0);
    do
    {

        choixMenuPrincipal = menuPrincipal.Afficher();
        switch (choixMenuPrincipal)
        {

        case 1:
            choixMenuCompteDepot = menuCompteDepot.Afficher();

            switch (choixMenuCompteDepot)
            {
            case 1:
                unCompte.ConsulterSolde();
                menuCompteDepot.AttendreAppuiTouche();
                break;
            case 2:
                float valDepot;
                cout << "Entrer la valeur du depot" << endl;
                cin >> valDepot;
                unCompte.Deposer(valDepot);
                break;
            case 3:
                float valRetrait;
                cout << "Entrer la valeur du retrait" << endl;
                cin >> valRetrait;
                unCompte.Retirer(valRetrait);
                break;
            }

            break;
        case 2:
            choixMenuCompteEpargne = menuCompteEpargne.Afficher();
            switch (choixMenuCompteEpargne)
            {
            case 1:
                unCompteEpargne.ConsulterSolde();
                menuCompteEpargne.AttendreAppuiTouche();
                break;
            case 2:
                float valDepot;
                cout << "Entrer la valeur du depot" << endl;
                cin >> valDepot;
                unCompteEpargne.Deposer(valDepot);
                menuCompteEpargne.AttendreAppuiTouche();
                break;
            case 3:
                float valRetrait;
                cout << "Entrer la valeur du retrait" << endl;
                cin >> valRetrait;
                unCompteEpargne.Retirer(valRetrait);
                break;
            case 4:
                unCompteEpargne.CalculerInterets();
                break;
            }
            break;

        case 3:
            choixMenuComptePayant = menuComptePayant.Afficher();

            switch (choixMenuComptePayant)
            {
            case 1:
                unComptePayant.ConsulterSolde();
                menuComptePayant.AttendreAppuiTouche();
                break;
            case 2:
                float valDepot;
                cout << "Entrer la valeur du depot" << endl;
                cin >> valDepot;
                unComptePayant.Deposer(valDepot);
                break;
            case 3:
                float valRetrait;
                cout << "Entrer la valeur du retrait" << endl;
                cin >> valRetrait;
                unComptePayant.Retirer(valRetrait);
                break;
            }
            break;

        }
    }while(choixMenuPrincipal != 4);


    return 0;
}
