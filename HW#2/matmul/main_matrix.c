#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matmul_matrix.h"
#include "matmul_matrix.c"


int main()
{
    int NRuns = 5;
    size_t i, j, k;

    double *runtimes;
    double *A, *B, *C;

    #define N 6
    int arr[N] = {500, 512, 1000, 1024, 2000, 2048};
    int c;

    for(int c=0; c<N; c++)
    {
        A = (double *) malloc(arr[c] * arr[c] * sizeof(double));
        B = (double *) malloc(arr[c] * arr[c] * sizeof(double));
        C = (double *) malloc(arr[c] * arr[c] * sizeof(double));
        runtimes = (double *) malloc(NRuns * sizeof(double));

        RandomMatrix(&A[0], arr[c]);
        RandomMatrix(&B[0], arr[c]);

    // ijk ordering
        double average_runtime = 0.0;
        for(int n = 0; n < NRuns; n++)
        {
            runtimes[n] = CalcMatmulTime_ijk(&A[0], &B[0], &C[0], arr[c]);
            // printf("runtime %lf seconds\n", runtimes[n]);
            average_runtime += runtimes[n]/NRuns;
        }
        printf("%d \n", arr[c]);

        printf("average runtime ijk %lf seconds \n", average_runtime);

    // jik ordering
        average_runtime = 0.0;
        for(int n = 0; n < NRuns; n++)
        {
            runtimes[n] = CalcMatmulTime_jik(&A[0], &B[0], &C[0], arr[c]);
            // printf("runtime %lf seconds\n", runtimes[n]);
            average_runtime += runtimes[n]/NRuns;
        }
        printf("average runtime jik %lf seconds \n", average_runtime);

    // kij ordering
        average_runtime = 0.0;
        for(int n = 0; n < NRuns; n++)
        {
            runtimes[n] = CalcMatmulTime_kij(&A[0], &B[0], &C[0], arr[c]);
            // printf("runtime %lf seconds\n", runtimes[n]);
            average_runtime += runtimes[n]/NRuns;
        }
        printf("average runtime kij %lf seconds \n", average_runtime);
        printf("----------------------------------\n");

        free(A);
        free(B);
        free(C);
    }
    return 0;
}

