#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // creation websocketserver
    sock = new QWebSocketServer (
                "mon serveur web sockett",
                QWebSocketServer::NonSecureMode);
    connect(sock,
            &QWebSocketServer::newConnection,
            this,
            &Widget::onQWebSocketServer_newConnection);

    if(!sock-> listen(QHostAddress::Any,8888)) {
        qDebug() << sock -> errorString();
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButto_quitter_clicked()
{
    close();
}

void Widget::onQWebSocketServer_newConnection()
{
    // Nouvelle connexion de client
    client=sock->nextPendingConnection();
    // association event de reception avec slot correspondant
    connect(client,
            &QWebSocket::textMessageReceived,
            this,
            &Widget::onQWebSocket_textMessageReceveid);
    listeClients.append(client);
    QTimer *majDate = new QTimer();
    connect(MajDate,
            &QTimer::timeout,
            this,
            &Widget::onQTimer_timeout);
    listeMajDates.append(majDate);
}

void Widget::onQWebSocket_textMessageReceveid(QString msg)
{
    QWebSocket *client = qobject_cast<QWebSocket *>(sender());
    // si on recoit la chaine 'date" lancer le timer
    if(msg=="date") {
        listelisteMajDates.at(indexTimer)->start(100);
    }
}

void Widget::onQTimer_timeout()
{
    QTimer *timer=qobject_cast<QTimer *>(sender());
    int indexClient = listeMajDates.indexOf(timer);
    // envoyer la date au client
    QString date = QDateTime::currentDateTime().toString();
    client->sendTextMessage(date);
}

