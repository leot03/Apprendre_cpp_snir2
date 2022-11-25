#ifndef UISERVEURTCP_H
#define UISERVEURTCP_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class UiServeurTcp; }
QT_END_NAMESPACE

class UiServeurTcp : public QWidget
{
    Q_OBJECT

public:
    UiServeurTcp(QWidget *parent = nullptr);
    ~UiServeurTcp();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void onQTcpServerAcceptError(QAbstractSocket::SocketError socketError);
    void onQTcpServerNewConnection();

    void onQTcpSocketConnected();
    void onQTcpSocketDisconnected();
    void onQTcpSocketReadyRead();
    void onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError);

private:
    Ui::UiServeurTcp *ui;
    QTcpServer sockServ;
    QList <QTcpSocket *>listeSockClient;
};
#endif // UISERVEURTCP_H
