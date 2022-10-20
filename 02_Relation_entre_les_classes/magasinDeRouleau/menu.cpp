#include "menu.h"

using namespace std;

Menu::Menu(const string &_nom):
    nom(_nom),
    longueurMax(0),
    nbOptions(0),
    options(nullptr) {
   // this->nom = _nom;
   // this->longueurMax = 0;
   // this->nbOptions = 0;
   // this->options = nullptr;
    ifstream fichierMenu(this->nom);
    if (fichierMenu.fail()){
            string message = " file not found !!";
            message = this->nom + message;
            Exception excep(404,message);
            throw (excep);
    } else {
       this->nbOptions = static_cast<int>(count(istreambuf_iterator<char>(fichierMenu),
                                          istreambuf_iterator<char>(),
                                          '\n'));
       fichierMenu.seekg(0,ios::beg);
       int longueur;
       string item;
       // allocation dynamique du tableaux création du tableau
       this->options = new string[this->nbOptions];
       // Lecture et chargement des items
       for( int i =0; i < this->nbOptions ; i++){
           getline(fichierMenu, item);
           longueur = static_cast<int>(item.length());
           if (longueur > longueurMax)
               longueurMax = longueur;
           if (longueur > 0)
                this->options[i] = item;
           else{
               this->nbOptions--;
               i--;
           }
       }
    }
}

/**
 * @brief Menu::~Menu (Destructeur)
 */

Menu::~Menu() {
    if (this->options != nullptr)
        delete  [] options;
}

/**
 * @brief Menu::Afficher
 *        Méthode pour créer la vue utilisateur du menu.
 *        Cette méthode attend la saisie du choix de l'utilisateur
 * @return Le choix de l'utilisateur sous la forme d'une valeur entière
 */

int Menu::Afficher() {
    int choix;
    // si le fichier ne peut pas être ouvert alors pas d'affichage;
    if (nbOptions == 0)
        choix = -1;
    else{
       cout << setfill('-');
       // dessine la première ligne du menu
       cout << "+-" << setw(4) << "-+-" << setw(longueurMax+2) << "-+" << endl;
       cout << setfill(' ');
        for( int i =0; i < nbOptions; i++){
            cout << "| " << i+1 << " | " << left << setw(longueurMax) << options[i]  << " |" << endl;
        }
        // dessine la dernière ligne
        cout << setfill('-') << right;
        cout << "+-" << setw(4) << "-+-" << setw(longueurMax+2) << "-+" << endl;
        cout << setfill(' ');

        do{
            cout << "Votre choix svp : " << endl;
            if(!(cin>>choix))
             {
                 cin. clear();
                 cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                 choix = -1;
             }

        }while (  choix > (nbOptions));

    }

    return choix;
}

/**
 * @brief Menu::AttendreAppuiTouche
 * @abstract Méthode statique pour attendre l'appui sur une touche du clavier.
 *           Le buffer d'entrée est vidé, l'écran est effacé après l'action sur le clavier
 */

void Menu::AttendreAppuiTouche() {
    string uneChaine;
    cout << endl << "Appuyer sur la touche Entrée pour continuer...";
    getline(cin,uneChaine);
    // Vidage du tampon d'entrée
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else

#endif
}

Exception::Exception(int _code, std::string _message):
    code(_code),
    message(_message)
{}

int Exception::ObtenirCodeErreur() const {
    return code;
}

std::string Exception::ObtenirMessage() const {
    return message;
}
