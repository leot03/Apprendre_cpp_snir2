#ifndef CHARIOT_H
#define CHARIOT_H

enum {
    VERS_MAGASIN = false,
    VERS_ENCEINTE
};

class Chariot
{
public:
    void DeplacerChariot(const bool _sens, const int _rangee, const int _colonne);
};

#endif // CHARIOT_H
