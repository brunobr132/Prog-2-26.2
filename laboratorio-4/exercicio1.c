#include <stdio.h>
#include <string.h>

void misterio(const char *n);

int main(void) {
  char nome[41];
  char *nova_linha;

  if (fgets(nome, sizeof nome, stdin) == NULL) {
    fputs("Nao foi possivel ler o nome.\n", stderr);
    return 1;
  }

  nova_linha = strchr(nome, '\n');
  if (nova_linha != NULL) {
    *nova_linha = '\0';
  } else {
    int c = getchar();
    if (c != '\n' && c != EOF) {
      while ((c = getchar()) != '\n' && c != EOF) {
      }
      fputs("Nome muito longo (limite de 40 caracteres).\n", stderr);
      return 1;
    }
  }

  misterio(nome);
  return 0;
}

void misterio(const char *n) {
  while (*n != '\0' && *n != ' ') {
    n++;
  }

  if (*n == '\0') {
    fputs("Digite o primeiro e o ultimo nome separados por um espaco.\n",
          stderr);
    return;
  }

  puts(n + 1);
}