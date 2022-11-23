/*#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>
#include <string.h>

#define TAILLEMAXBUFFER 4096
#define TAILLEPAGE 2048

int main(int argc, char** argv) {

    int sockServeur;
    int sockClient;
    int retour;
    struct sockaddr_in adresseServeur;
    struct sockaddr_in adresseClient;
    int tailleClient;


    char enTeteHttp[TAILLEMAXBUFFER], buffer2[TAILLEMAXBUFFER], pageHTML[TAILLEPAGE];
    memset(enTeteHttp, '\0', TAILLEMAXBUFFER);
    memset(buffer2, '\0', TAILLEMAXBUFFER);


    sprintf(pageHTML, "<!DOCTYPE html><html><head><title>serveur perso</title><style>h1{text-align: center;}</style></head><body><h1>c'est mon serveur http</h1>\n<p1>Tom Mussard</p1></body></html>");
    sprintf(enTeteHttp, "HTTP/1.1 200 OK\nContent-Length: %ld\nContent-type: text/html\n\n", strlen(pageHTML));


    adresseServeur.sin_family = AF_INET;
    adresseServeur.sin_port = htons(8888);
    adresseServeur.sin_addr.s_addr = htonl(INADDR_ANY);


    sockServeur = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockServeur == -1) {
        printf("pb socket : %s\n", strerror(errno));
        exit(0);
    }

    retour = bind(sockServeur, (struct sockaddr *) &adresseServeur, sizeof (adresseServeur));

    if (retour == -1) {
        printf("pb bind : %s\n", strerror(errno));
        exit(0);
    }

    retour = listen(sockServeur, 10);
    if (retour == -1) {
        printf("pb listen : %s\n", strerror(errno));
        exit(0);
    }
    while (1) {
        tailleClient = sizeof ( adresseClient);
        sockClient = accept(sockServeur, (struct sockaddr *) &adresseClient, &tailleClient);

        retour = read(sockClient, buffer2, TAILLEMAXBUFFER);
        if (retour == -1) {
            printf("pb connect : %s\n", strerror(errno));
            exit(0);
        }
        retour = write(sockClient, enTeteHttp, strlen(enTeteHttp));
        if (retour == -1) {
            printf("pb connect : %s\n", strerror(errno));
            exit(0);
        }
        retour = write(sockClient, pageHTML, strlen(pageHTML));
        if (retour == -1) {
            printf("pb connect : %s\n", strerror(errno));
            exit(0);
        }
    }
    return (EXIT_SUCCESS);
}*/