#include <stdio.h>
#include <omp.h>

int main()
{
    const int N = 64;
    int A[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
#pragma omp parallel
    {

        const int thread_id = omp_get_thread_num();

// parallel computing for A[i] = A[i] + 1
#pragma omp for
        for (int i = 0; i < N; i++)
        {
            A[i] = A[i] + 1;
            printf("A[%d] is computed by thread number : %d\n", i, thread_id);
        }
    }

    // print the array after parallel computing
    for (int i = 0; i < N; i++)
    {
        printf("%d, ", A[i]);
    }
    printf("\n");
    return 0;
}