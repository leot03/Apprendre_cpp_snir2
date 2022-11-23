#include <stdio.h>
#include <stdlib.h>
// include pour socket
#include <sys/types.h>
#include <sys/socket.h>
// include pour sockaddr_in
#include <netinet/in.h>
#include <arpa/inet.h>
// include gestion erreurs
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char** argv) {
    int sock;
    int valEnvoyee, valRecue;
    int retour;
    struct sockaddr_in infosServeur;
    struct sockaddr_in infosReception;
    socklen_t taille;
    // creation de la socket udp
    sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == -1) {
        printf("pb socket : %s\n", strerror(errno));
        exit(errno);
    }
    // init de la structure pour communiquer avec le serveur
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(2222); // port dans ordre reseau
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.150");
    // envoyer l'entier au serveur
    valEnvoyee = 101010101;
    retour = sendto(
            sock,
            &valEnvoyee,
            sizeof(valEnvoyee),
            0,
            (struct sockaddr *)&infosServeur,
            sizeof(infosServeur));
    if (retour == -1) {
        printf("pb sendto : %s\n", strerror(errno));
        exit(errno);
    }
    // recevoir l'entier en provenance du serveur
    retour=recvfrom(
            sock,
            &valRecue,
            sizeof(valRecue),
            0,
            (struct sockaddr *)&infosReception,
            &taille
            );
    if (retour == -1) {
        printf("pb recvfrom : %s\n", strerror(errno));
        exit(errno);
    }
    // affiche l'entier
    printf("reponse du serveur : %d \n",valRecue);

    return (EXIT_SUCCESS);
}

