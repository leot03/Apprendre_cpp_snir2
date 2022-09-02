#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//int main()
//{
//    float temperature;
//    float humidite;
//    int pression;

//    cout << "Saisir la température, l'humidité et la pression : " ;
//    cin >> temperature >> humidite >> pression ;
//    cout << "la température est : " << temperature << " °" << endl;
//    cout << "le taux d'humidité est : " << humidite << " %" << endl;
//    cout << "la pression est : " << pression << " hPa" << endl ;
//    return 0;
//}

//int main()
//{
//    char phrase[10+1];
//    cout << "Saisir une phrase : " ;
//    cin.getline(phrase, 10);
//    cout << "Votre phrase est :" << phrase << endl;
//    return 0;
//}

//int main()
//{
//    int val = 192;
//    cout << "Affichage par défaut : " << val << endl;
//    cout << "Affichage en hexadécimal : " << hex << val << endl;
//    cout << "Affichage en décimal : " << dec << val << endl;
//    return 0;
//}

//using namespace std;
//int main()
//{
//    string motCle ;
//    // string remplace un tableau de caractères. la taille de la chaîne est dynamique
//    int valeur;
//    ifstream fichier("config.txt");
//    if (!fichier.is_open())
//        cerr << "Erreur lors de l'ouverture du fichier" << endl;
//    else
//    {
//        do
//        {
//            // le fichier contient sur chaque ligne des couples mot clé + valeur
//            fichier >> motCle >> valeur ;
//            if (fichier.good())//Si les valeurs ont bien été lues
//            {
//                cout << motCle << endl;
//                cout << valeur << endl;
//                // traitement des variables motCle et valeur
//            }
//        } while(!fichier.eof());
//    }
//    return 0 ;
//}

int main() {
    string nomDuFichier;
    cout << "Entrer le nom du fichier à lire : ";
    cin >> nomDuFichier;
    //Création du flux en lecture sur le fichier
    ifstream leFichier(nomDuFichier.c_str()); // c_str() transforme string en char*
    if (!leFichier .is_open())
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    else
    {
        string pays;
        int nbOr;
        int nbArgent;
        int nbBronze;

        cout << "+" << setfill('-') << setw(45) << "+" << setfill(' ') << endl;
        // A compléter, affichage de la première ligne du tableau
        do
        {
            //récupération des valeurs
            leFichier >> pays >> nbOr >> nbArgent >> nbBronze;
            if (leFichier.good())//Si les valeurs ont bien été lues
            {
                cout << "| " << setw(19) << left << pays << "| " << setw(5) << right << nbOr << " | " << setw(5) << nbArgent << " | " << setw(5) << nbBronze << " |" << endl;
                // A compléter, affichage de chaque ligne du tableau
            }
        } while (!leFichier.eof());
        // A compléter, affichage de la dernière ligne du tableau.
        cout << "+" << setfill('-') << setw(45) << "+" << setfill(' ') << endl;
    }
    return 0;
}
