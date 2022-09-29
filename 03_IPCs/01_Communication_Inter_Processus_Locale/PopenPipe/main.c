///////////////////////////////// Exercice n°4 /////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

void traitement(int sig) {
    (void) signal(SIGUSR1, traitement);
    printf("Un signal SIGUSR1 je suis pid : %d\n", getpid());
}

int main(int argc, char** argv) {
    int nbOctets;
    int descTube[2];
    int pid, pidP1, pidP2, pidP3;
    
    char buffer[BUFSIZ];

    (void) signal(SIGUSR1, traitement); // Rederoutage des signaux SIGUSR1
    // Vers la fonction traitemet
    memset(buffer, '\0', BUFSIZ);
    // P1
    
    pidP1 = getpid(); // Sauvegarde du pid de P1 pour P3
    printf("Début pid P1 : %d\n", pidP1); 
    if (pipe(descTube) == 0) {
        if(pipe(descTube) == 0) {
            pid = fork();
            if (pid == 0) { // P3
                pidP3 = getpid();
                printf("P3 pid = %d\n", pidP3);
                nbOctets = write(descTube[1], &pidP3, sizeof(pidP3));
                printf("Je suis P3 : %d octets écrits\n", nbOctets);
            } else { // P2
                printf("P2 pid = %d\n", getpid());
                pause(); // Attente signal SIGUSR1
            }
        } else { // P1
            pidP2 = pid; //Le pid de P2 est dans le pid, on sauvegarde dans pidP2
            printf("Père pid = %d\n", getpid());
            sleep(3); // Tempo pour envoyer le signal en décalé
            kill(pidP2, SIGUSR1);
            // Manque read tube + kill vers P30.
        }
    }
    return (EXIT_SUCCESS);
}
////////////////////////////////////////////////////////////////////////////////


/*
///////////////////////////////// Exercice n°3 /////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv) {
    int nbOctets;
    int descTube[2];
    int descTube2[2];
    int pid;
    const char chaine[] = "Message en provenance de P1";
    const char chaine2[] = "Message en provenance de P2";
    char buffer[BUFSIZ];
    memset(buffer, '\0', BUFSIZ);
    char buffer2[BUFSIZ];
    memset(buffer2, '\0', BUFSIZ);
    // P1
    if (pipe(descTube) == 0) {
        if(pipe(descTube2) == 0) {
            pid = fork();
            if (pid == 0) { // P2
                nbOctets = write(descTube2[1], chaine2, strlen(chaine2));
                printf("Je suis P2 : %d octets écrits\n", nbOctets);
                nbOctets = read(descTube[0], buffer, BUFSIZ);
                printf("Je suis P2 : octets lus : %d : %s\n", nbOctets, buffer);
            } else { // P1
                nbOctets = write(descTube[1], chaine, strlen(chaine));
                printf("Je suis P1 : %d octets écrits\n", nbOctets);
                nbOctets = read(descTube2[0], buffer, BUFSIZ);
                printf("Je suis P1 : octets lus : %d : %s\n", nbOctets, buffer2);
            }
        }
    }
    return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////



///////////////////////////////// Exercice n°2 /////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv) {
    int nbOctets;
    int descTube[2];
    int pid;
    const char chaine[] = "Message en provenance de P1";
    char buffer[BUFSIZ];
    memset(buffer, '\0', BUFSIZ);
    // P1
    if (pipe(descTube) == 0) { // P2
        pid = fork();
        if (pid == 0) {
            nbOctets = read(descTube[0], buffer, BUFSIZ);
            printf("Je suis P2 : octets lus : %d : %s\n", nbOctets, buffer);
        } else { // P1
            nbOctets = write(descTube[1], chaine, strlen(chaine));
            printf("Je suis P1 : %d octets écrits\n", nbOctets);
        }
    }
    return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////

*/