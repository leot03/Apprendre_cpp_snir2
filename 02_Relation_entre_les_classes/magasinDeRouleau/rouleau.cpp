/**
  @file rouleau.cpp
  @brief Implémentation de la classe rouleau
  @version 1.1
  @author Philippe CRUCHET
  @date 13/10/2022
  */

#include "rouleau.h"

/**
 * @brief Rouleau::Rouleau
 * @param _reference Référence du rouleau
 * @param _diametre Diamètre du rouleau
 */

Rouleau::Rouleau() {}

Rouleau::Rouleau(const string _reference, const int _diametre):
    reference(_reference),
    diametre(_diametre)
{

}

/**
 * @brief Rouleau::AffecterAlveole
 * @param _rangee
 * @param _colonne
 * @details Indique la rangée et la Colonne ou est stocké le rouleau
 */
void Rouleau::AffecterAlveole(const int _rangee, const int _colonne)
{
    rangee = _rangee;
    colonne = _colonne;
}

/**
 * @brief Rouleau::ObtenirLocalisation
 * @param _rangee
 * @param _colonne
 * @details Permet de savoir ou est stocké le rouleau dans le magasin
 */
void Rouleau::ObtenirLocalisation(int &_rangee, int &_colonne) const
{
    _rangee = rangee;
    _colonne = colonne;
}

/**
 * @brief Rouleau::operator <
 * @param _aComparer 2ème terme de l'opération
 * @return Vrai si le diamètre du rouleau est plus petit que celui du second terme, Faux sinon
 */
bool Rouleau::operator <(const  Rouleau &_autreRouleau) const
{
    return diametre < _autreRouleau.diametre;
}

/**
 * @brief Rouleau::operator -
 * @param _aSoustraire 2ème terme de l'opération
 * @return résultat de l'opération
 * @details Réalise la différence entre les diamètres des deux rouleaux
 */
int Rouleau::operator -(const Rouleau &_aSoustraire) const
{
    return diametre - _aSoustraire.diametre;
}

/**
 * @brief Rouleau::Visualiser
 * @details visualisation des caractéristisue d'un rouleau
 */
void Rouleau::Visualiser() const
{
    cout << "Rouleau référence : " << reference << " Diamètre : " << diametre << endl;
    cout << "Dans magasin en " << rangee << " - " << colonne <<endl;

}
