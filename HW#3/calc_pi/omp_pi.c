#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <time.h>


double pi_mc(size_t Npoints)
{
    int i, tid;
    unsigned int seed_x, seed_y;
    double x, y, pi;
    size_t count = 0;
    

#pragma omp parallel \
        shared(Npoints) \
        private(i, tid, seed_x, seed_y, x, y)
    {
        tid = omp_get_thread_num();
        seed_x = (time(NULL) & 0xFFF0F0FF) | (tid + 1);
        seed_y = (time(NULL) & 0xFFF0F0FF) | (tid + 11);

#pragma omp for reduction(+: count)
        for (i = 0; i < (Npoints); ++i)
        {
            double x = (double)rand_r(&seed_x) / RAND_MAX;
            double y = (double)rand_r(&seed_y) / RAND_MAX;
            
            if ( (x * x + y * y) <= 1)
                {
                count += 1;
                }
        }
    }
  return (count / (double) Npoints) * 4;
}


int main() {
  const unsigned int Npoints = 100000000;
  double pi = pi_mc(Npoints);
  printf("Pi with Monte Carlo method =%f\n", pi);
  return 0;
}