#include "carro.h"

struct carro {
  enum veiculo marca;
  int km;
};

void instanciarCarro(carro* ptrCarro, enum veiculo marca, int km_inicial) {
  ptrCarro->marca = marca;
  ptrCarro->km = km_inicial;
}