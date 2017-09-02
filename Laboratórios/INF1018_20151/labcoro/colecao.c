#include <stdlib.h>
#include <values.h>
#include "corotinas.h"
#include "colecao.h"

struct colecao {
  int info;
  struct colecao *prox;
};

Colecao *colecaoCria (void) {
  return NULL;
}

Colecao * colecaoInsere (Colecao *ci, int v) {
  Colecao *n = (Colecao *) malloc(sizeof(Colecao));
  if (n != NULL) {
    n->info = v;
    n->prox = ci;
  }
  return n;
}

void colecaoLibera(Colecao *ci) {
  Colecao *prox, *n = ci;
  while (n != NULL) {
    prox = n->prox;
    free(n);
    n = prox;
  }
}

/*
 * Corpo da corotina que implementa o iterador 
 */
static int iteraColecao (int colecao) {

  /* Guarda a colecao que deve ser "iterada" */
  Colecao *ci = (Colecao *) colecao;
  coro_yield (0);

  while ( ci!=NULL ) {
    coro_yield(ci->info);
    ci = ci->prox;
  }

  return MININT;
}

void *criaIterador (Colecao *ci) {
	Coroutine c = coro_create("iterador", iteraColecao);
	coro_resume(c,(int)ci);
	return c;
}

int ativaIterador (void *iterador) {  

  return coro_resume ((Coroutine) iterador, 0);
}

void destroiIterador (void *iterador) {
  coro_free(iterador);
}
