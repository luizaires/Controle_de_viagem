#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grafo grafo;
typedef struct data data;
typedef struct carro carro;
typedef struct no no;
typedef struct viagem viagem;
carro *ford;
carro *jimy;
enum veiculo { FordK, Jimney } marca;
enum abragencia {
  PauDosFerros = 0,
  RafaelFernandes,
  SaoFranciscoDoOeste,
  Alexandria,
  SaoMiguel,
  vertices
};

struct grafo {
  int n_nos;
  int n_viagens;
  no **lista_adj;
};

struct data {
  int dia;
  int mes;
  int ano;
};

struct carro {
  enum veiculo marca;
  int km;
};

struct no {
  enum abragencia cidade;
  data data;
  int km_carro;
  no *destino;
};

struct viagem {
  carro *carro_viagem;
  no *origem;
  no *destino;
  int distancia;
};

grafo *criarGrafo(int vertices) {
  grafo *novoGrafo = malloc(sizeof(grafo));
  novoGrafo->n_nos = vertices;
  novoGrafo->lista_adj = malloc(vertices * sizeof(no *));
  memset(novoGrafo, 0, sizeof(no *));
  return novoGrafo;
}

void lerData(data *d) {
  printf("Dia: ");
  scanf("%d", &d->dia);
  printf("Mes: ");
  scanf("%d", &d->mes);
  printf("Ano: ");
  scanf("%d", &d->ano);
}

char *imprimirEnum(int id_cidade) {
  char *name;

  switch (id_cidade) {
  default:
    strcpy(name, "");
    break;
  case 0:
    strcpy(name, "Pau dos Ferros");
    break;
  case 1:
    strcpy(name, "Rafael Fernandes");
    break;
  case 2:
    strcpy(name, "São Francisco do Oeste");
    break;
  case 3:
    strcpy(name, "Alexandria");
    break;
  case 4:
    strcpy(name, "São Miguel");
    break;
  }
  return name;
}
void lerNo(no *ptr) {
  printf("Nome da cidade: ");
  char *nome;
  for (int i = 0; i < vertices; i++) {
    nome = imprimirEnum(i);
    printf("%d: %s", i, nome);
  }
  scanf("%d", &ptr->cidade);
  printf("Data:\n");
  lerData(&ptr->data);
  ptr->destino = NULL;
}

no *criarNo() {
  no *novoNo = malloc(sizeof(no));
  lerNo(novoNo);
  return novoNo;
}

void instanciarCarro(carro *ptrCarro, enum veiculo marca, int km_inicial) {
  ptrCarro->marca = marca;
  ptrCarro->km = km_inicial;
}

void inserirViagem(grafo *gptr) {
  viagem *ptrViagem = malloc(sizeof(viagem));
  enum veiculo marca;
  printf("Informe o veículo utilizado na viagem\n");
  scanf("%d", &marca);
  if (marca == FordK) {
    ptrViagem->carro_viagem = ford;
  }else{
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
void exibirGrafo(grafo *gptr);
void visualizarGrafo(grafo *gptr);

int main(void) {
  instanciarCarro(ford, 0, 20568);
  instanciarCarro(jimy, 1, 78043);
  return 0;
}