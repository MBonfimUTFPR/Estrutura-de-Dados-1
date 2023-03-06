#include <stdio.h>
#include <stdlib.h>

/*Faca um programa que leia um valor N e crie dinamicamente um vetor com essa
quantidade de elementos. Em seguida, passe esse vetor para um procedimento que vai preencher os
elementos desse vetor com numeros aleatorios de 0 ate N. Depois, no programa principal, imprima os
valores do vetor preenchido. Alem disso, antes de finalizar o programa, lembre-se de liberar a area de
memoria alocada.*/

int main()
{
    int n;
    int *vetor;

    printf("insira o valor de n: ");
    scanf("%d",&n);

    vetor = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        vetor[i] = rand() % n+1;
    }

    for(int i = 0; i < n; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");

    free(vetor);
}