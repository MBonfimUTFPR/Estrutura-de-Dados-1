#include <stdio.h>
#include <stdlib.h>

void criaHeap(int *vetor, int i, int f){
    int aux = vetor[i];
    int j = i*2 + 1;
    while(j <= f){
        if(j < f){
            if(vetor[j] > vetor[j + 1]){
                j += 1;
            }
        }
        if(aux > vetor[j]){
            vetor[i] = vetor[j];
            i = j;
            j = 2*i + 1;
        }else{
            j = f + 1;
        }
    }
    vetor[i] = aux;
}

void heapSort(int *vetor, int n){
    int aux;
    for(int i = (n - 1)/2; i >= 0; i--){
        criaHeap(vetor, i, n-1);
    }
    for(int i = n-1; i >= 1; i--){
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criaHeap(vetor, 0, i - 1);
    }
}


int main()
{
    int vetor[10] = {12,9,3,7,14,11,6,2,10,5};
    heapSort(vetor,10);
    for(int i = 0; i < 10; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
}