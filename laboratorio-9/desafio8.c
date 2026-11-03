#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX_NOME 21
#define TEMPO_BASE_ATENDIMENTO 10

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char nome[MAX_NOME];
    long long segundo_chegada;
    long long numero_produtos;

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
    if (novo == NULL)
        return false;
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

void reinicializarFila(FILA *f)
{
    CLIENTE cliente;
    while (excluirDaFila(f, &cliente))
    {
    }
}

int main(void)
{
    FILA fila_clientes;
    inicializarFila(&fila_clientes);

    int C;
    long long K;
    if (scanf("%lld%d", &K, &C) != 2 || C < 0)
    {
        fprintf(stderr, "Erro: entrada invalida.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < C; i++)
    {
        CLIENTE cliente;
        if (scanf("%20s%lld%lld", cliente.nome, &cliente.segundo_chegada,
                  &cliente.numero_produtos) != 3)
        {
            fprintf(stderr, "Erro: dados de cliente invalidos.\n");
            reinicializarFila(&fila_clientes);
            return EXIT_FAILURE;
        }

        if (!inserirNaFila(&fila_clientes, cliente))
        {
            fprintf(stderr, "Erro: nao foi possivel alocar memoria para a fila.\n");
            reinicializarFila(&fila_clientes);
            return EXIT_FAILURE;
        }
    }

    long long tempo_saida_anterior = 0;
    CLIENTE cliente;
    while (excluirDaFila(&fila_clientes, &cliente))
    {
        long long inicio_atendimento = cliente.segundo_chegada;
        if (inicio_atendimento < tempo_saida_anterior)
            inicio_atendimento = tempo_saida_anterior;

        long long tempo_saida = inicio_atendimento + TEMPO_BASE_ATENDIMENTO +
                                K * cliente.numero_produtos;
        printf("%s %lld %lld\n", cliente.nome, cliente.segundo_chegada,
               tempo_saida);
        tempo_saida_anterior = tempo_saida;
    }

    return EXIT_SUCCESS;
}