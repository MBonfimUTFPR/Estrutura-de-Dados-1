#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct{
    char nome[30];
    int ra;
}Aluno;

typedef struct pilhaEstatica{
    Aluno alunos[N];
    int topo;
}Pilha;

void inicializaPilha(Pilha *p){
    p->topo = 0;
}

int vaziaPilha(Pilha *p){
    return(p->topo == 0);
}

int cheiaPilha(Pilha *p){
    return(p->topo == N);
}

void empilharPilha(Pilha *p, Aluno x){
    if(cheiaPilha(p) == 0){
        p->alunos[p->topo] = x;
        p->topo++;
    }
}

Aluno desempilharPilha(Pilha *p){
    if(vaziaPilha(p) == 0){
        p->topo--;
        Aluno x = p->alunos[p->topo];
        return x;
    }
}

Aluno topoPilha(Pilha *p){
    Aluno x = p->alunos[p->topo - 1];
    return x;
}

void preenchePilha(Pilha *p){
    char nome[30];
    int ra;
    Aluno x;

    inicializaPilha(&p);

    for(int i = 0; i < N; i++){
        
        printf("Insira o nome: ");
        fgets(nome,30,stdin);
        nome[strcspn(nome,"\n")] = '\0';
        setbuf(stdin,NULL);

        printf("Insira o ra: ");
        scanf("%d",&ra);
        setbuf(stdin,NULL);

        system("clear");

        strcpy(x.nome,nome);
        x.ra = ra;
        empilharPilha(p,x);
    }
}

void listaPilha(Pilha *p){
    if(vaziaPilha(p) == 0){
        for(int i = p->topo - 1; i >= 0; i--){
            printf("[posicao %d] ra: %d nome: %s \n",i ,p->alunos[i].ra ,p->alunos[i].nome);
        }
    }
}

Aluno buscaPilha(Pilha *p){
    int ra_busca;
    Aluno x;
    printf("insira o ra que vc quer: ");
    scanf("%d",&ra_busca);

    while(p->alunos[p->topo - 1].ra != ra_busca){
        x = desempilharPilha(p);
    }
    x = topoPilha(p);
    return x;
}

int main()
{
    Pilha p;
    Aluno x;

    preenchePilha(&p);
    strcpy(x.nome,"ze");
    x.ra = 0;

    
    listaPilha(&p);
    
    getchar();
    setbuf(stdin,NULL);
    printf("\n\n");


    x = buscaPilha(&p);
    printf("[posicao %d] ra: %d nome: %s \n",p.topo - 1 ,x.ra ,x.nome);
    printf("\n\n");
    
    listaPilha(&p);

}
