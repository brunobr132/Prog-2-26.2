#include <stdio.h>
#include <stdlib.h>

void buscaMenorMaiorBin(int arr[], int tam, int el, int *menor, int *maior)
{
    int inicio = 0;
    int fim = tam;

    while (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        if (*(arr + meio) < el)
            inicio = meio + 1;
        else
            fim = meio;
    }
    *menor = inicio;

    inicio = 0;
    fim = tam;
    while (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        if (*(arr + meio) <= el)
            inicio = meio + 1;
        else
            fim = meio;
    }
    *maior = tam - inicio;
}

int main(void)
{
    int tam;
    int el;

    if (scanf("%d", &tam) != 1 || tam < 0)
        return 1;
    if (scanf("%d", &el) != 1)
        return 1;

    int *arr = malloc((size_t)tam * sizeof(*arr));
    if (tam > 0 && arr == NULL)
        return 1;

    for (int i = 0; i < tam; i++)
    {
        if (scanf("%d", arr + i) != 1)
        {
            free(arr);
            return 1;
        }
    }

    int menor;
    int maior;
    buscaMenorMaiorBin(arr, tam, el, &menor, &maior);
    printf("Menor: %d - Maior: %d\n", menor, maior);

    free(arr);
    return 0;
}
