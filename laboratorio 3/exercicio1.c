/*ImpIemente, em C, uma função que recebe dois
parâmetros: o salário atuaI de uma pessoa (por
referência) e o percentuaI de aumento (por
vaIor). A função deve alterar o valor do salário
acrescentando o percentual correspondente de
aumento. Mostre como a função poderia ser
chamada a partir da função main.*/

#include <stdio.h>

void aumentar_salario(float *salario, float percentual) {
    *salario += (*salario * percentual / 100);
}

int main() {
    float salario, percentual;
    
    printf("Digite o salário atual: ");
    scanf("%f", &salario);
    
    printf("Digite o percentual de aumento: ");
    scanf("%f", &percentual);
    
    aumentar_salario(&salario, percentual);
    
    printf("Salário após aumento: %.2f\n", salario);
    
    return 0;
}