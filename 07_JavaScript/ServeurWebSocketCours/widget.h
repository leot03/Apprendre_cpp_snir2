#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QWebSocket>
#include <QWebSocketServer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButto_quitter_clicked();
    void onQWebSocketServer_newConnection();
    void onQWebSocket_textMessageReceveid(QString msg);
    void onQTimer_timeout();

private:
    Ui::Widget *ui;
    QWebSocketServer *sock;
    QList <QWebSocket> *client;
    QList <QTimer> *majDate;
};
#endif // WIDGET_H
