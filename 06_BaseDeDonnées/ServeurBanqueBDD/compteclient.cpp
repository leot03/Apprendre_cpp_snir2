#include "compteclient.h"

CompteClient::CompteClient(QObject *parent)
    : QTcpSocket(parent), numCompte(0), solde(0.0)
{

}

bool CompteClient::Retirer(const float _montant) {
  bool retour = false;
  if (_montant > 0) {
    if (solde >= _montant) {
      solde -= _montant;
      retour = true;
    }
  }
  return retour;
}

void CompteClient::Deposer(const float _montant) {
  if (_montant > 0) {
    solde += _montant;
  }
}

float CompteClient::ObtenirSolde() {
    return solde;
}

void CompteClient::DefinirNumCompte(const int _numCompte) {
  numCompte = _numCompte;
}

int CompteClient::ObtenirNumCompte() {
    return numCompte;
}
