#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <QObject>
#include <QList>
#include <QPointF>
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



signals:

private:

    quint16 vitesseMaxi;            /// vitesse maximale pour une consigne de 100% (en fonction des jauges)
    typePalier paliers[NB_PALIER];  /// Caractéristiques pour chaque palier (Jauge, Conditionneur, filtre)
    QString etablissement;          /// Nom de l'établissement où sont réalisés les expériences

    quint32 nbEchantillons;     /// Nombre d'échantillons dans le tableau de mesures brutes
    quint16 origine;            /// Valeur du décalage à l'origine
    qint16  vitesse;            /// Vitesse de l'expérience
    double *mesuresBrutes ;     /// Tableau de mesures brutes (allocation dynamique)

    QList<PointDeCourbe> courbeA;
    QList<PointDeCourbe> courbeO;


};

#endif // EXPERIENCE_H
