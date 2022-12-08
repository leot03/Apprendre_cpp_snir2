#ifndef RAPPORTMESURES_H
#define RAPPORTMESURES_H

#include <QPdfWriter>
#include <QFont>
#include <QString>

#include "experience.h"
#include "vuegraphique.h"


class RapportMesures : public QPdfWriter
{
public:
    RapportMesures(Experience &_experience, QChartView &_graphique, QString &_nomDuFichierPdf);
    void ConstruireRapport();
private:
    void FabriquerEntete();
    void FabriquerResultats();
    void FabriquerGraphique();
    void FabriquerCommentaire();
    int largeurPdf;
    int hauteurPdf;
    int margeGauche;
    int margeHaut;
    int largeurUtile;
    int padding;
    QFont fontTitre;
    QFont fontTexte;
};

#endif // RAPPORTMESURES_H
