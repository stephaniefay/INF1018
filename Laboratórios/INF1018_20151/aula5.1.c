#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
/*  int i,j;
  short a[2][3];
  int b[2];

  for (i=0;i<2;i++) {
    b[i] = i;
    for (j=0;j<3;j++)
      a[i][j] = 2+i-j;
  }*/
struct X {
  int a;
  int b;
  short c;
  int d;
} x = {0xa1a2a3a4, 0xb1b2b3b4, 0xc1c2, 0xd1d2d3d4};


/*  printf ("b: \n");
  dump (b, sizeof(b));
  printf ("a: \n");
  dump (a, sizeof(a));*/

printf ("X: \n");
dump (&x,sizeof(x));
printf ("%d", sizeof(x));


  return 0;
}
