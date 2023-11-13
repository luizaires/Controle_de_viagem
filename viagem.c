#include "viagem.h"
#include "carro.h"
#include "grafo.h"
#include "no.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct viagem {
  carro *carro_viagem;
  no *origem;
  no *destino;
  int distancia;
};

void inserirViagem(grafo *gptr) {
  viagem *ptrViagem = malloc(sizeof(viagem));
  enum veiculo marca;
  printf("Informe o veículo utilizado na viagem\n");
  scanf("%d", &marca);
  if (marca == FordK) {
    ptrViagem->carro_viagem = ford;
  } else {
    ptrViagem->carro_viagem = jimy;
  }
  printf("Informe os dados de origem:\n");
  ptrViagem->origem = criarNo();
  lerNo(ptrViagem->origem);
  ptrViagem->origem->km_carro = ptrViagem->carro_viagem->km;
  printf("Informe os dados de destino:\n");
  ptrViagem->destino = criarNo();
  lerNo(ptrViagem->destino);
  printf("Informe a quilometragem do carro no destino:\n");
  scanf("%d", &ptrViagem->destino->km_carro);
  ptrViagem->distancia =
      ptrViagem->destino->km_carro - ptrViagem->origem->km_carro;
  ptrViagem->carro_viagem->km = ptrViagem->destino->km_carro;
  gptr->lista_adj[gptr->n_viagens] = ptrViagem->origem;
  gptr->lista_adj[gptr->n_viagens]->destino = ptrViagem->destino;
  gptr->n_viagens++;
}

viagem *buscarViagem(grafo *gptr, enum veiculo carro, no origem, no destino);
void deletarViagem(grafo *gptr, enum veiculo carro, no origem, no destino);