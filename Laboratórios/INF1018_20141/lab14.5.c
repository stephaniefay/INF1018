#include <stdio.h>

unsigned char codigo [] = {0x55, 0x89, 0xe5, 0xff, 0x75, 0x08, 0xe8, 0xfc, 0xff, 0xff, 0xff, 0x89, 0xec, 0x5d, 0xc3};

typedef int (*funcp) (int x);

int add (int x) {
	return x+1;
}

int main (void) {
	int i = 0;
	unsigned int aux;
	
	aux = (unsigned int)add - (unsigned int)(&codigo[11]);

	codigo[10] = (aux>>24) & 0xff;
	codigo[9] = (aux>>16) & 0xff;
	codigo[8] = (aux>>8) & 0xff;
	codigo[7] = aux & 0xff;

	funcp f = (funcp)codigo;
	i = (*f)(10);

	printf("%d\n", i);

	return 0;
}
