/*Os alunos de uma turma de Programação de Computadores II
fizeram três avaliações: duas provas e um trabalho. Escreva um
programa que leia do teclado o nome e as três notas de cada
aluno dessa turma nas avaliações e os grave em um arquivo texto
na seguinte ordem: nome do aluno, nota da primeira prova (P1),
nota da segunda prova (P2) e nota do trabalho (T). O arquivo
deverá armazenar os dados de cada aluno em uma linha do
arquivo. O número de alunos da turma, bem como o nome do
arquivo de saída, deverão ser solicitados ao usuário. Em seguida,
abra o arquivo criado usando um editor de textos qualquer e
verifique o resultado do programa.*/
#include <stdio.h>

int main(){
    int numAlunos;
    char nomeArquivo[256];
    FILE *arq;

    printf("Informe o numero de alunos:\n");
    scanf("%d", &numAlunos);
    getchar(); // Limpar o buffer do teclado

    printf("Informe o nome do arquivo de saida:\n");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    arq = fopen(nomeArquivo, "w");
    if(arq == NULL){
        printf("Erro na abertura do arquivo.\n");
        return 1;
    }

    for(int i = 0; i < numAlunos; i++){
        char nome[100];
        float p1, p2, t;

        printf("Informe o nome do aluno %d:\n", i + 1);
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        printf("Informe a nota da primeira prova (P1):\n");
        scanf("%f", &p1);
        printf("Informe a nota da segunda prova (P2):\n");
        scanf("%f", &p2);
        printf("Informe a nota do trabalho (T):\n");
        scanf("%f", &t);
        getchar(); // Limpar o buffer do teclado

        fprintf(arq, "%s %.2f %.2f %.2f\n", nome, p1, p2, t);
    }

    fclose(arq);
    printf("Dados gravados com sucesso no arquivo %s.\n", nomeArquivo);

    return 0;
}