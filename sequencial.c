#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
// #include <mpi.h>

#define SIZE 10000

void oddEvenSort(int arr[], int size)
{
  int notSorted, i, temp;
  do {
    notSorted=0;
    // Para o Odd
    for (i=1; i<size-1; i+=2)
    {
      if(arr[i]>arr[i+1])
      {
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
        notSorted=1;
      }
    }
    // Para o Even
    for (i=0; i<size-1; i+=2)
    {
      if(arr[i]>arr[i+1])
      {
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
        notSorted=1;
      }
    }
  } while(notSorted);
}

void bubbleSort(int arr[], int size) {
  for (int step = 0; step < size-1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
}

void printArray(int arr[], int size)
{
  printf("Array Ordenado: ");
  for (int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main (int argc, char *argv[]) 
{
  int arr[SIZE];
  int i;
  
  for (i = 0; i < SIZE-1; i++) {
    arr[i] = rand();
  }
  
  double begin, end;
  begin = omp_get_wtime();
  // begin = MPI_Wtime();

  oddEvenSort(arr, SIZE);
  //bubbleSort(arr, SIZE);

  end = omp_get_wtime();
  // end = MPI_Wtime();
  
  // printArray(arr, SIZE);
  printf("%F\n", end - begin);
  return 0;
}
