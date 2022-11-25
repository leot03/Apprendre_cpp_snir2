#include "auditserveurmonowidget.h"
#include "ui_auditserveurmonowidget.h"

AuditServeurMonoWidget::AuditServeurMonoWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuditServeurMonoWidget)
{
    ui->setupUi(this);
    socketEcouteServeur = new QTcpServer(this);
    socketEcouteServeur -> setMaxPendingConnections(1);
    connect(socketEcouteServeur, &QTcpServer::newConnection, this, &AuditServeurMonoWidget::onQTcpServer_newConnection);
    connect(socketEcouteServeur, &QTcpServer::acceptError, this, &AuditServeurMonoWidget::onQProcess_readyReadStandardOutput);
}

AuditServeurMonoWidget::~AuditServeurMonoWidget()
{
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
    QTcpSocket *client;
    client = socketEcouteServeur-> nextPendingConnection();
    //récupération de la socket de communication avec le client

    connect(client, &QTcpSocket::connected,this,&::AuditServeurMonoWidget::onQTcpServerConnected);
    connect(client, &QTcpSocket::disconnected,this,&::AuditServeurMonoWidget::onQTcpServerDisconnect);
    connect(client, &QTcpSocket::readyRead,this,&AuditServeurMonoWidget::onQTcpServerReadyRead);
    connect(client, &QTcpSocket::stateChanged,this,&AuditServeurMonoWidget::onQTcpServerStateChanged);
    connect(client, &QTcpSocket::errorOccurred,this,&AuditServeurMonoWidget::onQTcpServerErrorOccured);
    connect(client, &QTcpSocket::hostFound,this,&AuditServeurMonoWidget::onQTcpServerHostFound);
    connect(client, &QTcpSocket::aboutToClose,this,&::AuditServeurMonoWidget::onQTcpServerAboutToClose);
    connect(client, &QTcpSocket::channelReadyRead,this,&::AuditServeurMonoWidget::onQTcpServerReadyRead);
    connect(client, &QTcpSocket::bytesWritten,this,&AuditServeurMonoWidget::onQTcpServerBytesWritten);

    socketDialogueClient.append(client);
    QProcess *process = new QProcess(this);

    connect(process,&QProcess::readyReadStandardOutput, this, &AuditServeurMonoWidget::onQProcess_readyReadStandardOutput);

    listeProcess.append(process);

    QHostAddress adresseClient = client->peerAddress();
    ui -> textEdit -> append("Client : " + adresseClient.toString());
}

void AuditServeurMonoWidget::onQTcpServerConnected()
{
    ui->textEdit->append("Client connecté");
}

void AuditServeurMonoWidget::onQTcpServerDisconnect()
{
    QTcpSocket *client=qobject_cast<QTcpSocket*>(sender());
    int indexClient = socketDialogueClient.indexOf(client);

    listeProcess.removeAt(indexClient);

    disconnect(client, nullptr, this, nullptr);
    socketDialogueClient.removeOne(client);
    client -> deleteLater();
    ui->textEdit->append("Client déconnecté");
}

void AuditServeurMonoWidget::onQTcpServerReadyRead()
{
    QTcpSocket *client=qobject_cast<QTcpSocket*>(sender());
    int indexClient = socketDialogueClient.indexOf(client);
    QProcess *process = listeProcess.at(indexClient);

    QChar commande;
    QString reponse;
    if(client -> bytesAvailable()) {
        QByteArray tampon = client -> readAll();
        commande = tampon.at(0);
        QString message = "Commande recu de : " + client -> peerAddress().toString() + " : ";
        message += commande;
        ui -> textEdit -> append(message);
        switch (commande.toLatin1()) {
        case 'u': reponse = getenv("USER");
            client->write(reponse.toLatin1());
            break;
        case 'a':
            process -> start("uname", QStringList("-p")); // Récuparation de l'architecture
            break;
        case 'c' : reponse = QHostInfo::localHostName();
            client->write(reponse.toLatin1());
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
    QTcpSocket *client=qobject_cast<QTcpSocket*>(sender());
    ui->textEdit->append("CLient :" + client -> errorString());
}

void AuditServeurMonoWidget::onQTcpServerHostFound()
{
    ui -> textEdit -> append("host found");
}

void AuditServeurMonoWidget::onQTcpServerStateChanged(QAbstractSocket::SocketState socketState)
{
    Q_UNUSED(socketState);
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
    QProcess * process = qobject_cast<QProcess *>(sender());
    int indexProcess = listeProcess.indexOf((process));
    QTcpSocket *client = socketDialogueClient.at(indexProcess);

    QString reponse = process->readAllStandardOutput();
    if(!reponse.isEmpty())
        client->write(reponse.toLatin1());
}
