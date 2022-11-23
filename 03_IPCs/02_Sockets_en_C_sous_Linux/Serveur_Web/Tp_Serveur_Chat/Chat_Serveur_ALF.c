/*
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#define TAILLE_MAX 4096


int main(int argc, char** argv) {

    int fdSocket, fdSocketClient;
    struct sockaddr_in adresseServeur;
    struct sockaddr_in adresseClient;
    int retour;
    int tailleClient;

    char msgEnv[TAILLE_MAX];
    char msgRecu[TAILLE_MAX];

    adresseServeur.sin_family = AF_INET;
    adresseServeur.sin_port = htons(8888);
    adresseServeur.sin_addr.s_addr = INADDR_ANY;  

    //stresseur de serveur
    fdSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (fdSocket == -1) {
        printf("pb socket : %s\n", strerror(errno));
        exit(0);
    }
    retour = bind(fdSocket, (struct sockaddr*) &adresseServeur, sizeof ( adresseServeur));
    if (retour == -1) {
        printf("pb bind : %s\n", strerror(errno));
        exit(0);
    }
    retour = listen(fdSocket, 10);
    if (retour == -1) {
        printf("pb listen : %s\n", strerror(errno));
        exit(0);
    }

    tailleClient = sizeof ( adresseClient);
    fdSocketClient = accept(fdSocket, (struct sockaddr *) &adresseClient, &tailleClient);
    if (fdSocketClient == -1) {
        printf("pb accept : %s\n", strerror(errno));
        exit(0);
    }
    do {
        memset(msgRecu, '\0', TAILLE_MAX);
        retour = read(fdSocketClient, msgRecu, TAILLE_MAX);
        if (retour == -1) {
            printf("pb read : %s\n", strerror(errno));
            exit(0);
        }
        printf("msg provenant du client %s: %s  \n\n", inet_ntoa(adresseClient.sin_addr),msgRecu);
        printf("votre message : ");
        gets(msgEnv);
        retour = write(fdSocketClient, msgEnv, strlen(msgEnv));
        if (retour == -1) {
            printf("pb write : %s\n", strerror(errno));
            exit(0);
        }
    } while (strcmp("a+", msgRecu) != 0);
    close(fdSocket);
    close(fdSocketClient);
    return (EXIT_SUCCESS);
}


*/