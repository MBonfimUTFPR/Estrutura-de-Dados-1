#include <stdio.h>
#include <stdlib.h>

void insertion(int* vetor, int n){
    int chave;
    int j;
    for(int i = 1; i < n; i++){
        chave = vetor[i];
        j = i - 1;
        while((j>=0) && (vetor[j]>chave)){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j+1] = chave;
    }
}

int main()
{
    int vetor[10] = {10,5,7,3,7,3,9,2,8,4};
    insertion(vetor,10);
    for(int i = 0; i < 10; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
}