#ifndef BARRECARREECREUSE_H
#define BARRECARREECREUSE_H

#include "barrecarree.h"
#include <string>

class BarreCarreeCreuse : public BarreCarree
{
public:
    BarreCarreeCreuse(const string _reference,
                      const string _nom,
                      const unsigned int _longueur,
                      const double _densite,
                      const unsigned int _cote,
                      const unsigned int _coteInt);
    ~BarreCarreeCreuse();

    double CalculerSection();
    double CalculerMasse();

private:
    unsigned int coteInt;
};

#endif // BARRECARREECREUSE_H
