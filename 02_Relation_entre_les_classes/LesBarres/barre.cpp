#include "barre.h"
#include <iostream>

using namespace std;

Barre::Barre(const string _reference, const int _longueur, const float _densite, const string _nomAlliage):
    reference(_reference),
    longueur(_longueur),
    densite(_densite),
    nomAlliage(_nomAlliage)
{
    cout << "Constructeur de la Classe Barre"  << endl;
}

Barre::~Barre()
{
    cout << "Destructeur de la Classe barre" << endl;
}

void Barre::AfficherCaracteristiques()
{
    cout << "La Référence de la barre est : " << reference << endl;
    cout << "La Longueur de la barre est : " << longueur << endl;
    cout << "La Densité de la barre est de : " << densite << endl;
    cout << "Le nom d'Alliage de la barre est : " << nomAlliage << endl;
}
