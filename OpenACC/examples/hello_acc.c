#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENACC
#include <openacc.h>
#endif 

int main(int argc, char *argv[]){

   int SIZE = 20000000;
   double* restrict a = malloc(SIZE * sizeof(double));
   double* restrict b = malloc(SIZE * sizeof(double));
   double* restrict c = malloc(SIZE * sizeof(double));

#ifdef _OPENACC
#pragma acc enter data create(a[0:SIZE],b[0:SIZE],c[0:SIZE])
#endif
   double scalar = 3.0;

#ifdef _OPENACC
#pragma acc parallel loop present(a[0:SIZE],b[0:SIZE])
#endif
   for (int i = 0; i < SIZE; ++i) {
      a[i] = 1.0;
      b[i] = 2.0;
   }

   for (int iter = 0; iter < 20; ++iter){
#ifdef _OPENACC
#pragma acc parallel loop present(a[0:SIZE],b[0:SIZE],c[0:SIZE])
#endif
      for (int i = 0; i < SIZE; ++i){
         c[i] = a[i] + scalar * b[i];
      }
   }
#ifdef _OPENACC
#pragma acc exit data delete(a[0:SIZE],b[0:SIZE],c[0:SIZE])
#endif
   
   free(a);
   free(b);
   free(c);

   return(0);
}