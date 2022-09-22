#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int cpt;

// fonction de traitement du signal SIGUSR1
void traitement(int sig) {
    (void) signal(SIGUSR1, traitement);
    cpt++;
    printf("cpt : %d\n", cpt);
    if (cpt==2) {
        printf("un signal SIGUSR1 je suis pid : %d\n", getpid());
    }
}

int main(int argc, char *argv[]) {
    int pid, pidP1;
    (void) signal(SIGUSR1, traitement); // Rederoutage des signaux SIGUSR1
    //P1
    pidP1 = getpid();
    cpt = 0;
    // vers la fonction traitement
    pid= fork();
    if(pid == 0) {
        pid = fork();
        if(pid == 0) {//P2
            printf("p3 pid=%d\n", getpid());
            kill(pidP1, SIGUSR1);
        } else {
            printf("p2 pid=%d\n", getpid());
            kill(pidP1, SIGUSR1);
        }
    } else {
            printf("pere pid =%d\n", getpid());
            pause();
            pause();
        }
    return EXIT_SUCCESS;
}

/*
int main(int argc, char *argv[])
{
    int pid;
    (void) signal(SIGUSR1, traitement);	// rederoutage des signaux SIGUSR1
                                                    // vers la fonction traitement
    pid = fork();

    if (pid == -1)
    {
        printf("pb creation fork : %s\n", strerror(errno));
        exit(1);
    }
    else
    {
        if (pid == 0)		// process fils
        {
            printf("fils pid=%d\n", getpid());
            kill(getppid(), SIGUSR1);
            sleep(2);	// tempo pour être certain que le fils sera
                            //encore vivant quand le pere lui 
                            //enverra son signal
        }
        else		// process principal (pere)
        {
            printf("pere pid=%d\n", getpid());
            kill(pid, SIGUSR1);
            sleep(2);	// tempo pour être certain que le pere sera
                            //encore vivant quand le fils lui 
                            //enverra son signal
        }
    }

    return EXIT_SUCCESS;
}
*/