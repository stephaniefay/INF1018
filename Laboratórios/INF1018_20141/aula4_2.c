#include <stdio.h>

int odd_ones(unsigned int x) {
unsigned int buffer = 0x00000001;
int contador = 0;

for(;x;) {
	contador += (buffer&x);
	x = x >> 1;
	}
return (contador&0x01);
}

int main ( ) {

	unsigned int meh = 0x01010101;
	unsigned int buffer = 0;
	printf ("Numero %08x\n", meh);
	buffer = odd_ones (meh);
	if (buffer == 1)
		printf ("Numero eh impar\n");
	else 
		printf ("Numero eh par\n");

	meh = 0x01030101;
	printf ("Numero %08x\n", meh);
	buffer = odd_ones (meh);
	if (buffer == 1)
		printf ("Numero eh impar\n");
	else 
		printf ("Numero eh par\n");

return 0;
}
