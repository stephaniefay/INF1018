#include <stdio.h>

int odd_ones(unsigned int x) { 
	int contador = 0;
	unsigned int buffer, temp;	
	temp = x;
	while ( temp ) {
		buffer = temp & 0xFF;
		if ( 0x00000001 & buffer)
			contador++;
		temp = temp >> 1;
	}

	if ( 0x00000001 & contador) 
		return 1;
	else
		return 0;
}

int main (void) {
	int verificador;
	unsigned int teste1 = 0x01010101;
	unsigned int teste2 = 0x01030101;
	verificador = odd_ones (teste1);

	if ( verificador > 0 )
		printf ( " O Valor %08x tem um valor impar de 1\n", teste1);
	else
		printf ( " O Valor %08x tem um valor par de 1\n", teste1);		

	verificador = odd_ones (teste2);

	if ( verificador > 0 )
		printf ( " O Valor %08x tem um valor impar de 1\n", teste2);
	else
		printf ( " O Valor %08x tem um valor par de 1\n", teste2);		

	return 0;
}
