#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QWidget>



QT_BEGIN_NAMESPACE
namespace Ui { class interface; }
QT_END_NAMESPACE

class interface : public QMainWindow
{
    Q_OBJECT

public:
    interface(QWidget *parent = nullptr);
    ~interface();

private slots:
    void on_Connexion_clicked();

    void on_BoutonEnvoyer_clicked();

    void onQTcpSocketConnected();

    void onQTcpSocketDisconnected();
    void onQTcpSocketReadyRead();
    void onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError);


private:
    Ui::interface *ui;
    QTcpSocket sockVersServeur;
};
#endif // INTERFACE_H
