#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief definição da estrutura Endereco, que é utilizada dentro da estrutura Cadastro
 * 
 */
typedef struct{
    char rua[50];
    char cidade[50];
    char estado[50];
}Endereco;


/**
 * @brief definição da estrutura Cadastro, que guarda informações de um funcionario 
 * 
 */
typedef struct{
    char nome[50];
    Endereco endereco;
    float salario;
    char estado_civil[50];
    int idade;
    char sexo;
}Cadastro;


/**
 * @brief procedimento utilizado para limpar a tela do terminal
 * 
 */
void limpa_tela(){
    system("clear||cls");
}

/**
 * @brief procedimento para limpar o buffer do teclado da melhor maneira dependendo o systema sendo utilizado, Windows ou Linux
 * 
 */
void limpaBuffer(){
    #ifdef _WIN32 //Testa se o SO é Windows
        fflush(stdin);
    #else
        setbuf(stdin,NULL);
    #endif
}

/**
 * @brief Função lê um arquivo contendo os funcionarios e le o numero de funcionarios no arquivo, sendo esse numero indicado no arquivo
 * 
 * @param arq arquivo utilizado para a leitura do numero de funcionarios
 * @return int retorna o numero de funcionarios no arquivo
 */
int verifica_num_funcionarios(FILE *arq){
    char linha[100];
    int conta_linha = 0;
    int num;
    while (1){
        fgets(linha,100,arq);
        if(conta_linha == 1){
            break;
        }
        conta_linha++;
          
    }
    num = atoi(linha);
    return num;
}

/**
 * @brief Função cria um vetor dinamico de struct da estrutura Cadastro para armazenar os funcionarios.
 * Le o arquivo dos funcionarios e registra todos eles dentro do vetor
 * 
 * @param num num de funcionarios no arquivo para serem registrados
 * @param arq arquivo para se ler os funcionarios
 * @return Cadastro* retorna o vetor dinamico com as devidas alterações
 */
Cadastro* registra_funcionarios(int num, FILE *arq){
    int conta_linha = 0;
    char linha[100];
    Cadastro *funcionarios = (Cadastro*) malloc(num * sizeof(Cadastro));
    

    char rua[50];
    char cidade[50];
    char estado[50];
    char nome[50];
    float salario;
    char estado_civil[50];
    int idade;
    char sexo;

    while(conta_linha < num){
        conta_linha++;
        fscanf(arq,"{%[^;]; {%[^;];%[^;];%[^}]} ; %f; %[^;]; %d; %c}",nome ,rua ,cidade ,estado ,&salario ,estado_civil ,&idade ,&sexo);
        
        strcpy(funcionarios[conta_linha - 1].nome,nome);
        strcpy(funcionarios[conta_linha - 1].endereco.rua,rua);
        strcpy(funcionarios[conta_linha - 1].endereco.cidade,cidade);
        strcpy(funcionarios[conta_linha - 1].endereco.estado,estado);
        funcionarios[conta_linha - 1].salario = salario;
        strcpy(funcionarios[conta_linha - 1].estado_civil,estado_civil);
        funcionarios[conta_linha - 1].idade = idade;
        funcionarios[conta_linha - 1].sexo = sexo;

        fgets(linha,100,arq);
    }
    return funcionarios;    
}


/**
 * @brief Função para criar uma heap do vetor dos funcionarios, tendo o funcionario no topo da heap aquele de menor salario
 * 
 * @param vetor vetor dos funcionarios para a criação da heap
 * @param i indice do elemento pai
 * @param f indice do ultimo elemento do vetor
 * @return Cadastro* retorna o vetor com as devidas alterações 
 */
Cadastro* criaHeap(Cadastro *vetor, int i, int f){
    Cadastro aux = vetor[i];
    int j = i*2 + 1;
    while(j <= f){
        if(j < f){
            if(vetor[j].salario > vetor[j+1].salario)
                j++;
        }
        if(vetor[j].salario < aux.salario){
            vetor[i] = vetor[j];
            i = j;
            j = i*2 + 1;
        }else{
            j = f+1;
        }
    }
    vetor[i] = aux;
    return vetor;
}

/**
 * @brief Função para a ordenação de um vetor de funcionarios usando o metodo de heap sort
 * 
 * @param vetor vetor de funcionarios para a ordenação
 * @param n numero de elementos no vetor
 * @return Cadastro* retorna o vetor de funcionarios com as devidas modificações
 */
Cadastro* heapSort(Cadastro *vetor, int n){
    Cadastro aux;
    for(int i = (n-1)/2; i >= 0;i--){
        vetor = criaHeap(vetor,i, n-1);
    }
    for(int i = n-1; i >= 1; i--){
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        vetor = criaHeap(vetor,0,i-1);
    }
    return vetor;
}

/**
 * @brief Procedimento para listar os funcionarios registrados no vetor de funcionarios
 * 
 * @param vetor vetor de funcionarios
 * @param n numero de elementos no vetor de funcionarios
 */
void listaFuncionarios(Cadastro *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("Nome: %s, Salario %.2f \n",vetor[i].nome ,vetor[i].salario);
    }
}

/**
 * @brief Procedimento para a exportação de um arquivo .txt, tendo em seu conteudo uma lista em csv dos funcionarios 
 * mostrando de caad funcionario seu nome,salario,idade,sexo respectivamente 
 * 
 * @param vetor vetor dos funcionarios 
 * @param n numero de elementos no vetor de funcionarios
 */
void exportaArquivo(Cadastro *vetor,int n){
    FILE *arq_export = fopen("ARQUIVO.txt","w");
    for(int i = 0; i < n; i++){
        fprintf(arq_export,"%s,%.2f,%d,%c\n",vetor[i].nome ,vetor[i].salario ,vetor[i].sexo ,vetor[i].sexo);
    }
    fclose(arq_export);
}

int main(int argc, char *argv[])
{   
    if(argc != 2){
        printf("Quantidade inadequada de argumentos\n");
        printf("Pressione enter para continuar... ");
        getchar();
        return 1;
    }

    char nome_arq[50];
    strcpy(nome_arq,argv[1]);

    int num_funcionarios;
    FILE *arq = fopen(nome_arq,"r");
    if(arq == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        return 1;
    }

    num_funcionarios = verifica_num_funcionarios(arq);
    Cadastro *funcionarios = registra_funcionarios(num_funcionarios, arq);

    funcionarios = heapSort(funcionarios,num_funcionarios);
    printf("\n");
    listaFuncionarios(funcionarios,num_funcionarios);

    exportaArquivo(funcionarios,num_funcionarios);

    fclose(arq);
    free(funcionarios);
}