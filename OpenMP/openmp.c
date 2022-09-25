/* question 1 */

#include "stdio.h"
#include "stdlib.h"

#ifdef _OPENMP
int omp_get_thread_num();
#endif


int main()
{
 int a=1 , b=2 , c=3 ;

#pragma omp parallel private (a) firstprivate(b) shared(c)
{
 	// int tid = omp_get_thread_num();
    int tid =3;
	a=a+tid;
	b=b+tid;
	printf(" %d, %d, %d, %d \n", tid, a, b,c);
}


#ifdef _OPENMP
#pragma omp parallel
	{
        /* nbre threads lancés printf("%d\n", omp_get_num_threads());*/
	printf("hello world %d\n ", omp_get_thread_num());
	}
#endif

}
