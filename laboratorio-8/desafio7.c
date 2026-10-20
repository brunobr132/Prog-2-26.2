/*Faça um programa que calcule e apresente o resultado
de uma expressão em notação pós-fixa (também
conhecida como Notação Polonesa Reversa), utilizando
uma pilha dinâmica de inteiros. A cada operador
encontrado, os dois últimos valores da pilha são
desempilhados, a operação é realizada, e o resultado é
empilhado novamente. Considere que a expressão é
fornecida na entrada padrão, tem no máximo 30
caracteres, e contém somente dígitos de 0 a 9
(operandos de um dígito) e os operadores +, -,*/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    
} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
    PONT topo;
} PILHA;

void inicializarPilha(PILHA *p)
{
    p->topo = NULL;
}

int tamanho(PILHA *p)
{
    PONT end = p->topo;
    int tam = 0;
    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }
    return tam;
}
bool estaVazia(PILHA *p)
{
    if (p->topo == NULL)
        return true;
    return false;
}

void exibirPilha(PILHA *p)
{
    PONT end = p->topo;
    while (end != NULL)
    {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

bool inserirElemPilha(PILHA *p, REGISTRO reg)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if (novo == NULL)
        return false; 
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

void notacao(){
    PILHA p;
    inicializarPilha(&p);
    int 
}