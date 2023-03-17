#include <stdio.h>
#include <stdlib.h>

int partition(int *vetor, int p, int r){
    int q = p;
    int aux;
    for(int u = p; u <= r-1; u++){
        if(vetor[u] <= vetor[r]){
            aux = vetor[q];
            vetor[q] = vetor[u];
            vetor[u] = aux;
            q++;
        }
    }
    aux = vetor[q];
    vetor[q] = vetor[r];
    vetor[r] = aux;
    return q;
}

void quickSort(int *vetor, int p, int r){
    if(p < r){
        int q;
        q = partition(vetor,p,r);
        quickSort(vetor,p,q-1);
        quickSort(vetor,q+1,r);
    }
}


int main()
{
    int vetor[10] = {12,9,3,7,14,11,6,2,10,5};
    quickSort(vetor,0,9);
    for(int i = 0; i < 10; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
}