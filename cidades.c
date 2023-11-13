#include <string.h>
#include "cidades.h"

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
    strcpy(name, "Agua Nova");
    break;
  case 2:
    strcpy(name, "Alexandria");
    break;
  case 3:
    strcpy(name, "Almino Afonso");
    break;
  case 4:
    strcpy(name, "Antonio Martins");
    break;
  case 5:
    strcpy(name, "Coronel Joao Pessoa");
    break;
  case 6:
    strcpy(name, "Dr Severiano");
    break;
  case 7:
    strcpy(name, "Encanto");
    break;
  case 8:
    strcpy(name, "Francisco Dantas");
    break;
  case 9:
    strcpy(name, "Frutuoso Gomes");
    break;
  case 10:
    strcpy(name, "Joao Dias");
    break;
  case 11:
    strcpy(name, "Jose da Penha");
    break;
  case 12:
    strcpy(name, "Lucrecia");
    break;
  case 13:
    strcpy(name, "Luis Gomes");
    break;
  case 14:
    strcpy(name, "Major Sales");
    break;
  case 15:
    strcpy(name, "Marcelino Vieira");
    break;
  case 16:
    strcpy(name, "Martins");
    break;
  case 17:
    strcpy(name, "Parana");
    break;
  case 18:
    strcpy(name, "Piloes");
    break;
  case 19:
    strcpy(name, "Portalegre");
    break;
  case 20:
    strcpy(name, "Rafael Fernandes");
    break;
  case 21:
    strcpy(name, "Rafael Godeiro");
    break;
  case 22:
    strcpy(name, "Riacho da Cruz");
    break;
  case 23:
    strcpy(name, "Riacho de Santana");
    break;
  case 24:
    strcpy(name, "Sao Francisco do Oeste");
    break;
  case 25:
    strcpy(name, "Sao Miguel");
    break;
  case 26:
    strcpy(name, "Serrinha Dos Pintos");
    break;
  case 27:
    strcpy(name, "Taboleiro Grande");
    break;
  case 28:
    strcpy(name, "Tenente Ananias");
    break;
  case 29:
    strcpy(name, "Venha-ver");
    break;
  case 30:
    strcpy(name, "Vicosa");
    break;
  }
  return name;
}