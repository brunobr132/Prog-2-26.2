#include <stdio.h>

void misterio(char *n);

int main(void) {
    char nome[41];

    if (fgets(nome, sizeof(nome), stdin) != NULL) {
        misterio(nome);
    }

    return 0;
}

void misterio(char *n) {
    if (n == NULL) {
        return;
    }

    while (*n != '\0' && *n != ' ' && *n != '\n') {
        n++;
    }

    if (*n == ' ') {
        n++;
        while (*n != '\0' && *n != '\n') {
            putchar(*n);
            n++;
        }
    }

    putchar('\n');
}