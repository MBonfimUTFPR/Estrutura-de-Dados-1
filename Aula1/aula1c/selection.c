#include <stdio.h>
#include <stdlib.h>

void selection(int* vetor, int n){
    int aux;
    for(int i = 0; i < n-1; i++){       
        for(int j = i+1; j < n; j++){
            if(vetor[j] < vetor[i]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main()
{
    int vetor[10] = {1,5,7,3,7,3,9,2,8,4};
    selection(vetor,10);
    for(int i = 0; i < 10; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
}