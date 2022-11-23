/*
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <signal.h>
#include <stdio.h>

#define TAILLE_MAX 255

int main(int argc, char** argv) {
    int fdSocket;
    struct sockaddr_in informationServeur;
    int retour;
    int tailleClient;
    char msgEnvoye[TAILLE_MAX];
    char msgRecu[TAILLE_MAX];
    int pid;
    if (argc != 2) {
        printf("Usage : %s IpDuServeur\n", argv[0]);
        exit(EXIT_SUCCESS);
    }
    printf("client de tchat tcp port 5678\n");
    informationServeur.sin_family = AF_INET;
    informationServeur.sin_port = htons(8888);
    informationServeur.sin_addr.s_addr = inet_addr(argv[1]);

    fdSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (fdSocket == -1) {
        printf("pb socket : %s\n", strerror(errno));
        exit(errno);
    }
    //demande de connexion au serveur
    retour = connect(fdSocket, (struct sockaddr *) &informationServeur,
            sizeof (informationServeur));
    if (retour == -1) {
        printf("pb connect : %s\n", strerror(errno));
        exit(errno);
    }
    pid = fork();
    if (pid == 0)//boucle d'envoie
    {
        do {
            printf("votre message : ");
            gets(msgEnvoye);
            retour = write(fdSocket, msgEnvoye, strlen(msgEnvoye));
            if (retour == -1) {
                printf("pb write : %s\n", strerror(errno));
                exit(errno);
            }
        } while (strcmp("a+", msgEnvoye) != 0);
        //arreter le processus de reception
        kill(getppid(),SIGTERM);
        close(fdSocket);
    } else//boucle de reception
    {
        while(1)
        {
            // reception en provenance du serveur
            memset(msgRecu, '\0', TAILLE_MAX);
            retour = read(fdSocket, msgRecu, TAILLE_MAX);
            if (retour == -1) {
                printf("pb read : %s\n", strerror(errno));
                exit(errno);
            }
            printf("\nmsg provenant du serveur :%s\n", msgRecu);
        }
    }
    // envoyer donnees au serveur
    
    

    return (EXIT_SUCCESS);
}*/