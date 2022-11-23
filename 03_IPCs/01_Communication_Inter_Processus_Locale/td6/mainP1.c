/*
#include "zone.h"

float randomF(){ 
	return ((float)100.0*(rand()/(RAND_MAX+0.1))); 
} 

int randomI(){ 
	return ((int)100.0*(rand()/(RAND_MAX+0.1))); 
}

int main(int argc, char** argv) {
    struct donnes *ZoneDePartage;
    int id;
    int oldt, oldp;
    
    // Création de la zone mémoire partagée
    id = shmget((key_t) 1234, sizeof (struct donnes), IPC_CREAT | 0600); // Autotisation de R/W
    if(id == -1) {
        if (errno != EEXIST) {
            printf("pb shmget : %s\n", strerror(errno));
            exit(2);
        }
    }
    
    //Attribution d'une adresse virtuelle du segment
    ZoneDePartage = (struct donnes *) shmat(id, NULL, SHM_W);
    if(ZoneDePartage == NULL) {
        printf("pb shmat : %s\n", strerror(errno));
        exit(1);
    }
    
    //Lecture et affichage de la zone de memoire partagée si NouvelleDonne a été mise à VRAI
    while(1) { // --> Boucle infinie
        ZoneDePartage->temp = randomF();
        ZoneDePartage->press = randomI();
        sleep(1);
    }
    return (EXIT_SUCCESS);
}

*/