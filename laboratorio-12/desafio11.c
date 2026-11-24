// Faça uma função que implemente o algoritmo Insertion
// Sort para ordenação dos dados da estrutura de dados
// Tpessoa a seguir, por ordem decrescente do valor do
// campo nome. Construa um programa principal para
// testar sua solução. Use a mesma formatação do
// exemplo de E/S a seguir. O primeiro valor indica a
// quantidade de pessoas com os dados a serem informados.
// Exemplo de entrada(stdin)
// e saída(stdout)

// Entrada 
// Joao 20 
// Jose 35 
// Ana 30 
// Carlos 21 

//     Saída
//     Jose : 35 anos
//     Joao : 20 anos
//     Carlos : 21 anos
//     Ana : 30 anos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa
{
    char nome[30];
    int idade;
} Tpessoa;

void insertionSort(Tpessoa pessoas[], int quantidade)
{
    for (int i = 1; i < quantidade; i++)
    {
        Tpessoa atual = pessoas[i];
        int j = i - 1;

        while (j >= 0 && strcmp(pessoas[j].nome, atual.nome) < 0)
        {
            pessoas[j + 1] = pessoas[j];
            j--;
        }

        pessoas[j + 1] = atual;
    }
}

int main(void)
{
    int quantidade;
    if (scanf("%d", &quantidade) != 1 || quantidade < 0)
        return 1;

    Tpessoa *pessoas = malloc((size_t)quantidade * sizeof(*pessoas));
    if (quantidade > 0 && pessoas == NULL)
        return 1;

    for (int i = 0; i < quantidade; i++)
    {
        if (scanf("%29s %d", pessoas[i].nome, &pessoas[i].idade) != 2)
        {
            free(pessoas);
            return 1;
        }
    }

    insertionSort(pessoas, quantidade);

    for (int i = 0; i < quantidade; i++)
        printf("%s : %d anos\n", pessoas[i].nome, pessoas[i].idade);

    free(pessoas);
    return 0;
}