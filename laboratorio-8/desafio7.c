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
#include <string.h>
#define true 1
#define false 0
typedef int bool;
typedef long long TIPOCHAVE;

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
        printf("%lld ", end->reg.chave);
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

bool excluirElemPilha(PILHA *p, REGISTRO *reg)
{
    if (p->topo == NULL)
        return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}
void reinicializarPilha(PILHA *p)
{
    PONT apagar;
    PONT posicao = p->topo;
    while (posicao != NULL)
    {

        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}

int main(void)
{
    char expressao[34];
    if (fgets(expressao, sizeof(expressao), stdin) == NULL)
    {
        fprintf(stderr, "Erro: nenhuma expressao foi informada.\n");
        return EXIT_FAILURE;
    }

    size_t comprimento = strlen(expressao);
    while (comprimento > 0 &&
           (expressao[comprimento - 1] == '\n' || expressao[comprimento - 1] == '\r'))
    {
        expressao[--comprimento] = '\0';
    }

    if (comprimento == 0 || comprimento > 30)
    {
        fprintf(stderr, "Erro: a expressao deve ter entre 1 e 30 caracteres.\n");
        return EXIT_FAILURE;
    }

    PILHA pilha;
    inicializarPilha(&pilha);
    const char *erro = NULL;

    for (size_t i = 0; i < comprimento && erro == NULL; i++)
    {
        char caractere = expressao[i];
        if (caractere >= '0' && caractere <= '9')
        {
            REGISTRO operando = {caractere - '0'};
            if (!inserirElemPilha(&pilha, operando))
                erro = "Erro: nao foi possivel alocar memoria para a pilha.";
            continue;
        }

        if (caractere != '+' && caractere != '-' &&
            caractere != '*' && caractere != '/')
        {
            erro = "Erro: a expressao contem um caractere invalido.";
            break;
        }

        REGISTRO direita, esquerda;
        if (!excluirElemPilha(&pilha, &direita) ||
            !excluirElemPilha(&pilha, &esquerda))
        {
            erro = "Erro: faltam operandos para um operador.";
            break;
        }

        TIPOCHAVE resultado;
        switch (caractere)
        {
        case '+':
            resultado = (long long)esquerda.chave + direita.chave;
            break;
        case '-':
            resultado = (long long)esquerda.chave - direita.chave;
            break;
        case '*':
            resultado = (long long)esquerda.chave * direita.chave;
            break;
        default:
            if (direita.chave == 0)
            {
                erro = "Erro: divisao por zero.";
                break;
            }
            resultado = esquerda.chave / direita.chave;
            break;
        }

        if (erro != NULL)
            break;

        REGISTRO registroResultado = {resultado};
        if (!inserirElemPilha(&pilha, registroResultado))
            erro = "Erro: nao foi possivel alocar memoria para a pilha.";
    }

    if (erro == NULL && (pilha.topo == NULL || pilha.topo->prox != NULL))
        erro = "Erro: a expressao nao forma um resultado unico.";

    if (erro != NULL)
    {
        fprintf(stderr, "%s\n", erro);
        reinicializarPilha(&pilha);
        return EXIT_FAILURE;
    }

    REGISTRO resultado;
    excluirElemPilha(&pilha, &resultado);
    printf("%lld\n", resultado.chave);
    return EXIT_SUCCESS;
}