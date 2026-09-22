// Campo de Batalha - O Ataque Perfeito: Em um jogo de estratégia por turnos, o jogador
// comanda um exército em um campo de batalha representado por um tabuleiro
// retangular de dimensões L x C, onde cada célula contém um número inteiro positivo
// representando o poder ofensivo acumulado das tropas inimigas posicionadas naquela
// região. Para planejar um ataque eficiente, o jogador pode escolher uma única zona de
// ataque retangular com dimensões M x N (ou seja, M linhas e N colunas), que
// representará a área em que suas forças lançarão uma ofensiva concentrada. As zonas
// de ataque são pré-definidas e não podem se sobrepor, ou seja, o campo de batalha é
// dividido logicamente em blocos M x N, e cada célula pertence a exatamente um desses
// blocos. O objetivo do jogador é maximizar o impacto do ataque, atingindo a maior soma
// possível de poder ofensivo inimigo dentro de um único bloco de M x N células.
//  Tarefa: Escreva um programa que, dado um mapa do campo de bataIha contendo o
// poder ofensivo das tropas inimigas em cada célula, determine quaI é o maior vaIor totaI
//  de poder ofensivo inimigo que pode ser atingido com um único ataque.
// • Entrada: A entrada contém um único conjunto de testes que deve ser Iido do
// dispositivo de entrada padrão. A primeira linha da entrada contém quatro
// números inteiros, L, C, M e N:
// § L e C representam respectivamente o número de linhas (L>=1) e de
// coIunas (C>=1) de céIuIas existentes no campo de bataIha. 
//§ M e N representam respectivamente o número de Iinhas (1<=M<=L)
// e de coIunas (1<=N<=C) das zonas de ataque. § O campo de batalha contém L*C inteiros, representando o poder de
// ataque das tropas inimigas em cada céIuIa. 
//• Saída: Seu programa deve imprimir na saída padrão uma única Iinha que
// contém o vaIor máximo de poder ofensivo das tropas inimigas que pode ser
// realizado em uma zona de ataque de MxN céIuIas. 
//Obs.: L/M e C/N são sempre inteiros (não há sobreposição das zonas de ataque).10

#include <stdio.h>
#include <stdlib.h>

int main(){
    int L,C,M,N;
    int **matriz;
    
    //sem as entradas de arquivo, descomente a linha acima para inserir os valores manualmente
    // printf("insira o Tamanho da linha e da Coluna e as valores de M e N: \n"); 
    if (scanf("%d %d %d %d", &L, &C, &M, &N) != 4) {
        printf("error - entrada invalida.\n");
        return -1;
    }
    
    if( L <= 0 || C <= 0 || M <= 0 || N <= 0 || L < M || C < N){
        printf("error - valores invalidos.\n");
        return -1;
    };

    matriz = (int **)malloc(L * sizeof(int *));
    if(!matriz){
        printf("error - memoria insuficiente.\n");
        return -1;
    };

    for (int i=0; i<L; i++){
        
        *(matriz + i) = (int *) malloc (C * sizeof (int));
        if (! (*(matriz + i))){
            printf ("Erro de alocacao de memoria\n");
            return -1;
        }
    }
    
    for (int i=0; i<L; i++){
        for (int j=0; j<C; j++){
            //sem as entradas de arquivo, descomente a linha acima para inserir os valores manualmente
            //printf("insira o valor da celula [%d][%d]: \n", i, j); 
            if (scanf("%d", (*(matriz + i) + j)) != 1) {
                printf("error - entrada invalida.\n");
                return -1;
            }
        };
    };

    int max_soma = 0;
    for ( int i = 0; i <= L - M; i += M) {
        for ( int j = 0; j <= C - N; j += N) {
            int soma = 0;
            for ( int k = 0; k < M; k++) {
                for ( int l = 0; l < N; l++) {
                    soma += *(*(matriz + i + k) + j + l);
                }
            }
            if (soma > max_soma) {
                max_soma = soma;
            }
        }
    }

    printf("%d", max_soma);
};


