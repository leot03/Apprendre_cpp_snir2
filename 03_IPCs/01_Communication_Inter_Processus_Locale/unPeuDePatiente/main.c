#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	int pid;
        int pidFils;
        char buffer[255];
        // p1
	pid = fork();
	if (pid == 0) { //P2
            sprintf(buffer, "Mon pid est de %d, le pid de mon père est de %d\n", getpid, getppid);
            boite("P2", buffer);
	} else { // P1
            pid = fork();
            if (pid==0) {// P3 
                sprintf(buffer, "Mon pid est de %d, le pid de mon père est de %d\n", getpid, getppid);
                boite("P3", buffer);
            } 
        } else { //P1
            // attendre la fin d'un fils
            pidFils = wait(NULL);
            sprintf(buffer, "Mon pid est de %d, le pid du fils termine %d\n", getpid, getppid);
            boite("P1", buffer);
            }
	return EXIT_SUCCESS;
}