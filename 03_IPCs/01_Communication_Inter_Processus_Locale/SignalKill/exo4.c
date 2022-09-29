// td3 exo 4
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
    int pid;
    int pidP2;
    (void) signal(SIGUSR1, traitement); // rederoutage des signaux SIGUSR1
    // vers la fonction traitement

    //P1    
    pid = fork();
    if (pid == 0) // P2
    {
        pid = fork();
        if (pid == 0) //P3
        {
            pidP2 = getppid();
            printf("p3 pid=%d\n", getpid());
            sleep(2); // tempo pour envoyer signal en décalé
            kill(pidP2, SIGUSR1);


        } else //P2
        {
            printf("p2 pid=%d\n", getpid());
            // attendre les 2 signaux en provenance de P2 et P3 avant de se terminer
            pause();
            pause();
        }

    } else // P1
    {

        pidP2 = pid;
        printf("pere pid=%d\n", getpid());
        sleep(1); // tempo pour envoyer signal en décalé
        kill(pidP2, SIGUSR1);
        sleep(2);
    }

    return EXIT_SUCCESS;
}