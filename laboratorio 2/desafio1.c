#include <stdio.h>
#include <stddef.h>

struct packet{
    char c;
    int  i;
    short s;
    double  d;
};


int main(void){
    struct packet p = {'B', 07, 10, 3.14};

    char *base = (char*)&p;


    // A: o offset de cada campo, obtido pela diferença de endereços.
    long offset_c = (char*)&p.c - base;
    long offset_i = (char*)&p.i - base;
    long offset_s = (char*)&p.s - base;
    long offset_d = (char*)&p.d - base;

    // B: tamanho de cada campo.
    long size_c = sizeof(p.c);
    long size_i = sizeof(p.i);
    long size_s = sizeof(p.s);
    long size_d = sizeof(p.d);

    // C: A quantidade de paddin entre os campos
    long pad_c_i = offset_i - (offset_c + size_c);
    long pad_i_s = offset_s - (offset_i + size_i);
    long pad_s_d = offset_d - (offset_s + size_s);
    

    // D: O padding de cauda
    long tail_padding = sizeof(p) - (offset_d + size_d);

    // E: O total do padding
    long total_padding = sizeof(p) -(size_c + size_i + size_s + size_d);

    // Imprimir os resultados
    printf("--- Analise de memoria da struct Packet---\n");
    printf("Tamanho total da struct: %ld bytes\n\n", sizeof(p));

    printf("a. Offsets (deslocamento a partir do inicio):\n");
    printf("  Offset de c (char)  : %ld bytes\n", offset_c);
    printf("  Offset de i (int)   : %ld bytes\n", offset_i);
    printf("  Offset de s (short) : %ld bytes\n", offset_s);
    printf("  Offset de d (double): %ld bytes\n\n", offset_d);

    printf("b. Tamanhos dos campos:\n");
    printf("  Tamanho de c (char)  : %ld bytes\n", size_c);
    printf("  Tamanho de i (int)   : %ld bytes\n", size_i);
    printf("  Tamanho de s (short) : %ld bytes\n", size_s);
    printf("  Tamanho de d (double): %ld bytes\n\n", size_d);

    printf("c. Padding interno entre os campos:\n");
    printf("  Entre 'c' e 'i': %ld bytes\n", pad_c_i);
    printf("  Entre 'i' e 's': %ld bytes\n", pad_i_s);
    printf("  Entre 's' e 'd': %ld bytes\n\n", pad_s_d);

    printf("d. Padding de cauda (Tail padding):\n");
    printf("  No final da struct: %ld bytes\n\n", tail_padding);

    printf("e. Total de padding:\n");
    printf("  Soma dos paddings     : %ld bytes\n", (pad_c_i + pad_i_s + pad_s_d + tail_padding));
    printf("  Calculado (Total-Soma): %ld bytes\n", total_padding);

    return 0;
    
}