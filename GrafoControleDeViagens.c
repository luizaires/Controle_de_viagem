#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grafo grafo;
typedef struct data data;
typedef struct carro carro;
typedef struct no no;
typedef struct viagem viagem;
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
  carro carro_viagem;
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
  ptr->km_carro = 0;
  ptr->destino = NULL;
}

no *criarNo() {
  no *novoNo = malloc(sizeof(no));
  lerNo(novoNo);
  return novoNo;
}

void inserirViagem(grafo *ptr, enum veiculo carro, no origem, no destino);
viagem *buscarViagem(grafo *ptr, enum veiculo carro, no origem, no destino);
void deletarViagem(grafo *ptr, enum veiculo carro, no origem, no destino);
void exibirGrafo(grafo *ptr);
void visualizarGrafo(grafo *ptr);

int main(void) { return 0; }