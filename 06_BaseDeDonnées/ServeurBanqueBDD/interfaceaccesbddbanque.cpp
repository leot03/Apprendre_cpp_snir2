#include "interfaceaccesbddbanque.h"

InterfaceAccesBddBanque::InterfaceAccesBddBanque()
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

float InterfaceAccesBddBanque::ObtenirSolde(const int _numCompte)
{
    QSqlQuery requete;
    float solde;
    requete.prepare("select solde from comptes where idCompte=:id;");
    requete.bindValue(":id", _numCompte);
    requete.exec();
    if (!requete.exec()) {
        qDebug() << "pb obtenir solde " << requete.lastError();
    }
    requete.next();
    solde = requete.value("solde").toFloat();
    return solde;
}

void InterfaceAccesBddBanque::MettreAJourSolde(const int _numCompte, const float _numCompte)
{

}

void InterfaceAccesBddBanque::CreerCompte(const int _numCompte)
{

}

bool InterfaceAccesBddBanque::CompteExiste(const int _numCompte)
{

}

bool InterfaceAccesBddBanque::ObtenirClient(const int _numCompte, QString &_nom, QString &_prenom, QString &_ville)
{

}
