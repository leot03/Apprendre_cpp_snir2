#include "banque.h"
#include "ui_banque.h"
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>


Banque::Banque(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Banque)
{
    ui->setupUi(this);
    ui -> groupBox_infosBanque -> setEnabled(false);
    ui -> pushButton_deconnexionBDD -> setEnabled(false);
    QHeaderView *headers = ui->tableWidget_infoBanque->horizontalHeader();
    headers->setSectionResizeMode(QHeaderView::Stretch);
}

Banque::~Banque()
{
    delete ui;
}
void Banque::on_pushButton_quitter_clicked()
{
    bd.close();
    qDebug()<<"disconnect bdd";
    close();
    qDebug()<<"close bank";
}


void Banque::on_pushButton_connexionBDD_clicked()
{
    QMessageBox message;

    bd=QSqlDatabase::addDatabase("QMYSQL");
    bd.setHostName(ui -> lineEdit_adresseIP -> text());
    bd.setDatabaseName(ui -> lineEdit_nomBDD -> text());
    bd.setUserName(ui -> lineEdit_login -> text());
    bd.setPassword(ui -> lineEdit_motDePasse -> text());
    if (!bd.open())
    {
    qDebug()<<bd.lastError().text();
    message.setText("Connexion échouée");
    message.exec();
    }
    else
    {
    qDebug()<<"connect bdd";
    message.setText("Connecté avec succès à la base de données");
    message.exec();
    ui -> groupBox_infosBanque -> setEnabled(true);
    ui -> pushButton_deconnexionBDD -> setEnabled(true);
    ui -> pushButton_connexionBDD -> setEnabled(false);
    }

}


void Banque::on_pushButton_afficherInfosComptes_clicked()
{
//    QSqlQuery requete ("select nom, prenom, solde, idCompte from comptes;");
//    if (!requete.exec()) {
//        qDebug()<<requete.lastError().text();
//    }
//    int nbLignes = requete.size();
//    qDebug()<<"Nombre de comptes : " << nbLignes;
//    QString nom, prenom, compte, solde;
//    while (requete.next()) {
//        nom = requete.value("nom").toString();
//        prenom = requete.value("prenom").toString();
//        solde = requete.value("solde").toString();
//        compte = requete.value("idCompte").toString();
//        qDebug()<<nom<<prenom<<solde<<compte;
//        ui->textEdit_infoBanque->append(nom);
//        ui->textEdit_infoBanque->append(prenom);
//        ui->textEdit_infoBanque->append(solde);
//        ui->textEdit_infoBanque->append(compte);
//    }

    ////////////////////////////////////////////////////////////
    // ajouter une ligne au tableau
    int ligne=0; // numéro de la ligne
    int col=0; // numéro de la colonne

    QSqlQuery requete ("select nom, prenom, solde, idCompte from comptes;");
    if (!requete.exec()) {
        qDebug()<<requete.lastError().text();
    }

    int nbLignes = requete.size();
    qDebug()<<"Nombre de comptes : " << nbLignes;
    QString nom, prenom, compte, solde;
    while (requete.next()) {
        ui->tableWidget_infoBanque->insertRow(ui->tableWidget_infoBanque->rowCount());

        nom = requete.value("nom").toString();
        prenom = requete.value("prenom").toString();
        solde = requete.value("solde").toString();
        compte = requete.value("idCompte").toString();

        qDebug()<<nom<<prenom<<solde<<compte;

        QTableWidgetItem *idCompteItem = new QTableWidgetItem(compte);
        ui->tableWidget_infoBanque->setItem(ligne, col++, idCompteItem);

        QTableWidgetItem *nomItem = new QTableWidgetItem(nom);
        ui->tableWidget_infoBanque->setItem(ligne, col++, nomItem);

        QTableWidgetItem *prenomItem = new QTableWidgetItem(prenom);
        ui->tableWidget_infoBanque->setItem(ligne, col++, prenomItem);

        QTableWidgetItem *soldeItem = new QTableWidgetItem(solde);
        ui->tableWidget_infoBanque->setItem(ligne, col++, soldeItem);
    }
}

void Banque::on_pushButton_ajout_clicked()
{
    QMessageBox message;
    message.setText("rien");
    message.exec();
}

void Banque::on_pushButton_deconnexionBDD_clicked()
{
    QMessageBox message;
    bd.close();
    qDebug()<<"disconnect bdd";
    message.setText("Déconnexion avec succès de la base de données");
    message.exec();
    ui -> pushButton_deconnexionBDD -> setEnabled(false);
    ui -> pushButton_connexionBDD -> setEnabled(true);
}

