#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int B[n1];
    int C[n2];

    for(int i = 0; i < n1; i++){
        B[i] = vetor[p + i];
    }
    for(int i = 0; i < n2; i++){
        C[i] = vetor[q + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while(i < n1 && j < n2){
        if(B[i] <= C[j]){
            vetor[k] = B[i];
            i++;
        }else{
            vetor[k] = C[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        vetor[k] = B[i];
        i++;
        k++;
    }

    while(j < n2){
        vetor[k] = C[j];
        j++;
        k++;
    }
}

void mergeSort(int *vetor, int p, int r){
    if(p < r){
        int q = (int)(p+r)/2;
        mergeSort(vetor,p,q);
        mergeSort(vetor,q+1,r);
        merge(vetor,p,q,r);
    }

}


int main()
{
    int vetor[10] = {12,9,3,7,14,11,6,2,10,5};
    mergeSort(vetor,0,9);
    for(int i = 0; i < 10; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
}