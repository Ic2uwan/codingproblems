#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 8

int A[NUM_THREADS];
void *PrintHello(void *threadId) {
int* data = static_cast <int*> (threadId);
    printf("Hello World! It's me, thread #%d!\n", *data);
    A[*data] += 10;
    pthread_exit(NULL);
    return nullptr;
}

int main (int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int tids[NUM_THREADS];
    for(int i=0; i<NUM_THREADS; i++){

        tids[i] = i;
        pthread_create(&threads[i], NULL, PrintHello, (void *)&tids[i]);

    }
    pthread_exit(NULL);
}
