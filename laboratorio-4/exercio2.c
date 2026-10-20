/*Adicione uma nova função incluiElem(...)
ao exemplo anterior, cujos parâmetros são s, i,
j e num, tal que esta modifique o elemento
s[i][j] com o valor num. Faça um programa
principal que teste a função incluiElem(...)
para i=1, j=2 e num=10.*/
#include <stdio.h>
#define DIM 3

void inicM(int s[][DIM])
{
    int i, j;
    for (i = 0; i < DIM; i++)
        for (j = 0; j < DIM; j++)
            s[i][j] = 0;

}
void mostraM(int s[DIM][DIM])
{
    int i, j;
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
            printf(" [%d] ",s[i][j]);
        printf("\n");
    }
}

void incluiElem( int s[DIM][DIM], int i, int j, int num){
    for (int x = 0; x < DIM; x++)
        for (int y = 0; y < DIM; y++)
            if (x == i && y == j)
                s[x][y] = num;
}

int main()
    {
        int s[DIM][DIM];
        inicM(s);
        mostraM(s);
        return 0;
    }

