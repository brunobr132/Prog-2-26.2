// Escreva um programa em C que recebe do usuário (entrada padrão) duas
// strings e verifica se a segunda é uma substring da primeira. As strings podem
// ser qualquer palavra ou frase. Para isso, faça o seguinte:
// 1. Crie uma função ocorrencia que recebe como argumentos duas strings e
// retorna um inteiro. Caso a segunda string seja uma substring da primeira, a
// função deverá retornar 1; zero caso contrário. A função deve garantir que a
// busca não seja sensível a letras maiúsculas e minúsculas (case insensitive). 
// 2. A função main do programa deve chamar a função ocorrencia para a
// verificação e imprimir o resultado na saída padrão. Exemplos:
// ENTRADA SAÍDA
// "Programacao de Computadores", "prog"        1
// "Programacao de Computadores", "Comp"        1
// "Padaria da esquina",          "padariaa"    0
// "Padaria da esquina",          "esq"         1
// "Teste de rererememorar",      "rerememorar" 1

#include <stdio.h>
#include <ctype.h>

int ocorrencia(char string1[51], char string2[51]){
    char temp1 [51],temp2[51];
    int i, j, k;

    for(i = 0; string1[i] != '\0'; i++){
        temp1[i] = tolower(string1[i]);

    };
    temp1[i] = '\0';

    printf("%s", temp1); //verificar se a string1 esta sendo passado para o diminutivo


    for(i = 0; string2[i] != '\0'; i++){
        temp2[i] = tolower(string2[i]);

    };
    temp2[i] = '\0';
    if (temp2[0] == '\0') return 1;

    printf("%s", temp2); //verificar se a string2 esta sendo passado para o diminutivo
    for(i = 0; temp1[i] != '\0'; i++){
        for (j = 0; temp2[j] != '\0'; j++){
            if(temp1[i+j] != temp2[j]){
                break;
            }
        }
        if (temp2[j] == '\0') {
            return 1;
        }
    }
    return 0;
};


int main(){
    char string1[51], string2[51];
    puts("Escreve uma frase:");
    fgets(string1, 51, stdin);
    for (i = 0; string1[i] != '\0'; i++) {
        if (string1[i] == '\n') {
            string1[i] = '\0';
            break;
        }
    }

    puts("Escreve uma palavra para ser encontrada na frase:");
    fgets(string2, 51, stdin);
    for (i = 0; string2[i] != '\0'; i++) {
        if (string2[i] == '\n') {
            string2[i] = '\0';
            break;
        }
    }

    printf("resultado: %d \n", ocorrencia(string1,string2));
}; 
