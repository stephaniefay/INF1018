#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static unsigned char inicio[] = {0x55,0x89,0xe5};
static unsigned char fim[] = {0x89,0xec,0x5d,0xc3};
static unsigned char tempCall[100];
static unsigned char posParam [] = {0x08, 0x1c, 0x10, 0x14, 0x18};


const char ENDLINE = '\n';

typedef int (*funcp) ();

funcp geracod (FILE * f) {
	char buffer [100];
	fseek(f, SEEK_SET, 0);
	fscanf(f, "%s", buffer);
	while (buffer != NULL) {
		if(buffer[0]=='v' || buffer[0]=='p') {	//atribuicao
			printf("%s\n", buffer);
			while (fscanf(f, "%s", buffer)==1 && buffer[0] != ENDLINE) {
				printf("%s\n", buffer);
				
			}
			return;
		}
	}
}

void libera_func(void* func) {
	free(func);
}

int main () {
	FILE * f;
	char * nome;

	printf("Comeco funcao\n\n");
	scanf("%s", nome);

	f = fopen(nome, "r");
	if (f == NULL) {
		printf("Erro ao abrir arquivo!\n\n");
		return -1;
	}

	geracod(f);

	return 0;
}



