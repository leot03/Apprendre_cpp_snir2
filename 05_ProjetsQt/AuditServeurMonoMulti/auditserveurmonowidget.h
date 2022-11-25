#ifndef AUDITSERVEURMONOWIDGET_H
#define AUDITSERVEURMONOWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QProcess>
#include <QHostInfo>
#include <QtNetwork>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class AuditServeurMonoWidget; }
QT_END_NAMESPACE

class AuditServeurMonoWidget : public QWidget
{
    Q_OBJECT

public:
    AuditServeurMonoWidget(QWidget *parent = nullptr);
    ~AuditServeurMonoWidget();

private slots:

    void on_pushButtonLancementServeur_clicked();
    void onQTcpServer_acceptError(QAbstractSocket::SocketError socketError);
    void onQTcpServer_newConnection();

    void onQTcpServerConnected();
    void onQTcpServerDisconnect();
    void onQTcpServerReadyRead();
    void onQTcpServerErrorOccured(QAbstractSocket::SocketError socketError);
    void onQTcpServerHostFound();
    void onQTcpServerStateChanged(QAbstractSocket::SocketState socketState);
    void onQTcpServerAboutToClose();
    void onQTcpServerBytesWritten(quint64 bytes);

    void onQProcess_readyReadStandardOutput();

private:
    Ui::AuditServeurMonoWidget *ui;
    QTcpServer * socketEcouteServeur;
    QList <QTcpSocket *> socketDialogueClient;
    QList <QProcess *> listeProcess;
};
#endif // AUDITSERVEURMONOWIDGET_H
