#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/unistd.h>
#include <string.h>

#define MAXBUFF 255

int main() {
    int pid;
    char *msg = "bonjour, message de p1";
    char buffer[MAXBUFF] = {0};
    int tube[2];
    int retour;
    //P1
    
    memset(buffer, '\0', MAXBUFF);

    //Création du tube commun
    
    if (pipe(tube) == 0) {
        pid = fork();
        if (pid == 0) // P2
        {
            printf("pid : %d ppid : %d\n", getpid(), getppid());

            retour = read(tube[0], buffer, 255);
            if (retour==-1) {
                printf("pb de read dans le tube : %s", strerror(errno));
                exit(errno);
            }
            printf("message de p1 : %s\n", buffer);
        } else // P1
        {
            printf("pid : %d\n", getpid());
            retour = write(tube[1], msg, strlen(msg));
            if (retour==-1) {
                printf("pb de read dans le tube : %s", strerror(errno));
                exit(errno);
            }
        }
    } else {
        printf("pb de tube : %s", strerror(errno));
        exit(errno);
    }
    return 0;
}