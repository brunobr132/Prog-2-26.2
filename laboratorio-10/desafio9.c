#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

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
    PONT inicio;
} LISTA;

void inicializarLista(LISTA *lista)
{
    lista->inicio = NULL;
}

int tamanho(LISTA *lista)
{
    int tam = 0;
    PONT atual = lista->inicio;
    while (atual != NULL)
    {
        tam++;
        atual = atual->prox;
    }
    return tam;
}

void exibirLista(LISTA *lista)
{
    PONT atual = lista->inicio;
    printf("Lista: \" ");
    while (atual != NULL)
    {
        printf("%i ", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\"\n");
}

bool insere(LISTA *lista, REGISTRO reg, int pos)
{
    if (pos < 0 || pos > tamanho(lista))
        return false;

    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if (novo == NULL)
        return false;
    novo->reg = reg;

    if (pos == 0)
    {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        return true;
    }

    PONT anterior = lista->inicio;
    for (int i = 0; i < pos - 1; i++)
        anterior = anterior->prox;
    novo->prox = anterior->prox;
    anterior->prox = novo;
    return true;
}

bool exclui(LISTA *lista, int pos)
{
    if (pos < 0 || pos >= tamanho(lista))
        return false;

    PONT apagar;
    if (pos == 0)
    {
        apagar = lista->inicio;
        lista->inicio = apagar->prox;
    }
    else
    {
        PONT anterior = lista->inicio;
        for (int i = 0; i < pos - 1; i++)
            anterior = anterior->prox;
        apagar = anterior->prox;
        anterior->prox = apagar->prox;
    }

    free(apagar);
    return true;
}

bool modificaElem(LISTA *lista, REGISTRO reg, int pos)
{
    if (pos < 0)
        return false;

    PONT atual = lista->inicio;
    for (int i = 0; atual != NULL && i < pos; i++)
        atual = atual->prox;
    if (atual == NULL)
        return false;

    atual->reg = reg;
    return true;
}

bool listasIguais(LISTA *l1, LISTA *l2)
{
    PONT atual1 = l1->inicio;
    PONT atual2 = l2->inicio;
    while (atual1 != NULL && atual2 != NULL)
    {
        if (atual1->reg.chave != atual2->reg.chave)
            return false;
        atual1 = atual1->prox;
        atual2 = atual2->prox;
    }
    return atual1 == NULL && atual2 == NULL;
}

void concatenaListas(LISTA *l1, LISTA *l2)
{
    if (l1 == l2 || l2->inicio == NULL)
        return;

    if (l1->inicio == NULL)
    {
        l1->inicio = l2->inicio;
    }
    else
    {
        PONT fim = l1->inicio;
        while (fim->prox != NULL)
            fim = fim->prox;
        fim->prox = l2->inicio;
    }
    l2->inicio = NULL;
}

void reinicializarLista(LISTA *lista)
{
    PONT atual = lista->inicio;
    while (atual != NULL)
    {
        PONT apagar = atual;
        atual = atual->prox;
        free(apagar);
    }
    lista->inicio = NULL;
}

int main(void)
{
    LISTA l1, l2;
    REGISTRO reg;
    inicializarLista(&l1);
    inicializarLista(&l2);

    for (int valor = 10; valor <= 30; valor += 10)
    {
        reg.chave = valor;
        if (!insere(&l1, reg, tamanho(&l1)) ||
            !insere(&l2, reg, tamanho(&l2)))
        {
            fprintf(stderr, "Erro: nao foi possivel alocar memoria.\n");
            reinicializarLista(&l1);
            reinicializarLista(&l2);
            return EXIT_FAILURE;
        }
    }

    printf("Antes das modificacoes:\n");
    printf("l1 - ");
    exibirLista(&l1);
    printf("l2 - ");
    exibirLista(&l2);

    reg.chave = 99;
    modificaElem(&l2, reg, 1);
    printf("Apos a modificacao de l2:\n");
    printf("l2 - ");
    exibirLista(&l2);
    printf("Listas iguais? %s\n", listasIguais(&l1, &l2) ? "sim" : "nao");

    concatenaListas(&l1, &l2);
    printf("Depois da concatenacao:\n");
    printf("l1 - ");
    exibirLista(&l1);
    printf("l2 - ");
    exibirLista(&l2);

    reinicializarLista(&l1);
    reinicializarLista(&l2);
    printf("Listas iguais? %s\n", listasIguais(&l1, &l2) ? "sim" : "nao");
    return EXIT_SUCCESS;
}
