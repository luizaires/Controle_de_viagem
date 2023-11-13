#include "data.h"
#include <stdio.h>

struct data {
  int dia;
  int mes;
  int ano;
};

void lerData(data *d) {
  printf("Dia: ");
  scanf("%d", &d->dia);
  printf("Mes: ");
  scanf("%d", &d->mes);
  printf("Ano: ");
  scanf("%d", &d->ano);
}
