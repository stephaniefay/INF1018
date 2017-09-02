#include <stdio.h>

unsigned int mul (unsigned int a, unsigned int b) {
	unsigned int p = 0;
	while (b) {
		if (b & 0x01)
		p += a;
	a = a << 1;
	b = b >> 1;
	}
	return p;
}

int main ( ) { 
	printf (" ==> %d \n", mul(3,5));
	printf (" ==> %d \n", mul(4,8));
	printf (" ==> %d \n", mul(2,7));
	return 0;
}

