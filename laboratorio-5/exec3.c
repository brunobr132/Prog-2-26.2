#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct _func
{
    char nome[40];
    int ano_nasc;
    float renda;
}
Tfunc;

void *inicializa(Tfunc *cadastro, int funcionarios){
    int i;
    cadastro = malloc(funcionarios * sizeof(Tfunc));
    for (i = 0; i < funcionarios; i++){
        printf("Funcionario %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", cadastro[i].nome);
        printf("Ano de nascimento: ");
        scanf("%d", &cadastro[i].ano_nasc);
        printf("Renda: ");
        scanf("%f", &cadastro[i].renda);
    }
    return cadastro;
};

void *inclui_novos(Tfunc *cadastro, int funcionarios, int adicionais){
    int i;
    cadastro = realloc(cadastro, (funcionarios + adicionais) * sizeof(Tfunc));
    for (i = funcionarios; i < funcionarios + adicionais; i++){
        printf("Funcionario %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", cadastro[i].nome);
        printf("Ano de nascimento: ");
        scanf("%d", &cadastro[i].ano_nasc);
        printf("Renda: ");
        scanf("%f", &cadastro[i].renda);
    }
    return cadastro;
};
void imprime(Tfunc *cadastro, int funcionarios, int adicionais){
    for (int i = 0; i < funcionarios + adicionais; i++){
        printf("Funcionario %d\n", i + 1);
        printf("Nome: %s\n", cadastro[i].nome);
        printf("Ano de nascimento: %d\n", cadastro[i].ano_nasc);
        printf("Renda: %.2f\n", cadastro[i].renda);
    }
}
int main(void)
{
    Tfunc *cadastro;
    int funcionarios, adicionais;
    printf("Quantos funcionarios? ");
    scanf("%d", &funcionarios);
    cadastro = inicializa(cadastro, funcionarios);
    if (!cadastro)
        return -1;
    printf("Quantos funcionarios a mais deseja adicionar? ");
    scanf("%d", &adicionais);
    cadastro = inclui_novos(cadastro, funcionarios, adicionais);
    if (!cadastro)
        return -1;
    printf("Lista de funcionarios cadastrados\n");
    imprime(cadastro, 0, funcionarios + adicionais);
    free(cadastro);
    return 0;
}