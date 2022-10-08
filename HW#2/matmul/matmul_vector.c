#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matmul_matrix.h"


void ZeroVector(double * A, size_t N)
{
    for(size_t i=0; i<N; i++)
    {

        A[i] = 0.0;
    
    }
}

void RandomVector(double * A, size_t N)
{
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {

        A[i] = rand() / RAND_MAX;
    
    }
}

double CalcMatmulTime_ij(double * A, double * V, double * C, size_t N)
{
    struct timeval start, end;
    double r_time = 0.0;
    size_t i, j, k;

    ZeroMatrix(&C[0], N);

    gettimeofday(&start, NULL);

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            C[i * N + j] = A[i * N + k] * V[j];
        }
    gettimeofday(&end, NULL);

    r_time = end.tv_sec - start.tv_sec + ((double) (end.tv_usec - start.tv_usec)) / 1000000;

    return r_time;
}

double CalcMatmulTime_ji(double * A, double * V, double * C, size_t N)
{
    struct timeval start, end;
    double r_time = 0.0;
    size_t i, j, k;

    ZeroMatrix(&C[0], N);

    gettimeofday(&start, NULL);

    for (j = 0; j < N; j++)
        for (i = 0; i < N; i++)
        {
            C[i * N + j] = A[i * N + k] * V[j];
        }
    gettimeofday(&end, NULL);

    r_time = end.tv_sec - start.tv_sec + ((double) (end.tv_usec - start.tv_usec)) / 1000000;

    return r_time;
}
