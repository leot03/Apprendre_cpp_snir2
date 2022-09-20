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
            // attendre la fin de P1
            waitpid(getppid(), NULL, 0);
            
            sprintf(buffer, "Mon pid est de %d, le pid de mon père est de %d\n", getpid, getppid);
            boite("P2", buffer);
	} else { // P1
            sprintf(buffer, "Mon pid est de %d\n", getpid());
            boite("P1", buffer);
        }
	return EXIT_SUCCESS;
}