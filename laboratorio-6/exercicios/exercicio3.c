// Faça um programa que recebe como entrada o nome de um arquivo texto e o
// nome de um arquivo de saída. Esses dados devem vir da chamada do programa
// (via linha de comando). Cada Iinha do arquivo de entrada possui até 200
// caracteres. No arquivo de saída, deverá ser escrito o arquivo de entrada com o
// conteúdo de cada Iinha na ordem inversa. Veja um exemplo:

// Arquivo de entrada:
// Hoje eh dia de prova de Prog 2
// A prova esta facil
// Vou tirar uma boa nota

// Arquivo de saída:
// 2 gorP ed avorp ed aid he ejoH
// licaf atse avorp A
// aton aob amu rarit uoV

#include <stdio.h>
#include <string.h>

int main(){
    char nameArq[256], nameArqOut[256];
    FILE *arq;

    printf("Informe o nome do arquivo de entrada:\n");
    fgets(nameArq, sizeof(nameArq), stdin);
    nameArq[strcspn(nameArq, "\r\n")] = '\0';

    printf("Informe o nome do arquivo de saída:\n");
    fgets(nameArqOut, sizeof(nameArqOut), stdin);
    nameArqOut[strcspn(nameArqOut, "\r\n")] = '\0';

    arq = fopen(nameArq, "r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo.\n");
        return 1;
    }

    FILE *arqOut = fopen(nameArqOut, "w");
    if(arqOut == NULL){
        printf("Erro na abertura do arquivo de saida.\n");
        return 1;
    }

    char linha[201];
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        // Remove o caractere de nova linha, se presente
        int len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') {
            linha[len - 1] = '\0';
            len--;
        }
        
        // Escreve a linha invertida no arquivo de saída
        for (int i = len - 1; i >= 0; i--) {
            fputc(linha[i], arqOut);
        }
        fputc('\n', arqOut);
    }

    fclose(arq);
    fclose(arqOut);
    return 0;
}