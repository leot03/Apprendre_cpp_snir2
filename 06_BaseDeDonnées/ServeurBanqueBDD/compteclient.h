#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H

#include "interfaceaccesbddbanque.h"
#include <QTcpSocket>

class CompteClient : public QTcpSocket
{
public:
    CompteClient(QObject *parent=nullptr);
    bool Retirer(const float montant);
    void Deposer(const float montant);
    float ObtenirSolde();
    void DefinirNumCompte(const int _numCompte);
    int ObtenirNumCompte();
    void SetAccesBdd(InterfaceAccesBddBanque *accesBdd);

private:
    int numCompte;
    float solde;
    InterfaceAccesBddBanque *accesBdd;


};
#endif // COMPTECLIENT_H
