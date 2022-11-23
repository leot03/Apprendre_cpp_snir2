#include <stdio.h>
#include <stdlib.h>

#include "zone.h"

float randomF(){ 
    return ((float)100.0*(rand()/(RAND_MAX+0.1))); 
} 

int randomI(){ 
    return ((int)100.0*(rand()/(RAND_MAX+0.1))); 
}

int main(int argc, char** argv) {
/*
    struct donnees maFile;
    int idFile;
    unsigned int val = 0x0000000;
    unsigned int *pVal;
    char *pText
    unsigned int *pInt;
    int cpt;
    float valF;
*/
    struct donnees maFile;
    cahr tampon[255];
    int idFile;
    
    idFile = msgget((key_t) 5678, 0666 | IPC_CREAT);
    if (idFile == -1) {
        printf("pb creation file : %s\n", strerror(errno));
        exit(0);
    }
    while (1) {
        maFile.texte[0] = 'A';
        maFile.type = 3;
        msgsnd(idFile, (void*) &maFile, sizeof (char), IPC_NOWAIT);
        sleep(1);
    }
    return (EXIT_SUCCESS);
}


