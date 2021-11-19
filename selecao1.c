#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int* array, int size) {
  int pivot = array[size-1];
  int i = -1;
  int j;

  for(j = 0; j < size-1; j++)
    if(array[j] <= pivot)
      troca(&array[++i], &array[j]);
  troca(&array[i+1], &array[j]);

  return i + 1;
}

int partitionSelection2(int* array, int inicio, int fim) {
  int pivot = array[fim-1];
  int i = -1;
  int j;

  for(j = inicio; j < fim; j++)
    if(array[j] <= pivot)
      troca(&array[++i], &array[j]);
  troca(&array[i+1], &array[j]);

  return i + 1;
}

void quicksort(int* array, int size) {
  int q;
  if (size > 0) {
    q = partition(array, size);

    quicksort(array, q);
    quicksort(&array[q+1], size - (q + 1));
  }
}

int Selecao1 (int* array, int size, int i){
    quicksort(array, size);
    return array[i-1];

}

int Selecao2 (int* array, int inicio, int fim, int i) {
    int q;
    if (fim - inicio > 0){
        q = partitionSelection2(array, inicio, fim);
        if ((fim - inicio) == 0) return array[inicio - 1];
        if (i < q) 
            return Selecao2(array, inicio, q-1 ,i);
        else if (i > q) 
            return Selecao2(array, q+1, fim, i - (q+1));
        else return array[q-1];
    }
}

int main()
{
    float time_spent1 = 0.0;
    int i, size;
    int *array1;
    int position = 25487;

    size = 50000000;

    array1 = (int*) malloc(sizeof(int)*size);

    srand(time(NULL));

    for(i = 0; i < size; i++) array1[i] = rand();
    
    clock_t start1 = clock();
    int nu = Selecao1(array1, size, position);
    clock_t pause1 = clock();

    time_spent1 += (float) (pause1 - start1) / CLOCKS_PER_SEC;

    printf("Tempo decorrido na selecao1 %.10f\n",time_spent1);
    printf("N %i", nu);

    return 0;
}