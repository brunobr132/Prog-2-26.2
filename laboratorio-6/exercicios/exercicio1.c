/*Faça um programa que recebe como entrada o nome de um arquivo texto. Seu
programa deve calcular e exibir a quantidade de vezes que cada uma das vogais
aparecem no arquivo (deve ser case insensitive e não precisa incluir vogais
acentuadas na contagem). Exemplo de arquivo de entrada:
Este eh um exemplo de arquivo de entrada.
O importante eh contar as vogais caso uma vogal nao apareca, exibir zero

Saída na tela (stdout):
a 14
e 13
i 5
o 10
u 3  */
#include <stdio.h>
#include <string.h>

int main()
{
    char nameArq[256];
    FILE *arq;
    int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;
    int c;

    printf("Informe o nome do arquivo:\n");
    fgets(nameArq, sizeof(nameArq), stdin);
    nameArq[strcspn(nameArq, "\n")] = '\0';

    arq = fopen(nameArq, "r");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        return 1;
    }

    while ((c = fgetc(arq)) != EOF)
    {
        switch (c)
        {
        case 'a':
        case 'A':
            countA++;
            break;
        case 'e':
        case 'E':
            countE++;
            break;
        case 'i':
        case 'I':
            countI++;
            break;
        case 'o':
        case 'O':
            countO++;
            break;
        case 'u':
        case 'U':
            countU++;
            break;
        }
    }

    printf("a %d\n", countA);
    printf("e %d\n", countE);
    printf("i %d\n", countI);
    printf("o %d\n", countO);
    printf("u %d\n", countU);
    fclose(arq);
    return 0;
}