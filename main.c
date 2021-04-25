#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

long const N = 100000000;

int main(int argc, char *argv[]) {
    clock_t start = clock();
    long *tab = (long*)malloc(N * sizeof(long));
    int i;
#pragma omp parallel shared(tab)
#pragma omp single
     {
         printf("%d \n" , omp_get_num_threads());
         }
    for (i = 0; i < N; i++) tab[i] = rand();
clock_t end = clock();
float seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("%.6f", seconds);

    return 0;
}