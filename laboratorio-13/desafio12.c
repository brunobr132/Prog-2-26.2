#include <stdio.h>
#include <stdlib.h>

static void intercala(int p, int q, int r, int v[])
{
    int *w;
    w = malloc((r - p) * sizeof(int));
    int i = p, j = q;
    int k = 0;
    while (i < q && j < r)
    {
        if (v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i < q)
        w[k++] = v[i++];
    while (j < r)
        w[k++] = v[j++];
    for (i = p; i < r; ++i)
        v[i] = w[i - p];
    free(w);
};

void mergesort_iterativo(int n, int v[])
{
    for (int b = 1; b < n; b *= 2)
    {
        for (int inicio = 0; inicio < n; inicio += 2 * b)
        {
            int meio = inicio + b;
            if (meio > n)
                meio = n;

            int fim = inicio + 2 * b;
            if (fim > n)
                fim = n;

            intercala(inicio, meio, fim, v);
        }
    }
};

int main()
{
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    mergesort_iterativo(n, v);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}