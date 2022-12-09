#ifndef SERVEURBANQUE_H
#define SERVEURBANQUE_H


#include <QTcpServer>
#include "compteclient.h"
#include "interfaceaccesbddbanque.h"

class ServeurBanque : public QTcpServer
{

public:
    ServeurBanque(QObject *parent=nullptr);
    void Lancer();
    void Arreter();
    void EnvoyerMessage( QString _message, CompteClient *_client);
private slots:
    void onServeurBanque_newConnection();
    void onCompteClient_readyRead();
    void onCompteClient_disconnected();
private:
    QList <CompteClient *> listeComptesClients;
    InterfaceAccesBddBanque *accesBdd;

};

#endif // SERVEURBANQUE_H;
