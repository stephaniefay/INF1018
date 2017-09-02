#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned packed_t;

int string2num (char *s, int base) {
  int a = 0;
  for (; *s; s++) {
    if(isdigit(*s))
      a = a*base + (*s - '0');
    else if((*s >= 'A') && (*s < (base-10+'A')))
      a = a*base + ((*s - 'A') + 10);
    else if((*s >= 'a') && (*s < (base-10+'a')))
      a = a*base + ((*s - 'a') + 10);
    else {
      printf("pane: numero invalido! \n");
      exit(1);
    }
  }
  return a;
}

int xbyte (packed_t word, int bytenum) {
	unsigned int aux1, aux2;
	aux1 = (unsigned int)word;
	aux2 = (unsigned int)word;
	
	if (bytenum == 0) {
		aux1 = word << 24;
		aux1 = word >> 24;
	}
	else if (bytenum == 1) {
		aux1 = word << 16;
		aux1 = word >> 24;
	}
	else if (bytenum == 2) {
		aux1 = word << 8;
		aux1 = word >> 24;
	}
	else if (bytenum == 3) {
		aux1 = word >> 24;
	}
	else
		return -1;

	aux2 = aux1>>7;
	if (aux2 == 0)
		return aux1;
	else {
		aux1 = 0xffffffffffffffffffffffff00000000 + aux1;
		return aux1;
	}
}

int main (int argc, char **argv) {
  int x;
  if (argc != 3) {
    printf ("uso: %s <word (em hexadecimal)> <bytenum>\n", argv[0]);
    exit(1);
  }

  x = xbyte(string2num(argv[1], 16), atoi(argv[2]));
  printf ("%08x  %d\n", x, x);
  return 0;
}
