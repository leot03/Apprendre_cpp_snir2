#include "barre.h"

using namespace std;

Barre::Barre()
{

}

Barre::Barre(const string _reference, const string _nom, const unsigned int _longueur, const double _densite):
    reference(_reference),
    nom(_nom),
    longueur(_longueur),
    densite(_densite)
{
    cout << endl << "Constructeur de la calsse Barre" << endl;
}

Barre::~Barre()
{
    cout << "Deestructeur de la classe Barre" << endl;
}

void Barre::AfficherCaracteristique()
{
    cout << endl;
    cout << "Reference : " << reference << endl;
    cout << "Nom de l'alliage : " << nom << endl;
    cout << "Densité : " << densite << endl;
    cout << "Longueur : " << longueur << endl;
    cout << endl;
}
