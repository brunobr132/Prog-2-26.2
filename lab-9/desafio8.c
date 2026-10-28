#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX_NOME 20

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char nome[MAX_NOME];
    int segundo_chegada;
    int numero_produtos;

} CLIENTE;

typedef struct aux
{
    CLIENTE reg;
    struct aux *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
    PONT inicio;
    PONT fim;
} FILA;

void inicializarFila(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}
int tamanho(FILA *f)
{
    PONT end = f->inicio;
    int tam = 0;
    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }
    f->fim = NULL;
    return tam;
}

void exibirFila(FILA *f)
{
    PONT end = f->inicio;
    printf("Fila: \" ");
    while (end != NULL)
    {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

bool inserirNaFila(FILA *f, CLIENTE reg)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
    return true;
}

bool excluirDaFila(FILA *f, CLIENTE *reg)
{
    if (f->inicio == NULL)
        return false;
    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if (f->inicio == NULL)
        f->fim = NULL;
    return true;
}

int main(){
    FILA fila_clientes;
    inicializarFila(&fila_clientes);
    int C,K;
}