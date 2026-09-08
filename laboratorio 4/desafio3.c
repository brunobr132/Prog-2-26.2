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

int posicao(char *substr, char *str){
    int i,j;
    char *temp1[101], *temp2[101];

    for(i = 0; *(substr+i) != '\0'; i++ ){
        
        *(temp1+i) = tolower(*(substr+i));
        printf("%d\n", *(temp1+i));
    }; *(temp1+i) = '\0';
    

    for(i = 0; str[i] != '\0'; i++ ){
        str[i] == tolower(str[i]);
    }; str[i] = '\0';

    if (str[0] = '\0'){
        printf("ERROR: string principal invalida.");
        return 1;
    }

};

int main(){
    int i ;
    char *substr[101], *str[101];
    
    puts("Escreve uma frase:");
    fgets(str, 101, stdin);
    for (i = 0; str+i != '\0'; i++) {
        if (str+i == '\n') {
            str+i == '\0';
            break;
        }
    }
    puts("Escreve uma palavra para ser encontrada na frase:");
    fgets(*substr, 101, stdin);
    for ( i = 0; *(substr+i) != '\0'; i++) {
        if (*(substr+i) == '\n') {
            *(substr+i) = '\0';
            break;
        }
    }

    printf("resultado: %s, %s \n", posicao(*substr, *str));
}