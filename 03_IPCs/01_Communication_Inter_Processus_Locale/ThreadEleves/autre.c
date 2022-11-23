/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/syscall.h>

typedef struct {
    int v1;
    int v2;
    int v3;
}laStruct;

laStruct partage;

void *thread1(void *arg) {
    int val = 1;
    printf("dans le thread1 mon tid est de %d\n", syscall(SYS_gettid));
    printf("mise a jour de v1 avec la valeur %d\n :%d\n", val);
    partage.v1 = val;
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2, t3;
    int ret;
    void *thread_result;
    // élément de la structure commune aux threads
    partage.v1 = 0;
    partage.v2 = 0;
    partage.v3 = 0;
    printf("avant création threads\n");
    
	ret = pthread_create(&t1, NULL, thread1, (void *)NULL);
    if (ret != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("attente de la fin du thread...\n");
    
	ret = pthread_join(t1, &thread_result);
    if (ret != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
    printf("OK, valeur de retour du Thread join :%s\n", (char *)thread_result);
    printf("Le message est maintenant %s\n", NULL);
    exit(EXIT_SUCCESS);
}
*/