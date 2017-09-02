/****************************************************************************/
/* O char sc é visto como 0xff (-1) pela máquina, então temos que passar de */
/* 4bytes para 8bytes, preenchendo os valores vazios com 1, para manter o   */
/* mesmo número. (Porque o número é negativo).                              */
/* Caso sc fosse positivo, os bits restantes seriam preenchidos com 0.      */
/****************************************************************************/


#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  signed char sc = -1;
  unsigned int ui = sc;

  printf("dump de sc: \n");
  dump(&sc, sizeof(sc));
  printf("dump de ui: \n");
  dump(&ui, sizeof(ui));
  printf("%x e %x\n",sc,ui);
  return 0;
}



