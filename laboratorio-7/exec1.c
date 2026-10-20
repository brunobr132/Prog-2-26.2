/*Implemente as funções utilizadas no programa principal a seguir:

● int grava(FILE *pFile, int N): armazena no arquivo
binário (pFile) valores inteiros de 1 até N, em ordem
decrescente, e retorna o número de valores efetivamente
gravados.
● int* recupera(FILE *pFile): retorna um ponteiro para
uma região de memória alocada dinamicamente, onde são
armazenados todos os dados recuperados a partir do arquivo
através de uma única chamada da função fread (todos os N
inteiros armazenados no arquivo).
● void exibe_vetor(int *vetor, int N): exibe na tela
todos os N inteiros armazenados no vetor. 2
● int modifica(FILE *pFile, int M): verifica os
últimos M inteiros armazenados no arquivo e, dentre estes,
substitui (no mesmo arquivo) os inteiros que forem pares
pelos seus dobros. O intervalo permitido para M é (0,N]. Retorna M em caso de sucesso, -1 se o intervalo informado
for inválido ou zero no caso de outro erro qualquer. ●
 void recupera_exibe(FILE *pFile): deve recuperar
todos os números gravados no arquivo e exibí-los na tela. No caso das funções tipadas, não esqueça de verificar os
resultados de retorno que indicam erros, conforme pode ser
observado a partir dos testes presentes no programa principal.*/
#include <stdio.h>
#include <stdlib.h>

int grava(FILE *pFile, int N){
    for(int i = N; i >= 1; i--){
        fwrite(&i, sizeof(int), 1, pFile);
    };
    return N;
}
int* recupera(FILE *pFile){
    fseek(pFile, 0, SEEK_END);
    int N = ftell(pFile) / sizeof(int);
    rewind(pFile);
    int *vetor = (int*)malloc(N * sizeof(int));
    if(vetor == NULL){
        return NULL;
    }
    fread(vetor, sizeof(int), N, pFile);
    return vetor;
}

int main()
{
    FILE *pFile;
    int i, N, M, num, mod, *vetor;
    char nome_arquivo[100];
    printf("Informe o nome do arquivo a ser criado: ");
    gets(nome_arquivo);
    printf("Informe um numero positivo: ");
    scanf("%d", &N);
    pFile = fopen(nome_arquivo, "wb+");
    if (!pFile)
    {
        printf("Erro na criacao do arquivo...");
        return -1;
    }
    if (grava(pFile, N) != N)
    {
        printf("Erro na gravacao do arquivo...");
        return -1;
    }
    vetor = recupera(pFile);
    if (vetor == NULL)
    {
        printf("Erro na recuperacao de dados do arquivo...");
        return -1;
    }
    exibe_vetor(vetor, N);
    printf("Informe um numero positivo M correspondente a quantidade de valores apartir do final do arquivo que deseja alterar:");

    scanf("%d", &M);
    mod = modifica(pFile, M);
    if (mod == -1)
    {
        printf("Valor de M fora do intervalo permitido...");
        return -1;
    }
    if (mod != M)
    {
        printf("Erro de leitura e/ou gravacao no arquivo...");
        return -1;
    }
    recupera_exibe(pFile);
    fclose(pFile);
    return 0;
}