#include "clavier.h"
#include "ui_clavier.h"
#include <QMessageBox>

Clavier::Clavier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Clavier)
    , leDetecteur(nullptr)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,&QPushButton::clicked, this, &Clavier::TraiterChiffre);
    connect(ui->pushButton_1,&QPushButton::clicked, this, &Clavier::TraiterChiffre);
//    connect(ui->pushButton_2,&QPushButton::clicked, this, &Clavier::TraiterChiffre);
//    connect(ui->pushButton_3,&QPushButton::clicked, this, &Clavier::TraiterChiffre);
    connect(ui->pushButton_4,&QPushButton::clicked, this, &Clavier::TraiterChiffre);
    connect(ui->pushButton_5,&QPushButton::clicked, this, &Clavier::TraiterChiffre);
    connect(ui->pushButton_6,&QPushButton::clicked, this, &Clavier::TraiterChiffre);
    connect(ui->pushButton_7,&QPushButton::clicked, this, &Clavier::TraiterChiffre);
    connect(ui->pushButton_8,&QPushButton::clicked, this, &Clavier::TraiterChiffre);
    connect(ui->pushButton_9,&QPushButton::clicked, this, &Clavier::TraiterChiffre);

    connect(&timerLed, &QTimer::timeout, this, &Clavier::onTimerLed_timeout);
}

Clavier::~Clavier()
{
    delete ui;
}


void Clavier::TraiterChiffre()
{
    QPushButton *pBouton = static_cast<QPushButton *>(sender());
    QString texteBouton = pBouton -> text();
    QMessageBox messageMarche;
    messageMarche.setText("Le bouton " + texteBouton + " a été pressé");
    messageMarche.exec();
}

void Clavier::on_pushButton_Marche_clicked()
{
//    QString texteBouton = ui -> pushButton_Marche -> text();
//    QMessageBox messageMarche;
//    messageMarche.setText("Le bouton " + texteBouton + " a été pressé");
//    messageMarche.exec();
//    if(ui -> checkBox_LedRouge -> checkState() == Qt::Unchecked)
//        ui -> checkBox_LedRouge -> setCheckState(Qt::Checked);
    timerLed.start(500);


}


void Clavier::on_pushButton_Arret_clicked()
{
//    QString texteBouton = ui -> pushButton_Arret -> text();
//    QMessageBox messageArret;
//    messageArret.setText("Le bouton " + texteBouton + " a été pressé");
//    messageArret.exec();

//    if(ui -> checkBox_LedRouge -> checkState() == Qt::Checked)
//        ui -> checkBox_LedRouge -> setCheckState(Qt::Unchecked);
    timerLed.stop();
}

void Clavier::onTimerLed_timeout()
{
    if(ui -> checkBox_LedRouge -> checkState() == Qt::Checked)
        ui -> checkBox_LedRouge -> setCheckState(Qt::Unchecked);
    else
        ui -> checkBox_LedRouge -> setCheckState(Qt::Checked);
}


void Clavier::on_pushButton_2_clicked()
{
    if(leDetecteur == nullptr)
        leDetecteur = new Detecteur;
    leDetecteur -> show();
}


void Clavier::on_pushButton_3_clicked()
{
    if(leDetecteur != nullptr) {
        leDetecteur -> hide();
        delete leDetecteur;
        leDetecteur = nullptr;
    }
;}

