/*Você foi contratado para escrever programas para auxiliar o treinamento dos maratonistas de um país que irão participar das
próximas Olimpíadas. 
Estes atletas treinam realizando corridas e medindo seus tempos. O treinamento constitui-se de uma série
de corridas realizadas durante diversos dias. Escreva um programa que, sabendo o número de atletas, o
número de corridas que eles fizeram e os tempos de cada corrida,
descubra qual atleta obteve o menor tempo total durante os
treinamentos. 
Os dados devem ser lidos de um arquivo texto de entrada cujo nome deve ser informado pelo usuário em tempo de execução.
Arquivo texto de entrada: A primeira linha do arquivo de entrada contém dois
inteiros A e C representando o número de atletas e o número de corridas, respectivamente.
Cada uma das A linhas seguintes contém o nome e os C
tempos obtidos por cada atleta nas corridas. Cada tempo é representado por 3
inteiros no formato h, m e s, separados por espaço. 
Mesmo se o tempo for igual a 0 (hora, minuto ou segundo), ele estará escrito
no arquivo. Garante-se que não haverá dois atletas que obtiveram o mesmo
tempo total para completar o treinamento e que os tempos fornecidos estarão
corretos e dentro do formato exigido (não precisa verificar). 
Saída: A saída, mostrada na tela, consiste do nome do atleta que obteve o menor tempo total e um número inteiro que corresponde ao valor em
s desse tempo total, seguindo a formatação apresentada nos exemplos de saída a seguir. 
Restrições: A > 0 e C > 0; os nomes dos atletas são compostos por, no máximo,
100 caracteres (apenas caracteres alfabéticos e/ou o caracter ‘_’) e não
contêm espaços em branco.*/

#include <stdio.h>

#define MAX_NOME 101
#define MAX_ARQUIVO 256

int main(void){
    int A, C;
    char nomeArquivo[MAX_ARQUIVO];
    char nome[MAX_NOME];
    char nomeMenor[MAX_NOME];
    FILE *arq;
    long long menorTempo = 0;

    if (scanf("%255s", nomeArquivo) != 1) {
        printf("Nome de arquivo invalido.\n");
        return 1;
    }

    arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro na abertura de arquivo.\n");
        return 1;
    }

    if (fscanf(arq, "%d %d", &A, &C) != 2 || A <= 0 || C <= 0) {
        printf("Numero de atletas ou de corridas invalidos.\n");
        fclose(arq);
        return 1;
    }

    for (int i = 0; i < A; i++) {
        long long tempoTotal = 0;

        if (fscanf(arq, "%100s", nome) != 1) {
            printf("Erro na leitura dos dados.\n");
            fclose(arq);
            return 1;
        }

        for (int j = 0; j < C; j++) {
            int h, m, s;

            if (fscanf(arq, "%d %d %d", &h, &m, &s) != 3) {
                printf("Erro na leitura dos dados.\n");
                fclose(arq);
                return 1;
            }

            tempoTotal += h * 3600LL + m * 60LL + s;
        }

        if (i == 0 || tempoTotal < menorTempo) {
            menorTempo = tempoTotal;
            snprintf(nomeMenor, sizeof(nomeMenor), "%s", nome);
        }
    }

    printf("%s %lld\n", nomeMenor, menorTempo);
    fclose(arq);
    return 0;
}
