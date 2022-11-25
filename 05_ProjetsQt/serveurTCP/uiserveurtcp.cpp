#include "uiserveurtcp.h"
#include "ui_uiserveurtcp.h"

UiServeurTcp::UiServeurTcp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UiServeurTcp)
{
    ui->setupUi(this);

    connect(&sockServ, &QTcpServer::newConnection, this, &UiServeurTcp::onQTcpServerNewConnection);

    connect(&sockServ, &QTcpServer::acceptError, this, &UiServeurTcp::onQTcpServerAcceptError);
}

UiServeurTcp::~UiServeurTcp()
{
    delete ui;
}


void UiServeurTcp::on_pushButton_2_clicked()
{
    close();
}


void UiServeurTcp::on_pushButton_clicked()
{
    if (sockServ.listen(QHostAddress::Any, ui -> spinBoxPort -> value())) {
                           ui -> textEditMessage -> append("Lancement OK");
                       } else {
        ui -> textEditMessage -> append("Lancement échoué");
    }
}

void UiServeurTcp::onQTcpServerAcceptError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    ui -> textEditMessage -> append(sockServ.errorString());
}

void UiServeurTcp::onQTcpServerNewConnection()
{

    ui -> textEditMessage -> append("nouvelle connexion");
    // Récupération de la socket de comma evc le client
    sockClient=sockServ.nextPendingConnection();

}

void UiServeurTcp::onQTcpSocketConnected()
{

}

void UiServeurTcp::onQTcpSocketDisconnected()
{
    ui -> textEditMessage -> append("Déconnexion client");
    // retirer le client de la liste des clients
    QTcpSocket *sockClient;
    sockClient = qobject_cast<QTcpSocket*>(sender());
    // retirer les genstions d'events de la socket
    disconnect(sockClient, nullptr, this, nullptr);
    // Suppression de la liste
    listeSockClient.removeOne(sockClient);
    // destruction de l'objet SockClient
    sockClient -> deleteLater();
}

void UiServeurTcp::onQTcpSocketReadyRead()
{
    QByteArray data;
    QByteArray reponse;
    ui -> textEditMessage -> append("dans ReadyRead");
    // reception message client
    sockClient = qobject_cast<QTcpSocket*>(sender());
    data=sockClient -> readAll();
    ui -> textEditMessage -> append(sockClient -> peerAddress().toString() + " : " + data);
    // envoyer la réponse
    reponse = "Message reçu : " + data;
    sockClient -> write(reponse);
}
