#include <stdio.h>

unsigned char switch_byte(unsigned char x) {
	unsigned char temp;
	temp = x >> 4;
	x = x << 4;
	x = x | temp;

	return x;
}

unsigned char rotate_left(unsigned char x, int n) {
	unsigned char temp;
	int contador = 8 - n;

	if ( n < 0 || n > 8 ) {
		printf ("numero invalido\n");
		return false;
	}

	temp = x >> contador;
	x = x << n;

	x = x | temp;

	return x;
}

int main (void) {

	unsigned int x = 0xAB;
	unsigned int y = 0x61;
	unsigned int z;

	printf (" Teste switch_byte \n ");

	printf (" %02x original\n", x);
	x = switch_byte(x);
	printf (" %02x invertido\n", x);

	printf ("\n Teste rotate_left \n");

	printf (" %02x original\n", y);
	z = rotate_left(y, 1);
	printf (" %02x invertido\n", z);		

	printf (" %02x original\n", y);
	z = rotate_left(y, 2);
	printf (" %02x invertido\n", z);		

	printf (" %02x original\n", y);
	z = rotate_left(y, 7);
	printf (" %02x invertido\n", z);		


	return 0;
}
