#include <stdio.h>

#include<stdlib.h>

#include <time.h>

#include<cblas.h>

/*
  int main(int argc, char* argv[])

  The main program creates two static vectors and then computes their
  dot product using the BLAS routing ddot (double precision dot product)

  Inputs: none

  Outputs: The dot product of the two vectors
  Usage:
  $ gcc -o ip example-71.c -lblas
  $./ip
*/

int main(int argc, char * argv[]) {
  clock_t start, end;
  double cpu_time_used;

  start = clock();
  int n = atoi(argv[1]);
  // x and y are the two vectors that we will use
  double * x = malloc(sizeof(double) * n);
  double * y = malloc(sizeof(double) * n);

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      x[i] = 1.0;
    else
      x[i] = -1.0;
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 1)
      y[i] = 1.0;
    else
      y[i] = -1.0;
  }
//   for (int i = 0; i < n; i++) {
//     printf("%lf ", x[i]);

//   }
//   printf("\n");
//   for (int i = 0; i < n; i++) {
//     printf("%lf ", y[i]);

//   }
//   printf("\n");

  int lib = atoi(argv[2]);
  double dotprod = 0.0;
  if (lib == 1) {

    for (int i = 0; i < n; i++) {
      dotprod += (x[i] * y[i]);
    }
  } else {
    dotprod = cblas_ddot(n, x, 1, y, 1);
  }
  //
  printf("%s %lf\n", lib == 1 ? "loop" : "library", dotprod);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  // print the result
  printf("This task took %f seconds to execute \n", cpu_time_used);

  return 0.;
}
