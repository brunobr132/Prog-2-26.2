// Implemente uma função chamada posicao, com o seguinte protótipo:
// int posicao(char *substr, char *str);
// Essa função deve verificar se a cadeia de caracteres apontada por substr está
// contida na cadeia apontada por str. Caso a substring ocorra dentro da string,
// a função deve retornar a posição (baseada em índice, começando de 0) onde
// se inicia a primeira ocorrência de substr em str. Se a substring não for
// encontrada, a função deve retornar -1. Requisitos:
// 1. A função deve retornar apenas a posição da primeira ocorrência, mesmo
// que a substring apareça mais de uma vez na string. 
// 2. Faça também um programa principal (main) que permita testar a função,
// lendo as duas strings do usuário e imprimindo o resultado da busca. 
//3. Não utilize a biblioteca <string.h> ou qualquer função pronta de busca. 
// A função deve ser implementada manualmente, usando apenas notação de
// ponteiros (sem colchetes [ ]).

#include <stdio.h>
#include <ctype.h>

int posicao(char *substr, char *str) {
    char *p, *q, *inicio;

    if (*substr == '\0')
        return 0;

    for (p = str; *p != '\0'; p++) {
        inicio = p;
        q = substr;

        while (*q != '\0' &&
               tolower(*p) == tolower(*q)) {
            p++;
            q++;
        }

        if (*q == '\0')
            return (int)(inicio - str);

        p = inicio;
    }

    return -1;
}

int main(void) {
    char str[101], substr[101];
    char *p;
    int resultado;

    printf("Digite a string principal: ");
    if (fgets(str, sizeof(str), stdin) == NULL)
        return 1;

    for (p = str; *p != '\0'; p++) {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
    }

    printf("Digite a substring: ");
    if (fgets(substr, sizeof(substr), stdin) == NULL)
        return 1;

    for (p = substr; *p != '\0'; p++) {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
    }

    resultado = posicao(substr, str);

    if (resultado == -1)
        printf("Resultado: -1\n");
    else
        printf("Resultado: %d\n", resultado);

    return 0;
}