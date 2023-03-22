#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char nome[30];
    int ra;
    struct aluno *prox;
}Aluno;

typedef struct{
    Aluno *topo;
    int tamanho;
}Pilha;

void inicializarPilha(Pilha *s){
    s->topo = NULL;
    s->tamanho++;
}

int tamanhoPilha(Pilha *s){
    return(s->tamanho);
}

int estaVazia(Pilha *s){
    return(s->tamanho == 0);
}

void inserirPilha(Pilha *s, int ra, char *nome){
    Aluno *aux;
    aux = (Aluno*) malloc(sizeof(Aluno));
    
    strcpy(aux->nome,nome);
    aux->ra = ra;
    aux->prox = s->topo;
    
    s->topo = aux;
    s->tamanho++;
}

void listaPilha(Pilha *s){
    Aluno *aux;
    aux = s->topo;
    while(aux != NULL){
        printf("%s | %d \n",aux->nome ,aux->ra);
        aux = aux->prox;
    }
    
}

Aluno removerElemPilha(Pilha *s){
    Aluno *aux;
    aux = s->topo;
    s->topo = aux->prox;
    s->tamanho--;
    return *aux;
}

void destroiPilha(Pilha *s){
    Aluno *aux;
    while(s->topo != NULL){
        aux = s->topo;
        s->topo = aux->prox;
        free(aux);
    }
    s->tamanho = 0;
}

Aluno topoPilha(Pilha *s){
    return *(s->topo);
}

int main()
{
    Pilha p;
    inicializarPilha(&p);
    inserirPilha(&p,2453258,"matheus");
    inserirPilha(&p,1233,"adawd");
    listaPilha(&p);
    printf("\n");
    destroiPilha(&p);
    inserirPilha(&p,567567,"davi");
    inserirPilha(&p,4324,"hrthh");
    listaPilha(&p);
    printf("\n");

    Aluno x = topoPilha(&p);
    printf("%s | %d \n",x.nome ,x.ra);
    printf("\n");
}