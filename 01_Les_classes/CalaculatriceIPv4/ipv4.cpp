#include "ipv4.h"



void IPv4::CalculerMasque(unsigned char _cidr)
{
    int indice;
    for(indice = 0; indice < 4; indice++){
        masque[indice] = 0;
    }
    indice = 0;
    while(_cidr >= 8){
        masque[indice++] = 255;
        _cidr -= 8;
    }
    unsigned char puissance = 128;
    while(_cidr-- > 0){
        masque[indice] += puissance;
        puissance /=2;
    }
}

IPv4::IPv4(const unsigned char *_addresse, const unsigned char _cidr)
{
    adresse = new unsigned char [4];
    masque = new unsigned char [4];

    for (int indice = 0; indice < 4; indice++){
        adresse[indice] = _addresse[indice];
        if(_cidr <= 32)
            CalculerMasque(_cidr);
    }
}

IPv4::IPv4(const unsigned char *_addresse, const unsigned char *_masque)
{
    adresse = new unsigned char [4];
    masque = new unsigned char [4];
    for (int indice = 0; indice < 4; indice++){
        adresse[indice] = _addresse[indice];
        masque[indice] = _masque[indice];
    }
}

IPv4::~IPv4()
{
    delete [] adresse;
    delete []masque;

}

void IPv4::ObtenirMasque(unsigned char *_masque)
{
    for(int indice = 0; indice <4; indice++)
        _masque[indice] = masque[indice];
}

void IPv4::ObtenirAddresseReseau(unsigned char *_reseau)
{
    for(int indice = 0 ; indice < 4 ; indice++)
    _reseau[indice] = adresse[indice] & masque[indice] ;
}

void IPv4::ObtenirAdresseDiffusion(unsigned char *_diffusion)
{
    unsigned char adresseDuReseau[4];
    ObtenirAddresseReseau(adresseDuReseau);
    for(int indice = 0 ; indice < 4 ; indice++)
    _diffusion[indice] = adresseDuReseau[indice] | ~masque[indice] ;
}
