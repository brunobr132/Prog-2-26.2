/*Você foi contratado para escrever programas para auxiliar o treinamento dos maratonistas de um país que irão participar das
próximas Olimpíadas. 
Estes atletas treinam realizando corridas e medindo seus tempos. O treinamento constitui-se de uma série
de corridas realizadas durante diversos dias. Escreva um programa que, sabendo o número de atletas, o
número de corridas que eles fizeram e os tempos de cada corrida,
descubra qual atleta obteve o menor tempo total durante os
treinamentos. 
Os dados devem ser lidos de um arquivo texto de entrada cujo nome deve ser informado pelo usuário em tempo de execução.
Arquivo texto de entrada: A primeira linha do arquivo de entrada contém dois
inteiros A e C representando o número de atletas e o número de corridas, respectivamente.
Cada uma das A linhas seguintes contém o nome e os C
tempos obtidos por cada atleta nas corridas. Cada tempo é representado por 3
inteiros no formato horas, minutos e segundos, separados por espaço. 
Mesmo se o tempo for igual a 0 (hora, minuto ou segundo), ele estará escrito
no arquivo. Garante-se que não haverá dois atletas que obtiveram o mesmo
tempo total para completar o treinamento e que os tempos fornecidos estarão
corretos e dentro do formato exigido (não precisa verificar). 
Saída: A saída, mostrada na tela, consiste do nome do atleta que obteve o menor tempo total e um número inteiro que corresponde ao valor em
segundos desse tempo total, seguindo a formatação apresentada nos exemplos de saída a seguir. 
Restrições: A > 0 e C > 0; os nomes dos atletas são compostos por, no máximo,
100 caracteres (apenas caracteres alfabéticos e/ou o caracter ‘_’) e não
contêm espaços em branco.*/

#include <stdio.h>
#define MAX 100 

int main(){
    int A, C, H, M, S;
    FILE *arq;
    char nome[MAX];


    if(!(arq = fopen("/home/convidado/Documentos/Prog-2-26.2/laboratorio-6/entrada2.txt","r"))) //modificar depois com diretorio certo
        printf("Erro na abertura de arquivo.");

    else{
        fscanf(arq, "%d %d", A , C );
        if( A<= 0 || C<= 0){
            printf("Numero de atletas ou de corridas invalidos(Atletas > 0 ou Corridas > 0).");
        }
        
        // fscanf(arq,);
    };
}
