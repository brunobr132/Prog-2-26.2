#include <stdio.h>

void buscaMenorMaiorBin(int arr[], int tam, int el, int *menor, int *maior)
{
    int fim = tam - 1;
    int ini = 0;
    while (ini <= fim)
    {
        int meio = (fim + ini) / 2;
        if (arr[meio] < el){
            ini = meio + 1;
            *menor = ini;
        }
        else
        {
            if (arr[meio] > el){
                fim = meio - 1;
                *maior += 1;
            }
            else
                return meio;
        }
    } return -1;
}

int main(){
    int *arr;
    int tam, el;
    int *menor; 
    int *maior;
    int n;

    printf("digita o tamanho do array.");
    scanf("%d", &tam);
    
    printf("digita o numero que verificar a quantidade de menores que ele e maiores que ele.");
    scanf("%d", &el);
    
    arr = (int*) malloc(tam*sizeof(int));
    
    for(int i = 0; i < arr; i++){

        printf("digita os numeros do array");
        scanf("%d", &n);
    }
    
    buscaMenorMaiorBin(arr,tam,el,menor,maior);

}