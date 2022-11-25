#include "detecteur.h"
#include "ui_detecteur.h"
#include <QMessageBox>

Detecteur::Detecteur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Detecteur)
{
    ui->setupUi(this);
}

Detecteur::~Detecteur()
{
    delete ui;
}

void Detecteur::on_pushButtonIntrusion_clicked()
{
    QString texteBouton = ui -> pushButtonIntrusion -> text();
    QMessageBox messageArret;

    messageArret.setText("Le bouton " + texteBouton + " a été pressé");
    messageArret.exec();

    close();

}

