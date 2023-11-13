#include "no.h"
#include "cidades.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
  enum cidades cidade;
  // data dataViagem;
  int km_carro;
  no *destino;
};

void lerNo(no *ptr) {
  printf("Nome da cidade: ");
  char *nome;
  for (int i = 0; i < vertices; i++) {
    nome = imprimirEnum(i);
    printf("%d: %s", i, nome);
  }
  scanf("%d", &ptr->cidade);
  // printf("Data:\n");
  // lerData(&ptr->data);
  ptr->destino = NULL;
}

no *criarNo() {
  no *novoNo = malloc(sizeof(no));
  lerNo(novoNo);
  return novoNo;
}