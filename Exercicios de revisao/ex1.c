#include <stdio.h>
#include <stdlib.h>

/*Escreva e programe uma funcao recursiva para calcular o valor de um numero inteiro de base
x elevada a um expoente inteiro y, sendo os valores de x>0 e y>0 fornecidos pelo usuario.*/

int potencia(int x, int y){
    if(y == 1){
        return x;
    }else{
        return x * potencia(x, y-1);
    }
}

int main()
{
    int x, y;
    printf("Insira o valor de x(base): ");
    scanf("%d",&x);
    printf("Insira o valor de y(expoente): ");
    scanf("%d",&y);

    int resultado = potencia(x,y);

    printf("Resultado: %d \n",resultado);
}