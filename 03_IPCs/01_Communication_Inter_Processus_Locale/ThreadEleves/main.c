#include <stdio.h>
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

void *threadMulti(void *arg) {
    laStruct *ptr = (laStruct *) arg;
    printf("dans le threadMulti mon tid est %ld\n", syscall(SYS_gettid));
    printf("mise à jour de v1,v2,v3 avec les valeurs  %d, %d, %d\n", ptr->v1, ptr->v2, ptr->v3);
    
    partage.v1 = ptr->v1;
    partage.v2 = ptr->v2;
    partage.v3 = ptr->v3;
    
    pthread_exit(NULL);
}

void affichagePartage() {
    printf("____________________\n");
    printf("v1 = %d\n", partage.v1);
    printf("v2 = %d\n", partage.v2);
    printf("v3 = %d\n", partage.v3);
}

int main() {
    pthread_t t1, t2, t3;
    int ret;
    laStruct valparam1,valparam2 ,valparam3 ; 
    void *thread_result;
    
    pthread_mutex_t verrou;
    
     ret = pthread_mutex_init(&verrou, NULL);
    if (ret != 0) {
        printf("pb mutex initilisation");
        exit(EXIT_FAILURE);
    }
    
    
    // élément de la structure commune aux threads
    
    pthread_mutex_lock(&verrou);
    partage.v1 = 0;
    partage.v2 = 0;
    partage.v3 = 0;
    pthread_mutex_unlock(&verrou);
    printf("avant création threads\n");
    
    
    affichagePartage();
    
    valparam1.v1 = 1;
    valparam1.v2 = 1;
    valparam1.v3 = 1;
    ret = pthread_create(&t1, NULL, threadMulti, (void *) &valparam1);
    if (ret != 0) {
        printf("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("creation thread 1\n");
    
    valparam2.v1 = 2;
    valparam2.v2 = 2;
    valparam2.v3 = 2;
    ret = pthread_create(&t2, NULL, threadMulti, (void *) &valparam2);
    if (ret != 0) {
        printf("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("creation thread 2\n");
    
    valparam3.v1 = 3;
    valparam3.v2 = 3;
    valparam3.v3 = 3;
    ret = pthread_create(&t3, NULL, threadMulti, (void *) &valparam3);
    if (ret != 0) {
        printf("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("creation thread 3\n");
    
    ret = pthread_join(t1, &thread_result);
    if (ret != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
    ret = pthread_join(t2, &thread_result);
    if (ret != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
    ret = pthread_join(t3, &thread_result);
    if (ret != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
    
    printf("OK, valeur de retour du Thread join :%s\n", (char *)thread_result);
    printf("Le message est maintenant %s\n", NULL);
    
    exit(EXIT_SUCCESS);
}



