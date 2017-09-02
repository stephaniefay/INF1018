#include <stdio.h>
#include <values.h>
#include "colecao.h"

int main(void) {
  void * aux, * aux2;
  int sum = 0, prod = 1, item;

  Colecao *ci1 = colecaoCria();
  Colecao *ci2 = colecaoCria();

  ci1 = colecaoInsere(ci1, 1);
  ci1 = colecaoInsere(ci1, 2);
  ci1 = colecaoInsere(ci1, 3);
  ci1 = colecaoInsere(ci1, 4);
  ci1 = colecaoInsere(ci1, 5);

  ci2 = colecaoInsere(ci2, 2);
  ci2 = colecaoInsere(ci2, 5);
  ci2 = colecaoInsere(ci2, 1);

  aux = criaIterador(ci1);

  while ((item = ativaIterador(aux)) != MININT) {
	
	sum += item;
  }
  destroiIterador(aux);

  printf("soma da colecao 1 = %d\n", sum);

  aux2 = criaIterador(ci2);

  while ((item = ativaIterador(aux2)) != MININT) {
	
	prod *= item;
  }
  destroiIterador(aux2);

  printf("produto da colecao 2 = %d\n", prod);

  colecaoLibera(ci1);
  colecaoLibera(ci2);

  return 0;
}


