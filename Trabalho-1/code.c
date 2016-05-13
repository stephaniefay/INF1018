/* Stephanie Fay 1121598 */

#include "code.h"
#include <string.h>

typedef unsigned char BYTE;

int mostra_int (FILE *f, BYTE * aux) {
	int nbyte = 0;
	int result;
	unsigned int val = 0;
	BYTE byte;


	do {
		if (fread(&byte, 1, 1, f) != 1){
			*aux = -1;
			break;
		}

		val |= ((unsigned int) (byte & 0x7f)) << (nbyte * 7);
		nbyte++;
	} 
	while (byte & 0x80);
	
	result = val >> 1;
	if (val == 1)
		result = -1;	
	else if (val % 2 != 0) {
		result = -result - 1;
	}

	return 0;
}

int mostra_long (FILE *f, BYTE * aux) {
	int nbyte = 0;
	long result;
	unsigned long val = 0;
	BYTE byte;


	do {
		if (fread(&byte, 1, 1, f) != 1){
			*aux = -1;
			break;
		}

		val |= ((unsigned int) (byte & 0x7f)) << (nbyte * 7);
		nbyte++;
	} 
	while (byte & 0x80);
	
	result = val >> 1;
	if (val == 1)
		result = -1;	
	else if (val % 2 != 0) {
		result = -result - 1;
	}

	return 0;
}


int decode (FILE *f) {
	BYTE chave = 0;

	while (fread(&chave, 1, 1, f) == 1) {

		if (chave == -1)
			return 0;

		else if ((chave == 0x81) || (chave == 0x01)) {
			if (mostra_int(f, &chave) == -1) 
				return -1;
		}
		else if (chave == 0x82 || (chave == 0x02)) {
			if (mostra_long(f, &chave) == -1) 
				return -1;
		}
	}
	return 0;
}

int code_inteiro (int aux, int numcampos, FILE *fp, int *pad) {
	unsigned char aux2[3];
	int i = 0;
	unsigned int zigzag;

	zigzag = aux << 1;
  	if (aux < 0)
		zigzag = ~zigzag;

	if (numcampos > 1)
		fputc(0x81,fp);
	else 
		fputc(0x01,fp);

	do {
		aux2[i] = zigzag & 0x7ff;
		zigzag >>= 7;
		i++;
	} 
	while(zigzag);

	if(fwrite(aux2, sizeof(char), i, fp) != i)
		return -1;

	*pad = sizeof(int);
	return 0;
}

int code_long (long aux, int numcampos, FILE *fp, int *pad) {
	unsigned char aux2[7];
	int i = 0;
	unsigned long zigzag;

	zigzag = aux << 1;
  	if (aux < 0)
		zigzag = ~zigzag;

	if (numcampos > 1)
		fputc(0x82,fp);
	else 
		fputc(0x02,fp);

	do {
		aux2[i] = zigzag & 0x7ff;
		zigzag >>= 7;
		i++;
	} 
	while(zigzag);

	if(fwrite(aux2, sizeof(char), i, fp) != i)
		return -1;

	*pad = sizeof(long);
	return 0;
}

int code (char *desc, void* v, FILE *f) {
	int pad;
	int padtot = 0;
	int numcampos = strlen(desc);
	int condInt = 0; int condLong = 0;
	int i = 0; long j = 0;
	int padding;
	fputc(0xff,f);
	while(*desc != '\0') {
		if(*desc == 'i') {
			condInt = (padtot % sizeof(int));
			if(condInt > 0) {
				 padding = sizeof(int) - condInt;
				 padtot = padtot + padding;
				 v = v + padding;
			}

			i = (*(int*)v);
			if(code_inteiro(i, numcampos, f, &pad) == -1)
				return -1;
		}
		else if(*desc == 'l') {
			condLong = (padtot % sizeof(long));
			if(condLong > 0) {
				padding = sizeof(long) - condLong;
				padtot = padtot + padding;
				v = v + padding;
			}
			j = (*(long*)v);
			if(code_long(j, numcampos, f, &pad) == -1)
				return -1;
		}

		v = v + pad;
		padtot = padtot + pad;

		desc++;
		numcampos--;
	}
	return 0;
}
