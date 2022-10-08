#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matmul_vector.h"
#include "matmul_vector.c"


int main()
{
    int NRuns = 5;
    size_t i, j;

    double *runtimes;
    double *A, *V, *C;

    #define N 6
    int arr[N] = {500, 512, 1000, 1024, 2000, 2048};
    int c;

    for(int c=0; c<=N; c++)
    {
        A = (double *) malloc(arr[c] * arr[c] * sizeof(double));
        V = (double *) malloc(arr[c] * sizeof(double));
        C = (double *) malloc(arr[c] * arr[c] * sizeof(double));
        runtimes = (double *) malloc(NRuns * sizeof(double));

        RandomMatrix(&A[0], arr[c]);
        RandomVector(&V[0], arr[c]); 


    // ij ordering
        double average_runtime = 0.0;
        for(int n = 0; n < NRuns; n++)
        {
            runtimes[n] = CalcMatmulTime_ij(&A[0], &V[0], &C[0], arr[c]);
            // printf("runtime %lf seconds\n", runtimes[n]);
            average_runtime += runtimes[n]/NRuns;
        }
        printf("%d \n", arr[c]);

        printf("average runtime ij %lf seconds \n", average_runtime);

    // ji ordering
        average_runtime = 0.0;
        for(int n = 0; n < NRuns; n++)
        {
            runtimes[n] = CalcMatmulTime_ji(&A[0], &V[0], &C[0], arr[c]);
            // printf("runtime %lf seconds\n", runtimes[n]);
            average_runtime += runtimes[n]/NRuns;
        }
        printf("average runtime ji %lf seconds \n", average_runtime);
        printf("----------------------------------\n");


        free(A);
        free(V);
        free(C);
    }
    return 0;
}


