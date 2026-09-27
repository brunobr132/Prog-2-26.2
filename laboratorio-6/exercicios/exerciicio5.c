/*Escreva um programa que leia do arquivo gerado no
exercício anterior (os nomes e as três notas dos alunos). O seu programa deve calcular a média de cada aluno
considerando a seguinte equação:
média=(((P1+P2)/2)*0.8)+(T*0.2). Seu
programa deverá gravar em um outro arquivo: o nome
de cada aluno e sua respectiva média (uma linha para
cada aluno). Os nomes dos arquivos de entrada e saída
devem ser informados pelo usuário. Em seguida, abra o
arquivo criado usando um editor de textos qualquer e
verifique o resultado do programa.*/
#include <stdio.h>

int main(){
    char nameArqIn[256], nameArqOut[256];
    FILE *arqIn, *arqOut;
    char nome[100];
    float p1, p2, t, media;

    printf("Informe o nome do arquivo de entrada:\n");
    fgets(nameArqIn, sizeof(nameArqIn), stdin);
    nameArqIn[strcspn(nameArqIn, "\n")] = '\0';

    printf("Informe o nome do arquivo de saída:\n");
    fgets(nameArqOut, sizeof(nameArqOut), stdin);
    nameArqOut[strcspn(nameArqOut, "\n")] = '\0';

    arqIn = fopen(nameArqIn, "r");
    if(arqIn == NULL){
        printf("Erro na abertura do arquivo de entrada.\n");
        return 1;
    }

    arqOut = fopen(nameArqOut, "w");
    if(arqOut == NULL){
        printf("Erro na abertura do arquivo de saída.\n");
        fclose(arqIn);
        return 1;
    }

    while(fscanf(arqIn, "%99s %f %f %f", nome, &p1, &p2, &t) == 4){
        media = (((p1 + p2) / 2) * 0.8) + (t * 0.2);
        fprintf(arqOut, "%s %.2f\n", nome, media);
    }

    fclose(arqIn);
    fclose(arqOut);

    printf("Médias calculadas e gravadas no arquivo %s com sucesso.\n", nameArqOut);

    return 0;
}