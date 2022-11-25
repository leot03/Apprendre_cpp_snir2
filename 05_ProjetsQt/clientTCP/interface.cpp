#include "interface.h"
#include "ui_interface.h"
#include <QDebug>

interface::interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::interface)
{
    ui->setupUi(this);
    //désactiver le texte bouton envoyer
    ui->BoutonEnvoyer->setDisabled(true);
    //desactiver le texte a envoyer
    ui->TexteAEnv->setDisabled(true);
    //association signal/slot pour sockVersServeur
    connect(&sockVersServeur,
            &QTcpSocket::connected,
            this,
            &interface::onQTcpSocketConnected);
    connect(&sockVersServeur,
            &QTcpSocket::connected,
            this,
            &interface::onQTcpSocketDisconnected);
    connect(&sockVersServeur,
            &QTcpSocket::readyRead,
            this,
            &interface::onQTcpSocketReadyRead);
    connect(&sockVersServeur,
            &QTcpSocket::stateChanged,
            this,
            &interface::onQTcpSocketStateChanged);



}

interface::~interface()
{
    delete ui;
}


void interface::on_Connexion_clicked()
{
sockVersServeur.connectToHost(ui->lineEditIPServeur->text(),

                              ui->spinBoxPort->value());
}


void interface::on_BoutonEnvoyer_clicked()
{
sockVersServeur.write(
            ui->TexteAEnv->text().toUtf8()
            );
}

void interface::onQTcpSocketConnected()
{
    qDebug()<<"connected";

    ui->BoutonEnvoyer->setDisabled(false);
        ui->TexteAEnv->setDisabled(false);

        ui->Connexion->setDisabled(true);
        ui->spinBoxPort->setDisabled(true);
        ui->lineEditIPServeur->setDisabled(true);

}

void interface::onQTcpSocketDisconnected()
{
    qDebug()<<"disconnected";
}

void interface::onQTcpSocketReadyRead()
{
    QByteArray reponse;
    reponse=sockVersServeur.readAll();
    ui->TexteEtEtat->append(reponse);
}

void interface::onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    switch(socketState)
    {
    case QAbstractSocket::UnconnectedState:
           ui->TexteEtEtat->append("The socket is not connected.");
        break;
    case QAbstractSocket::HostLookupState:
        ui->TexteEtEtat->append("The socket is performing a host name lookup.");
        break;
    case QAbstractSocket::ConnectingState:
    ui->TexteEtEtat->append("The socket has started establishing a connection.");
    break;

   case QAbstractSocket::ConnectedState:
    ui->TexteEtEtat->append("A connection is established.");
        break;
    case QAbstractSocket::BoundState:
        ui->TexteEtEtat->append("The socket is bound to an address and port.");
        break;
    case QAbstractSocket::ClosingState:
        ui->TexteEtEtat->append("The socket is about to close (data may still be waiting to be written");
        break;
    case QAbstractSocket::ListeningState:
        ui->TexteEtEtat->append("For internal use only.");
        break;
    }
}

void interface::onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError)
{
ui->TexteEtEtat->append(sockVersServeur.errorString());
}







