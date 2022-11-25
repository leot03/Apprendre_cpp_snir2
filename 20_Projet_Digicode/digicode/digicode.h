#ifndef DIGICODE_H
#define DIGICODE_H

#include "porte.h"
#include <QWidget>
#include <QCloseEvent>

#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QProcess>
#include <QHostInfo>
#include <QtNetwork>

#include <QMessageBox>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class digicode; }
QT_END_NAMESPACE

class digicode : public QWidget
{
    Q_OBJECT

public:
    digicode(QWidget *parent = nullptr);
    ~digicode();
    void onQPushButtonClicked();
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_On_clicked();
    void on_pushButton_Ok_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

private:
    Ui::digicode *ui;
    Porte laPorte;
};
#endif // DIGICODE_H
