#include <stdio.h>
#include <stdlib.h>

void bubble(int* vetor, int n){
    int troca;
    int aux;
    do{
        troca = 0;
        for(int i = 0; i < n-1; i++){
            if(vetor[i] > vetor[i+1]){
                troca++;
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }while(troca != 0);
}

int main()
{
    int vetor[10] = {1,5,7,3,7,3,9,2,8,4};
    bubble(vetor,10);
    for(int i = 0; i < 10; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
}