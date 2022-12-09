#include "serveurbanque.h"
#include <QMessageBox>
#include <QBuffer>

ServeurBanque::ServeurBanque(QObject *parent):
    QTcpServer(parent)
{
    connect(this,&QTcpServer::newConnection,this,&ServeurBanque::onServeurBanque_newConnection);
}

void ServeurBanque::Lancer()
{
    if (!listen(QHostAddress::Any,8888))
    {
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
    // construction de la trame
    quint16 taille=0;
    QBuffer tampon;
    tampon.open(QIODevice::WriteOnly);
    // association du tampon au flux de sortie
    QDataStream out(&tampon);
    // construction de la trame
    out<<taille<<_message;
    // calcul de la taille de la trame
    taille=(static_cast<quint16>(tampon.size()))-sizeof(taille);
    // placement sur la premiere position du flux pour pouvoir modifier la taille
    tampon.seek(0);
    //modification de la trame avec la taille reel de la trame
    out<<taille;
    // envoi du QByteArray du tampon via la socket
    _client->write(tampon.buffer());
}

void ServeurBanque::onServeurBanque_newConnection()
{
    while(hasPendingConnections())
    {
        CompteClient *client= static_cast<CompteClient *>(nextPendingConnection());
        if(client != nullptr)
        {
            connect(client,&CompteClient::readyRead,this,&ServeurBanque::onCompteClient_readyRead);
            connect(client,&CompteClient::disconnected,this,&ServeurBanque::onCompteClient_disconnected);
            listeComptesClients.append(client);
            EnvoyerMessage("Veuillez donner votre numéro de compte svp",client);
        }
    }
}

void ServeurBanque::onCompteClient_readyRead()
{
    CompteClient *socketVersClient= static_cast<CompteClient *>(sender());
    quint16 taille=0;
    QChar commande;
    int valeur=-1;
    QString message;
    float valeurOperation=0.0;
    bool operationPossible;

    if (socketVersClient->bytesAvailable() >= static_cast<qint64>(sizeof(taille)))
    {
        QDataStream in(socketVersClient);
        in >> taille;
        if (socketVersClient->bytesAvailable() >= (qint64)taille)
        {
            // decomposition de la trame
            in>>commande;

            switch (commande.toLatin1()) {
            case 'N':
                in>>valeur;

                socketVersClient->DefinirNumCompte(valeur);
                // construction du message
                message="Bienvenue sur le compte " + QString::number(valeur);


                EnvoyerMessage(message,socketVersClient);
                break;
            case 'R':
                in>>valeurOperation;
                operationPossible=socketVersClient->Retirer(valeurOperation);
                // construction du message
                if (operationPossible)
                {
                    message="nouveau solde " + QString::number(socketVersClient->ObtenirSolde());
                }
                else
                {
                    message="Solde insuffisant";
                }
                EnvoyerMessage(message,socketVersClient);
                break;
            case 'D':
                in>>valeurOperation;
                if ((valeurOperation+socketVersClient->ObtenirSolde())<=100000)
                {
                    socketVersClient->Deposer(valeurOperation);
                    // construction du message
                    message="nouveau solde " + QString::number(socketVersClient->ObtenirSolde());
                }
                else
                {
                    message="le solde ne peux exeder 100 000";
                }
                EnvoyerMessage(message,socketVersClient);
                break;
            case 'S':
                // construction du message
                message="Solde " + QString::number(socketVersClient->ObtenirSolde());
                EnvoyerMessage(message,socketVersClient);
                break;
            default:
                break;
            }
        }
    }
}

void ServeurBanque::onCompteClient_disconnected()
{
    CompteClient *client= static_cast<CompteClient*>(sender());
    if (client == nullptr)
    {
        QMessageBox msg;
        msg.setText("erreur deconnexion : " + client->errorString());
        msg.exec();
    }
    else
    {
        listeComptesClients.removeOne(client);
        client->deleteLater();
    }
}

