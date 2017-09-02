#include <stdio.h>

#define makefloat(s,e,m) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((m) & 0x7fffff))
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getmant(x) ((x) & 0x7fffff)

typedef union { 
  float f;
  unsigned int i;
 } U;

float int2float(int i){
	int sinal = 0, temp, e = 0;
	unsigned int expoente, mantissa;
	U un;
	if(i == 0){
		return 0;
	}
	else if ( i < 0 ) {
		sinal = 1;
		i = -i;
	}

	temp = i;
	while (temp > 1) {
		temp = temp >> 1;
		e++;
	}

	expoente = e + 127;
	
	if ( e > 23 )
		mantissa = i >> (e - 23);
	else
		mantissa = i << (23 - e);

	un.i = makefloat (sinal,expoente,mantissa);

	return un.f;
}

int float2int (float f) {
	unsigned int mantissa, expoente, sinal, aux;
	int valor;
	U un;

	if (f > -1 && f < 1)
		return 0;

	aux = 0x1 << 23;
	un.f = f;
	mantissa = getmant(un.i) | aux;
	expoente = getexp(un.i) - 127;
	sinal = getsig(un.i);
	
	if ( expoente < 23 )
		mantissa = mantissa >> (23 - expoente);

	else
		mantissa = mantissa << (expoente - 23);

	if (sinal > 0)
		return -mantissa;
	else
		return mantissa;
	
}

