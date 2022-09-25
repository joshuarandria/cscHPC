#include "stdio.h"
#include "stdlib.h"
 
// #ifdef _OPENMP
int omp_get_num_threads();
int omp_get_thread_num();
int omp_get_max_threads();
// #endif
 
int main()
{
    int a = 5, b = 14, c = 20;
    printf("Hello world\n");
    printf("%d\n", omp_get_max_threads());
#pragma omp parallel num_threads(4) private(a) firstprivate(b) shared(c)
    {
        int tid = omp_get_thread_num();
        a += tid;
        b += tid;
        printf(" %d, %d, %d, %d\n", tid, a, b, c);
    }
 
    printf("\n\n");
}
 
/*
Q1b
6 threads lancés par défaut
Q1c
???
*/
