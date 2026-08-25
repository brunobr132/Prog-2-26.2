#include <stdio.h>

int main(void)
{
    int *p, x;
    int  i;
    p = &x;
    
    printf("Digita um numero inteiro: ");
    scanf("%d", &x);


    printf("O valor hexadecimal do valor é: %X\n", *p);

    for(i = 0; i < sizeof(x); i++){
        printf("%d\n",p);
        printf("%X\n",&p);
        p = p +1;
    }

    

}