#include "alveoleslibres.h"

using namespace std;

Alveoleslibres::Alveoleslibres(const int _nbRangees, const int _nbColonnes):
    nbRangees(_nbRangees),
    nbColonnes(_nbColonnes)
{
    int taille = nbRangees * nbColonnes;
    reserve(taille);
    for(int numAlveole = 1; numAlveole <= taille; numAlveole++)
        push_back(numAlveole);
}

bool Alveoleslibres::Reserver(int &_rangee, int &_colonne) {
    int numAlveole;
    bool alveoleLibre = false;

    if(!empty()) {
        numAlveole = this -> back();
        this->pop_back();

        _rangee = ((numAlveole-1)/nbColonnes)+1;
        _colonne = ((numAlveole-1)%nbColonnes) +1;

        alveoleLibre = true;
    }
    return alveoleLibre;
}

bool Alveoleslibres::Liberer(const int _rangee, const int _colonne) {
    bool ajoutAlveole = false;
    int numAlveole = (_rangee-1) * nbColonnes + _colonne;

    if(find(begin(), end(), numAlveole) == end())
    {
        push_back(numAlveole);
        ajoutAlveole = true;
    }
    return ajoutAlveole;
}

void Alveoleslibres::Visualiser() {
    vector<int>::iterator it;
    if(!empty()) {
        for(it=begin(); it!=end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    } else {
        cout << "Tous les emplacements sont réservés" << endl;
    }
}
