#include "auditserveurmonowidget.h"
#include "ui_auditserveurmonowidget.h"

AuditServeurMonoWidget::AuditServeurMonoWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuditServeurMonoWidget)
    , socketDialogueClient(nullptr)
{
    ui->setupUi(this);
    socketEcouteServeur = new QTcpServer(this);
    socketEcouteServeur -> setMaxPendingConnections(1);
    connect(socketEcouteServeur, &QTcpServer::newConnection, this, &AuditServeurMonoWidget::onQTcpServer_newConnection);

    process = new QProcess(this);
    connect(process,&QProcess::readyReadStandardOutput, this, &AuditServeurMonoWidget::onQProcess_readyReadStandardOutput);
}

AuditServeurMonoWidget::~AuditServeurMonoWidget()
{
    if(socketDialogueClient != nullptr) {
        socketDialogueClient -> close();
        delete socketDialogueClient;
    }
    delete socketEcouteServeur;
    delete ui;
}

void AuditServeurMonoWidget::on_pushButtonLancementServeur_clicked() {
  if (!socketEcouteServeur->listen(QHostAddress::Any, ui->spinBoxPort->value())) {
    QString message = "Impossible de démarrer le serveur " + socketEcouteServeur->errorString();
    ui->textEdit->append(message);
  } else {
    QList<QHostAddress> listeAdresses = QNetworkInterface::allAddresses();
    QList<QHostAddress>::iterator it;
    for (it = listeAdresses.begin(); it != listeAdresses.end(); it++) {
      if (it->toIPv4Address())
        ui->textEdit->append("Adresse serveur : " + it->toString());
    }
    ui->textEdit->append("N° du port : " + QString::number(socketEcouteServeur->serverPort()));
    ui->pushButtonLancementServeur->setEnabled(false);
    ui->spinBoxPort->setEnabled(false);
  }
}

void AuditServeurMonoWidget::onQTcpServer_acceptError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    ui->textEdit->append("Serveur : " + socketEcouteServeur->errorString());
}

void AuditServeurMonoWidget::onQTcpServer_newConnection()
{
    if (socketDialogueClient != nullptr) {
            socketDialogueClient->close();
    }
        ui->textEdit->append("nouvelle connexion");
        //récupération de la socket de communication avec le client
        socketDialogueClient= socketEcouteServeur->nextPendingConnection();

        connect(socketDialogueClient, &QTcpSocket::connected,this,&::AuditServeurMonoWidget::onQTcpServerConnected);
        connect(socketDialogueClient, &QTcpSocket::disconnected,this,&::AuditServeurMonoWidget::onQTcpServerDisconnect);
        connect(socketDialogueClient, &QTcpSocket::readyRead,this,&AuditServeurMonoWidget::onQTcpServerReadyRead);
        connect(socketDialogueClient, &QTcpSocket::stateChanged,this,&AuditServeurMonoWidget::onQTcpServerStateChanged);
        connect(socketDialogueClient, &QTcpSocket::errorOccurred,this,&AuditServeurMonoWidget::onQTcpServerErrorOccured);
        connect(socketDialogueClient, &QTcpSocket::hostFound,this,&AuditServeurMonoWidget::onQTcpServerHostFound);
        connect(socketDialogueClient, &QTcpSocket::aboutToClose,this,&::AuditServeurMonoWidget::onQTcpServerAboutToClose);
        connect(socketDialogueClient, &QTcpSocket::channelReadyRead,this,&::AuditServeurMonoWidget::onQTcpServerReadyRead);
        connect(socketDialogueClient, &QTcpSocket::bytesWritten,this,&AuditServeurMonoWidget::onQTcpServerBytesWritten);

        QHostAddress adresseClient = socketDialogueClient->peerAddress();
        ui -> textEdit -> append("Client : " + adresseClient.toString());
}

void AuditServeurMonoWidget::onQTcpServerConnected()
{
    ui->textEdit->append("Client connecté");
}

void AuditServeurMonoWidget::onQTcpServerDisconnect()
{
    disconnect(socketDialogueClient, nullptr, this, nullptr);
    socketDialogueClient->deleteLater();
    socketDialogueClient = nullptr;
    ui->textEdit->append("Client déconnecté");
}

void AuditServeurMonoWidget::onQTcpServerReadyRead()
{
    QChar commande;
    QString reponse;
    if(socketDialogueClient -> bytesAvailable()) {
        QByteArray tampon = socketDialogueClient -> readAll();
        commande = tampon.at(0);
        QString message = "Commande recu de : " + socketDialogueClient -> peerAddress().toString() + " : ";
        message += commande;
        ui -> textEdit -> append(message);
        switch (commande.toLatin1()) {
        case 'u': reponse = getenv("USER");
            socketDialogueClient->write(reponse.toLatin1());
            break;
        case 'a':
            process -> start("uname", QStringList("-p")); // Récuparation de l'architecture
            break;
        case 'c' : reponse = QHostInfo::localHostName();
            socketDialogueClient->write(reponse.toLatin1());
            break;
        case 'o':
            process-> start("uname"); // récupération de l'os
            break;
        }
    }
}

void AuditServeurMonoWidget::onQTcpServerErrorOccured(QAbstractSocket::SocketError socketError)
{
Q_UNUSED(socketError);
    ui->textEdit->append("CLient :" + socketDialogueClient -> errorString());
}

void AuditServeurMonoWidget::onQTcpServerHostFound()
{
    ui -> textEdit -> append("host found");
}

void AuditServeurMonoWidget::onQTcpServerStateChanged(QAbstractSocket::SocketState socketState)
{
    switch (socketState) {
    case QAbstractSocket::UnconnectedState : ui->textEdit->append("text"); break;
    case QAbstractSocket::HostLookupState : ui->textEdit->append("text");break;
    case QAbstractSocket::ConnectingState : ui->textEdit->append("text");break;
    case QAbstractSocket::ConnectedState : ui ->textEdit->append("text");break;
    case QAbstractSocket::BoundState : ui-> textEdit->append("text");break;
    case QAbstractSocket::ClosingState : ui-> textEdit->append("text");break;
    case QAbstractSocket::ListeningState : ui-> textEdit->append("text");break;
    }
}

void AuditServeurMonoWidget::onQTcpServerAboutToClose()
{
    ui -> textEdit -> append("About to close");
}

void AuditServeurMonoWidget::onQTcpServerBytesWritten(quint64 bytes)
{
    ui->textEdit->append(QString::number(bytes) + "bytes written");
}

void AuditServeurMonoWidget::onQProcess_readyReadStandardOutput()
{
    QString reponse = process->readAllStandardOutput();
    if(!reponse.isEmpty())
        socketDialogueClient->write(reponse.toLatin1());
}
