#include <stdio.h> 
#include <stdlib.h>

int closest_to_mean_index( int v[], int n){
    int i; 
    int *p;
    int soma = 0;
    int media ;
    int index = 0;
    int menor;
    if (n == 0 || n > 100){
        printf("Quantidade de elementos invalida\n");
        return -1;
    } 
        
    // calcula a soma dos elementos do vetor atraves do ponteiro
    for (i = 0, p = v; i < n; i++, p++){
        soma += *p;
        //printf("%d ", *p); teste para exibir os valores do vetor
            
    };
    media = soma/n;
    //printf("media: %d\n", media); 
    //teste para exebir a media

    // percorre o vetor para encontrar o indice do elemento com a menor diferença absoluta para a média
    for( i = 0, p = v; i < n; i++, p++){
        if (i == 0){
            menor = *p;
            index = i;
        } else {
            if (abs(*p - media) < abs(menor - media)){
                menor = *p;
                index = i;
            }
        };
    };
        
    return index;
};

int main() {
    int n, i;
    int v[100];
    int *p;

    puts("Digite a quantidade de numeros:");
    scanf("%d", &n);
    
    // print abaixo para visualizar a quantidade de numeros digitados atraves de entrada de um arquivo.
    //printf("Quantidade de numeros: %d\n", n); 
    
    puts("Digite os numeros:");
    for (i = 0, p = v; i < n; i++, p++) {
        scanf("%d", p);
        
        //dois print abaixo para visualizar os numeros digitados no vetor atraves de entrada de um arquivo.
        //printf("Numeros no vetor v[%d]:", i);
        //printf(" %d\n", *p);
    }
    
    printf("%d", closest_to_mean_index(v, n));
    return 0;
}