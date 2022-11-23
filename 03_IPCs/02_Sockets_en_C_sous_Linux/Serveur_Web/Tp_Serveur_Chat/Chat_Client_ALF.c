/* 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv) {

    struct sockaddr_in {
        sa_family_t sin_family; // famille d'adresses : AF_INET sur 16 bits
        u_int16_t sin_port; // port dans l'ordre d'octets réseau
        struct in_addr sin_addr; // adresse Internet
        char sin_zero[8]; // initialise à zéro
    };

    struct in_addr {
        u_int32_t s_addr;
    };

    int sockServeur;
    int retour;
    struct sockaddr_in infosServeur;
    socklen_t tailleServeur = sizeof (infosServeur);
    char valClient[255];


    sockServeur = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockServeur == -1) {
        printf("pb socket : %s\n", strerror(errno));
        exit(errno);
    }

    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(8888); 
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.74");

    retour = connect(sockServeur, (struct sockaddr*) &infosServeur, tailleServeur);
    if (retour == -1) {
        printf("pb connect : %s\n", strerror(errno));
        exit(errno);
    }

    printf("Client, ");
    while (1) {
        printf("ecrivez : ");
        gets(valClient);
        printf("\n");
        if (valClient != " ") {
            retour = write(sockServeur, (void *) &valClient, sizeof (valClient));
            if (retour == -1) {
                printf("pb write : %s\n", strerror(errno));
                exit(errno);
            }
        }
        retour = read(sockServeur, (void *) &valClient, sizeof (valClient));
        if (retour == -1) {
            printf("pb read : %s\n", strerror(errno));
            exit(errno);
        }
        printf("%s: %s\n", inet_ntoa(infosServeur.sin_addr), valClient);

    }while(strcmp("a+", &valClient)!=0);
    close(sockServeur);
    return (EXIT_SUCCESS);
}

*/