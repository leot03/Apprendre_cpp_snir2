#include <iostream>

using namespace std;

void AfficherTableau(const unsigned char *tab);

int main()
{
    unsigned char adresse[4] = {192.168.1.1};
    unsigned char masque[4];
    unsigned char reseau[4];
    unsigned char diffusion[4];

    IPv4 uneAdresse(adresse, 24);

    cout << "Adresse IPV4 :";
    AfficherTableau(adresse);
    uneAdresse.ObtenirMasque(masque);
    cout << "Masque:";
    AfficherTableau(masque);
    return 0;
}

void AfficherTableau(const unsigned char *tab) {
    for (int indice =0; indice < 4; indice++) {
        cout << static_cast<int>(tab[indice++]);
        if(indice < 3)
            cout << ".";
    }
    cout << endl;
}
