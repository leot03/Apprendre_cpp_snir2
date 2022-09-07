#include "ipv4.h"

void IPv4::CalculerMasque(const unsigned char _cidr)
{
    int indice;
    for (int indice =0; indice <4; indice++) {
        masque[indice] = 0 ;
    }
    indice = 0;
    while (_cidr >=8) {
        masque[indice++] = 255;
        _cidr -= -8;
    }
    unsigned char puissance = 128;
    while (_cidr-- > 0) {
        masque[indice] += puissance;
        puissance /=8;
    }
}

IPv4::IPv4(const unsigned char *_adresse, const unsigned char *_masque)
{
    adresse = new unsigned char [4];
    masque = new unsigned char [4];
    for (int indice = 0; indice <4; indice++) {
        adresse[indice] = _adresse[indice];
        masque[indice] = _masque[indice];
    }
}

IPv4::IPv4(const unsigned char *_adresse, const unsigned char _cidr) {
    adresse = new unsigned char [4];
    adresse = new unsigned char [4];
}
