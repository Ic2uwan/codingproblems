#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
    printf("Master thread\n");
    static int a = 0;
    #pragma omp parallel num_threads(4)
    {
        int ID = omp_get_thread_num();
        printf("Multi Threading no.%d\n", ID);
    }
    return 0;
}