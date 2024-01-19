#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000
#define NUM_THREADS 4

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main (int argc, char *argv[]) 
{
    int A[SIZE];
    for(int i=0; i<SIZE; i++)
    {
        A[i] = rand();
    }
    
    int N = SIZE;
    int i=0, j=0;
    int first;

    double begin, end;
    begin = omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);
    
    for(i=0; i<N-1; i++)
    {
        first = i%2; 
        #pragma omp parallel for default(none) shared(A,first,N)
        for(j=first; j<N-1; j+=2)
        {
            if(A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
            }
        }
    }
    
    end = omp_get_wtime();
    
    printArray(A, SIZE);
    printf("%F\n", end - begin);
      return 0;
}
