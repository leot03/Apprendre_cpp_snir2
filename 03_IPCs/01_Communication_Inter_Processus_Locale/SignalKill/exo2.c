// td3 exo 2
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// fonction de traitement du signal SIGUSR1

void traitement(int sig) {
    (void) signal(SIGUSR1, traitement);
    printf("un signal SIGUSR1 je suis pid :%d\n", getpid());
}

int main(int argc, char *argv[]) {
    int pid, pidP1;
    (void) signal(SIGUSR1, traitement); // rederoutage des signaux SIGUSR1
    //P1
    pidP1 = getpid();
    // vers la fonction traitement
    pid = fork();
    if (pid == 0) // P2
    {
        pid = fork();
        if (pid == 0) //P3
        {
            printf("p3 pid=%d\n", getpid());
            kill(pidP1, SIGUSR1);


        } else //P2
        {
            printf("p2 pid=%d\n", getpid());
            kill(pidP1, SIGUSR1);
        }

    } else // P1
    {

        printf("pere pid=%d\n", getpid());
        // attendre les 2 signaux en provenance de P2 et P3 avant de se terminer
        pause();
        pause();




    }


    return EXIT_SUCCESS;
}