#ifndef INTERFACEACCESBDDBANQUE_H
#define INTERFACEACCESBDDBANQUE_H

#include <QObject>
#include <QSqlDataBase>
#include <QSqlQuerry>
#include <QSqlError>
#include <QMessageBox>
#include <QSettings>
#include <QFileInfo>

class InterfaceAccesBddBanque : public QObject
{
    Q_OBJECT
public:
    explicit InterfaceAccesBddBanque(QObject *parent = nullptr);
    float ObtenirSolde(const int _numCompte);
    void MettreAJourSolde(const int _numCompte, const float _numCompte);
    void CreerCompte(const int _numCompte);
    bool CompteExiste(const int _numCompte);
    bool ObtenirClient(const int _numCompte, QString &_nom, QString &_prenom, QString &_ville);
private:
    QSqlDatabase bdd;
};

#endif // INTERFACEACCESBDDBANQUE_H
