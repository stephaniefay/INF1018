#include <stdio.h>
#include <values.h>
#include "listainteiros.h"

int main(void) {

  int i;

  ListaInteiros *l1 = listaCria();
  ListaInteiros *l2 = listaCria();

  l1 = listaInsere(l1, 1);
  l1 = listaInsere(l1, 2);
  l1 = listaInsere(l1, 3);
  l1 = listaInsere(l1, 4);
  l1 = listaInsere(l1, 5);

  l2 = listaInsere(l2, 2);
  l2 = listaInsere(l2, 5);
  l2 = listaInsere(l2, 1);

  i = criaIterador (l1);

  i = ativaIterador (i);

  listaLibera(l1);
  listaLibera(l2);

  return 0;
}

