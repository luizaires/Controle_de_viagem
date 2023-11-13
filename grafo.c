#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "no.h"

struct grafo {
  int n_nos;
  int n_viagens;
  no **lista_adj;
};

grafo *criarGrafo(int vertices) {
  grafo *novoGrafo = malloc(sizeof(grafo));
  novoGrafo->n_nos = vertices;
  novoGrafo->lista_adj = malloc(vertices * sizeof(no *));
  memset(novoGrafo, 0, sizeof(no *));
  return novoGrafo;
}

void exibirGrafo(grafo *gptr);
void visualizarGrafo(grafo *gptr);
