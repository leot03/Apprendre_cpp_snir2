#include "serveurbanque.h"
#include <QMessageBox>
#include <QBuffer>

ServeurBanque::ServeurBanque(QObject *parent):
    QTcpServer(parent)
{
    connect(this, &QTcpServer::newConnection,this,&ServeurBanque::onServeurBanque_newConnection);
}

void ServeurBanque::Lancer()
{
    if (!listen(QHostAddress::Any,8888)) {
        QMessageBox msgBox;
        msgBox.setText("erreur listen sur le port 8888 : " + errorString());
        msgBox.exec();
        close();
    }
}

void ServeurBanque::Arreter()
{
    close();
}

void ServeurBanque::EnvoyerMessage(QString _message, CompteClient *_client)
{
    // Constructuon de la trame
    quint16 taille = 0;
    QBuffer tampon;
    tampon.open(QIODevice::WriteOnly);
    // association du tampon au flux de sortie
    QDataStream out (&tampon);
    // construction de la trame
    out << taille << _message;
    // calcuyl de la taille de la trame
    taille = (static_cast<quint16>(tampon.size()))-sizeof(taille);
// placement sur la premiere position de
    tampon.seek(0);

    out << taille;

    _client-> write(tampon.buffer());
}

void ServeurBanque::onServeurBanque_newConnection()
{
    while(hasPendingConnections()) {
        CompteClient *client = static_cast<CompteClient *>(nextPendingConnection());
                if {
                connect(client, &CompteClient::readyRead, this, &ServeurBanque);
                connect(client, &CompteClient::disconnected, this, &ServeurBanque);
                listeComptesClients.append(client);
                EnvoyerMessage("Veuillez donner votre n° d ecompte svp");
    }
    }
}

void ServeurBanque::onCompteClient_readyRead()
{

}

void ServeurBanque::onCompteClient_disconnected()
{

}
