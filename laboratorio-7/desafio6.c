/*Implemente as seguintes funções utilizadas no programa principal a seguir:

int grava(FILE *pFile, int N): armazena no arquivo binário (pFile)
informações de N pessoas (estrutura TPessoa), na mesma ordem de entrada. Retorna o número de registros efetivamente gravados no aquivo. int modifica(FILE *pFile, int M, int idade): substitui a idade da
M-ésima pessoa do arquivo binário (pFile) pelo valor de idade. A função deve
verificar se M está dentro do intervalo inteiro permitido (de 1 até a quantidade
de registros existentes no arquivo). Retorna M em caso de sucesso, -1 se o
intervalo informado for inválido ou zero no caso de outro erro qualquer
relacionado com a leitura ou a gravação no arquivo. void exibe(FILE *pFile): deve recuperar todos os registros de pessoas
(estrutura TPessoa) gravados no arquivo binário (pFile) e exibí-los na tela.
O programa principal deve funcionar sem nenhuma alteração
além da implementação das funções solicitadas. 
No caso das funções tipadas (grava e modifica), não
esqueça de verificar os resultados de retorno que indicam
erros, conforme pode ser observado a partir dos testes
presentes no programa principal.*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char nome[50];
    int idade;
} TPessoa;

int grava(FILE *pFile, int N){
    TPessoa pessoa;
    int i;

    for(i = 0; i<N ; i++){
        if((scanf("%49s", pessoa.nome)) != 1 || scanf("%d", &pessoa.idade) != 1){
            printf("Erro na leitura dos dados");
        }
        
        if((fwrite(&pessoa, sizeof(TPessoa) , 1 , pFile)) != 1){
            printf("Erro na escrita!\n");
        }
    };
    return N;
}

int modifica(FILE *pFile, int M, int idade){
    TPessoa pessoa;
    
    if (M<1) return -1;
    
    if((fseek(pFile, (M-1)*sizeof(TPessoa), SEEK_SET)) != 0 ){
        printf("Erro na procura\n");
    };
    
    if(fread(&pessoa,sizeof(TPessoa),1,pFile)!=1) {
        printf("Error na leitura\n");
    }
    pessoa.idade = idade;
    
    fseek(pFile,(M-1)*sizeof(TPessoa),SEEK_SET);
    
    if(fwrite(&pessoa,sizeof(TPessoa),1,pFile)!=1) { 
        printf("Erro na escrita!\n");
    }
    return 1;


}

void exibe(FILE *pFile){
    TPessoa pessoa;

    if((fseek(pFile, 0, SEEK_SET)) != 0){
        printf("Error no seek\n");
    };

    while(fread(&pessoa,sizeof(TPessoa),1,pFile)==1){
        printf("%s - %d\n",pessoa.nome,pessoa.idade);
    }
}

int main()
{
    FILE *pFile;
    int N, M, mod, idade;
    char nome_arquivo[100];
    fgets(nome_arquivo, 100, stdin);

    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';
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
    scanf("%d", &M);

    scanf("%d", &idade);

    mod = modifica(pFile, M, idade);

    if (mod == -1)
    {
        printf("Valor de M fora do intervalo permitido...");
        return -1;
    }

    if (mod == 0)
    {
        printf("Erro de leitura e/ou gravacao no arquivo...");
        return -1;
    }
    exibe(pFile);
    fclose(pFile);
    return 0;
}