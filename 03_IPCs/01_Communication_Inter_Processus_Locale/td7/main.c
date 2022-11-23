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
    struct donnees maFile;
    int idFile;
    unsigned int val = 0x0000000;
    unsigned int *pVal;
    char *pText
    unsigned int *pInt;
    int cpt;
    float valF;
    
    idFile = msgget((key_t) 5678, 0666 | IPC_CREAT);
    if (idFile == -1) {
        printf("pb creation file : %s\n", strerror(errno));
        exit(0);
    }
    while (1) {
        valF = randomF();
        
        sprintf(maFile.texte, "%f", valF);
        maFile.type = 2;
        msgsnd(idFile, (void*) &maFile, sizeof(float), IPC_NOWAIT);
        
        val = randomI();
        printf("val = %d\n", val);
        pVal = &val;
        pInt = (char*) &val;
        pTexte = maFile.texte;
        
        for (cpt = 0; cpt<sizeof (int); cpt++) {
            pTexte[cpt]
        }
    }

    return (EXIT_SUCCESS);
}