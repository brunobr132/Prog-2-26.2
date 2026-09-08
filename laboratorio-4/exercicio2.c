#include <stdio.h>
#define DIM 3

void inicM(int s[][DIM]){
    int i, j;
    for(i=0; i<DIM; i++){
        for (j=0; j<DIM;j++){
            s[i][j] = 0;
        }
    }
}

void mostraM (int s[DIM][DIM]){
    int i, j;
    for (i=0; i<DIM; i++){
        for (j=0; j<DIM; j++){
            printf("%d ", s[i][j]);
        } printf("\n");
    }
}

void  incluiElem(int s[DIM][DIM], int i, int j, int num){
    if (i>=0 && i<DIM && j>=0 && j<DIM){
        s[i][j] = num;
    } else {
        printf("Posicao invalida\n");
    } printf("elemento incluido com sucesso\n");
    for (i=0; i<DIM; i++){
        for (j=0; j<DIM; j++){
            printf("%d ", s[i][j]);
        } printf("\n");
    }
}

int main(){
    int s[DIM][DIM];
    inicM(s);
    mostraM(s);
    incluiElem(s, 2, 2, 10);
    return 0;
}