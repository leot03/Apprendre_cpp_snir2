#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <QObject>
#include <QList>
#include <QPointF>
#include <QDate>
#include "constante.h"
#include "pointdecourbe.h"


typedef struct{
    QString modele;
    QString date;
    QString numeroDeSerie;
    double capacite;
    double sensibilite;
}typeJauge;

typedef struct{
    double tensionPleineEchelle;
    double calibrage;
}typeConditionneur;

typedef struct{
    double coefficient;
    double ordonnee;
}typeGain;

typedef struct{
    double coefficient;
    double ordonnee;
}typeDephasage;

typedef struct{
    typeGain gain;
    typeDephasage dephasage;
}typeFiltre;

typedef struct{
    QString id;
    typeJauge jauge;
    typeConditionneur conditionneur;
    typeFiltre filtre;
}typePalier;

class Experience : public QObject
{
    Q_OBJECT
public:
    explicit Experience(QObject *parent = nullptr);
    void LireFichierIni();
    void EnregistreFichierIni(const typePalier _paliers[]);
    typePalier *ObtenirCarateristiquesPaliers();

    void LireMesuresBrutes(QString &_nomFichier);
    void InitiliserCourbes();
    QList<QPointF> *ObtenirCourbeA();
    QList<QPointF> *ObtenirCourbeO();
    void ObtenirTypeAffichage(bool &_newton, bool &_pointCodeur);
    QPointF RechercherEffortMax(QChar courbe='A');
    double RechercherEffortAzero(QChar courbe='A');
    double RechercherEffortAquatreVingtDix(QChar courbe='A');
    qint16 ObtenirVitesse();

    QString ObtenirEtablissement() const;
    void ModifierEtablissement(const QString &value);
    QString ObtenirNom() const;
    void ModifierNom(const QString &value);
    QString ObtenirPrenom() const;
    void ModifierPrenom(const QString &value);
    QString ObtenirClasse() const;
    void ModifierClasse(const QString &value);
    QString ObtenirCommentaire() const;
    void ModifierCommentaire(const QString &value);
    QString ObtenirDate() const;
    void ModifierDate(const QDate &value);
    void ValiderConfig(bool _etat);

signals:

private:

    quint16 vitesseMaxi;            /// vitesse maximale pour une consigne de 100% (en fonction des jauges)
    typePalier paliers[NB_PALIER];  /// Caract??ristiques pour chaque palier (Jauge, Conditionneur, filtre)

    QString etablissement;          /// Nom de l'??tablissement o?? sont r??alis??s les exp??riences
    QString nomEtudiant;            /// Nom de l'??tudiant r??alisant l'exp??rience
    QString prenomEtudiant;         /// Pr??nom de l'??tudiant r??alisant l'exp??rience
    QString classe;                 /// Classe de l'??tudiant r??alisant l'exp??rience
    QString commentaire;            /// Commentaire de l'exp??rience
    QDate   date;
    bool    configExperience;       /// Vrai si l'utilisateur ?? bien configur?? l'exp??rience


    quint32 nbEchantillons;     /// Nombre d'??chantillons dans le tableau de mesures brutes
    quint16 origine;            /// Valeur du d??calage ?? l'origine
    qint16  vitesse;            /// Vitesse de l'exp??rience
    double *mesuresBrutes ;     /// Tableau de mesures brutes (allocation dynamique)

    QList<PointDeCourbe> courbeA;
    QList<PointDeCourbe> courbeO;


};

#endif // EXPERIENCE_H
