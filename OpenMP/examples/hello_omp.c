#include <stdio.h>

#ifdef _OPENMP
#include <omp.h>
#endif

int main(int argc, char *argv[]) {
    #ifdef _OPENMP
    #pragma omp parallel 
    {
    #endif
        int numThreads = omp_get_num_threads();
        int threadId   = omp_get_thread_num();
        printf("Num of threads: %d, thread id: %d\n", numThreads, threadId);
    #ifdef _OPENMP
    }
    #endif
    return 0;
}