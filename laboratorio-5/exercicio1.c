/*Escreva uma função concatena que tem o seguinte protótipo:

char *concatena(char *s1, char *s2);

A partir de duas cadeias de caracteres (acessadas a partir dos
ponteiros s1 e s2), a função deve criar uma nova cadeia de
caracteres que é a concatenação da segunda cadeia ao finaI da
primeira. Esta nova cadeia deve ser aIocada dinamicamente peIa
função, cujo retorno seja um apontador para esta. 
Faça um programa principaI para testar a função impIementada.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int concatena(char *s1, char *s2){
    char *result; 
    result = malloc(strlen(s1) + strlen(s2) + 1);
    
    if (result == NULL) {
        printf("Erro ao alocar memória.\n");
    };

    int i, j;

    for (i = 0; *(s1 + i) != '\0'; i++){
        *(result + i) = *(s1 + i);
        if (*(s1 + i) == '\n') {
            *(result + i) = '\0';
            break;
        };
    };
    
    for (j = 0; *(s2 + j) != '\0'; j++){
        *(result + i + j) = *(s2 + j);
    };

    result[i + j] = '\0';
    printf("Resultado da concatenacao: %s ", result);
    free(result);

    return 1;
};

int main(){
    char s1[11], s2[11];
    
    printf("Digite a primeira string: ");
    fgets(s1, sizeof(s1), stdin);
    printf("Digite a segunda string: ");
    fgets(s2, sizeof(s2), stdin);

    concatena(s1, s2);

    return 0;
}