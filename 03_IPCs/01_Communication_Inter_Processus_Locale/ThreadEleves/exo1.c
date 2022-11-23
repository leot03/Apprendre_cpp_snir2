/*
 * #include <stdio.h>
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
    int *ptr = (int *) arg;
    int val = *ptr;
    printf("dans le thread1 mon tid est de %d\n", syscall(SYS_gettid));
    printf("mise a jour de v1 avec la valeur %d\n :%d\n", val);
    partage.v1 = val;
    pthread_exit(NULL);
}
void *thread2(void *arg) {
    int *ptr = (int *) arg;
    int val = *ptr;
    printf("dans le thread2 mon tid est de %d\n", syscall(SYS_gettid));
    printf("mise a jour de v2 avec la valeur %d\n :%d\n", val);
    partage.v2 = val;
    pthread_exit(NULL);
}
void *thread3(void *arg) {
    int *ptr = (int *) arg;
    int val = *ptr;
    printf("dans le thread3 mon tid est de %d\n", syscall(SYS_gettid));
    printf("mise a jour de v3 avec la valeur %d\n :%d\n",                          );
    partage.v3 = val;
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2, t3;
    int ret;
    int valParam1, valParam2, valParam3;
    void *thread_result;
    // élément de la structure commune aux threads
    partage.v1 = 0;
    partage.v2 = 0;
    partage.v3 = 0;
    printf("avant création threads\n");
    
    valParam1 = 4;
        ret = pthread_create(&t1, NULL, thread1, (void *) &valParam1);
    if (ret != 0) {
        printf("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("creation thread 1\n");

	ret = pthread_create(&t2, NULL, thread1, (void *)NULL);
    if (ret != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("attente de la fin du thread...\n");
    
	ret = pthread_join(t3, &thread_result);
    if (ret != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
    printf("OK, valeur de retour du Thread join :%s\n", (char *)thread_result);
    printf("Le message est maintenant %s\n", NULL);
    
    exit(EXIT_SUCCESS);
}*/