/*Faça um programa que recebe como entrada o nome de um arquivo texto e o
nome de um arquivo de saída. Esses dados devem vir da chamada do programa
(via linha de comando). No arquivo de saida, deverá ser escrito o arquivo de
entrada com os caracteres em maiúsculo. veja o exemplo a seguir:

Arquivo de entrada:
Hoje eh dia de prova de Prog 2
A prova esta facil
Vou tirar uma boa nota

Arquivo de saída:
HOJE EH DIA DE PROVA DE PROG 2
A PROVA ESTA FACIL
VOU TIRAR UMA BOA NOTA*/
#include <stdio.h>
#include <ctype.h>

int main(){
    char nameArq[256], nameArqOut[256];
    FILE *arq;

    printf("Informe o nome do arquivo de entrada:\n");
    fgets(nameArq, sizeof(nameArq), stdin);

    printf("Informe o nome do arquivo de saída:\n");
    fgets(nameArqOut, sizeof(nameArqOut), stdin);
    nameArq[strcspn(nameArq, "\n")] = '\0';
    nameArqOut[strcspn(nameArqOut, "\n")] = '\0';

    arq = fopen(nameArq, "r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo.\n");
        return 1;
    }

    FILE *arqOut = fopen(nameArqOut, "w");
    if(arqOut == NULL){
        printf("Erro na abertura do arquivo.\n");
        return 1;
    }

    int c;
    while((c = fgetc(arq)) != EOF){
        fputc(toupper(c), arqOut);
    }

    fclose(arq);
    fclose(arqOut);
    printf("Arquivo convertido para maiúsculo e salvo em %s\n", nameArqOut);

    return 0;
}