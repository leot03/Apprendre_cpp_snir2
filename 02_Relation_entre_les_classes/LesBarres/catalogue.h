#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "barre.h"

class Catalogue
{
private:
    Barre **lesBarres;
    int index;
    const int nbBarres;
public:
    Catalogue(const int _nbBarres);
    ~Catalogue();
    bool AjouterBarre(Barre *ptrBarre);
    void AfficherCatalogue();
};

#endif // CATALOGUE_H
