#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char rua[50];
    char cidade[50];
    char estado[50];
}Endereco;

typedef struct{
    char nome[50];
    Endereco endereco;
    float salario;
    char estado_civil[50];
    int idade;
    char sexo;
}Cadastro;

void limpa_tela(){
    system("clear||cls");
}

void limpaBuffer(){
    #ifdef _WIN32 //Testa se o SO é Windows
        fflush(stdin);
    #else
        setbuf(stdin,NULL);
    #endif
}

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

void registra_mudancas(Cadastro *funcionarios, int num, FILE *arq, char *nome_arq){
    fclose(arq);
    arq = fopen(nome_arq,"w");
    
    fputs("\n",arq);
    fprintf(arq,"%d\n",num);
    for(int i = 0; i < num; i++){
        fprintf(arq,"{%s; {%s;%s;%s} ; %.2f; %s; %d; %c}\n",funcionarios[i].nome ,funcionarios[i].endereco.rua ,funcionarios[i].endereco.cidade ,funcionarios[i].endereco.estado ,funcionarios[i].salario ,funcionarios[i].estado_civil ,funcionarios[i].idade ,funcionarios[i].sexo);
    }
    fclose(arq);
    arq = fopen(nome_arq,"r");
}

void pesquisa_nome(Cadastro *funcionarios, int num){
    limpa_tela();

    char nome[50];
    int achou = 0;
    int indice;

    printf("Insira o nome \nPesquisa-> ");
    fgets(nome,50,stdin);
    nome[strcspn(nome,"\n")] = '\0';
    limpaBuffer();

    for(int i = 0; i < num; i++){
        if(strcmp(funcionarios[i].nome,nome) == 0){
            achou = 1;
            indice = i;
            break;
        }
    }

    if(achou == 1){
        limpa_tela();
        printf("Nome: %s \nIdade: %d \nSalario: $ %.2f \n",funcionarios[indice].nome ,funcionarios[indice].idade ,funcionarios[indice].salario);
        printf("pressione enter para continuar... ");
        getchar();
    }else{
        printf("Nome nao encontrado\n");
        printf("pressione enter para continuar... ");
        getchar();
    }
    limpaBuffer();
}

void pesquisa_salario(Cadastro *funcionarios, int num){
    limpa_tela();

    float salario;
    int achou = 0;

    printf("Insira o limite minimo do salario \nPesquisa-> ");
    scanf("%f",&salario);
    limpaBuffer();
    limpa_tela();

    for(int i = 0; i < num; i++){
        if(funcionarios[i].salario > salario){
            achou = 1;
            printf("%s \n",funcionarios[i].nome);
        }
    }

    if(achou == 1){
        printf("\nFuncionarios encontrados\n");
        printf("pressione enter para continuar... ");
        getchar();
    }else{
        printf("Nenhum funcionario encontrado com o determinado salario\n");
        printf("pressione enter para continuar... ");
        getchar();
    }
    limpaBuffer();
}

void pesquisa_sexo(Cadastro *funcionarios, int num){
    limpa_tela();

    char sexo;
    int achou = 0;

    printf("Insira o sexo (M/F) \nPesquisa-> ");
    scanf("%c",&sexo);
    sexo = toupper(sexo);
    limpaBuffer();
    limpa_tela();

    for(int i = 0; i < num; i++){
        if(funcionarios[i].sexo == sexo){
            achou = 1;
            printf("Nome: %s \nIdade: %d \nSalario: $ %.2f \n\n",funcionarios[i].nome ,funcionarios[i].idade ,funcionarios[i].salario);
        }
    }

    if(achou == 1){
        printf("Funcionarios encontrados\n");
        printf("pressione enter para continuar... ");
        getchar();
    }else{
        printf("Sexo nao encontrado\n");
        printf("pressione enter para continuar... ");
        getchar();
    }
    limpaBuffer();
}

void alterar_idade(Cadastro *funcionarios, int num, FILE *arq, char *nome_arq){
    limpa_tela();

    char nome[50];
    int achou = 0;
    int indice;
    int idade;

    printf("Insira o nome \nPesquisa-> ");
    fgets(nome,50,stdin);
    nome[strcspn(nome,"\n")] = '\0';
    limpaBuffer();

    for(int i = 0; i < num; i++){
        if(strcmp(funcionarios[i].nome,nome) == 0){
            achou = 1;
            indice = i;
            break;
        }
    }

    if(achou == 0){
        limpa_tela();
        printf("Nome nao encontrado\n");
        printf("pressione enter para continuar... ");
        getchar();
        limpaBuffer();
    }else{
        printf("\nInsira a nova idade do funcionario (idade atual: %d)\n-> ",funcionarios[indice].idade);
        scanf("%d",&idade);
        limpaBuffer();

        if(idade > funcionarios[indice].idade){
            limpa_tela();
            funcionarios[indice].idade = idade;
            registra_mudancas(funcionarios,num,arq,nome_arq);
            printf("Mudanca feita\n");
            printf("Pressione enter para continuar... ");
            getchar();
            limpaBuffer();
        }else{
            limpa_tela();
            printf("Idade invalida\n");
            printf("Pressione enter para continuar... ");
            getchar();
            limpaBuffer();
        }
    }

    
}

void menu(Cadastro *funcionarios,int num_funcionarios,FILE *arq,char *nome_arq){
    int selecao;
    int sair = 0;

    while(sair == 0){
        do{
            limpa_tela();
            printf("Menu de Funcionarios\n");
            printf("1 - Pesquisa por nome \n2 - Pesquisa por salario \n3 - Pesquisa por sexo \n4 - Alterar idade \n0 - Sair \n-> ");
            scanf("%d",&selecao);
            limpaBuffer();
        }while((selecao < 0) || (selecao > 4));

        switch (selecao)
        {
        case 1:
            pesquisa_nome(funcionarios,num_funcionarios);
            break;
        case 2:
            pesquisa_salario(funcionarios,num_funcionarios);
            break;
        case 3:
            pesquisa_sexo(funcionarios,num_funcionarios);
            break;
        case 4:
            alterar_idade(funcionarios,num_funcionarios,arq,nome_arq);
            break;
        case 0:
            sair = 1;
            limpa_tela();
            printf("FIM DO PROGRAMA\n");
            printf("Pressione enter para continuar... ");
            getchar();
            break;
        default:
            break;
        }
    }

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

    menu(funcionarios,num_funcionarios,arq,nome_arq);

    fclose(arq);
    free(funcionarios);
}