#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>


class CompteClient : public QTcpServer
{
public:
    CompteClient(QWidget *parent = nullptr);
    bool Retirer(const float _montant);
    float Deposer(const float _montant);
    float ObtenirSolde();
    void DefinirNumCompte(const int _numCompte);
    int obtenirNumCompte();
private:
    int numCompte;
    float solde;
};

#endif // COMPTECLIENT_H
