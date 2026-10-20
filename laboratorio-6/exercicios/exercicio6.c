/*Escreva um programa que calcule e informe o
número de vezes que uma determinada palavra
aparece em um arquivo texto. Para testar seu
programa, crie um arquivo em um editor de textos
qualquer. Solicite ao usuário o nome do arquivo a ser
utilizado e a palavra a ser buscada. A busca deve ser
case insensitive (sem diferenciação entre maiúsculas
e minúsculas). 
● Para simplificar, considere que o arquivo texto não
conterá nenhum tipo de pontuação.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char nomeArquivo[100];
    char palavra[100];
    FILE *arquivo;
    char buffer[1000];
    int contador = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    printf("Digite a palavra a ser buscada: ");
    scanf("%s", palavra);

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fscanf(arquivo, "%s", buffer) != EOF) {
        // Convertendo para minúsculas para busca case insensitive
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }
        for (int i = 0; palavra[i]; i++) {
            palavra[i] = tolower(palavra[i]);
        }

        if (strcmp(buffer, palavra) == 0) {
            contador++;
        }
    }

    fclose(arquivo);

    printf("A palavra '%s' aparece %d vezes no arquivo '%s'.\n", palavra, contador, nomeArquivo);

    return 0;
}