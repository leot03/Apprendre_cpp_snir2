#include "bdd.h"
#include "ui_bdd.h"
#include <QDebug>
#include <QSqlError>

bdd::bdd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::bdd)
{
    ui->setupUi(this);
}

bdd::~bdd()
{
    delete ui;
}

void bdd::on_pushButton_Leave_clicked()
{
    close();
}


void bdd::on_pushButton_Login_clicked()
{
    bd=QSqlDatabase::addDatabase("QMYSQL");
    bd.setHostName("172.18.58.8");
    bd.setDatabaseName("france2018");
    bd.setUserName("snir");
    bd.setPassword("snir");
    if (!bd.open())
    {
    qDebug()<<bd.lastError().text();
    }
    else
    {
    qDebug()<<"acces bdd ok!";
    }
}


void bdd::on_pushButton_nomDepartement_clicked()
{
    QSqlQuery requetePreparee;
    requetePreparee.prepare("select name from departments where code like :codeDept; ");
    QString nomDepartement;

    requetePreparee.bindValue(":codeDept", ui -> lineEdit_codeDepartement -> text());
    if (!requetePreparee.exec())
    {
    qDebug()<<requetePreparee.lastError().text();
    }
    while(requetePreparee.next())
    {
    nomDepartement=requetePreparee.value("name").toString();
    ui -> label_nomDepartement -> setText(nomDepartement);
    }

}

