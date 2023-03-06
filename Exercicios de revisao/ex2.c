#include <stdio.h>
#include <stdlib.h>

/*Faca um programa que receba, por argumento na main, o nome de um arquivo texto. Crie
outro arquivo texto de saıda contendo o texto do arquivo de entrada original, porem substituindo todas
as vogais ‘a’ pelo caractere ‘*’ e as demais vogais por ‘+’. Alem disso, mostre na tela quantas linhas
esse arquivo possui. Dentro do programa faca o controle de erros, isto e, insira comandos que mostre se
os arquivos foram abertos com sucesso e, caso contrario, imprima uma mensagem de erro encerrando o
programa.*/

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Deve ter o nome do arquivo a ser aberto passado como argumento \n");
        return 1;
    }

    FILE *arq = fopen(argv[1],"r");
    if(arq == NULL){
        printf("Arquivo não foi encontrado\n");
        return 1;
    }else{
        printf("Arquivo foi aberto\n");
    }

    FILE *novo_arq = fopen("Arquivo_resultado.txt","w");

    char c;
    int cont = 0;
    int cont_linha = 0;
    while(1){
        c = fgetc(arq);
        
        if(c == EOF){
            cont_linha++;
            break;
        }

        if(c == 'a'){
            fputc('*',novo_arq);
        }else if( (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')){
            fputc('+',novo_arq);
        }else{
            fputc(c,novo_arq);
        }

        if(c == '\n'){
            cont_linha++;
        }

        cont++;
    }
    printf("O arquivo possui %d linhas \n",cont_linha);


    fclose(arq);
    fclose(novo_arq);
    
}