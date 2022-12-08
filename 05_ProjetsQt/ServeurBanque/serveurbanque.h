#ifndef SERVEURBANQUE_H
#define SERVEURBANQUE_H

#include "compteclient.h"
#include <QTcpServer>

class ServeurBanque : public QTcpServer
{
public:
    ServeurBanque(QObject *parent = nullptr);
    void Lancer();
    void Arreter();
    void EnvoyerMessage(QString _message, CompteClient *_client);
private slots:
    void onServeurBanque_newConnection();
    void onCompteClient_readyRead();
    void onCompteClient_disconnected();
private:
    QList <CompteClient *> listeComptesClients;
};

#endif // SERVEURBANQUE_H
