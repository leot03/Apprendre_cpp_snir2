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
/*
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
*/
////////////////////////////////////////////////////////////////////////////////
