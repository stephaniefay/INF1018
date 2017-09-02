#include <stdio.h>

int isPrio(unsigned int pacote) { 
	if ((pacote & 0x00001000) == 0x00001000)
		return 1;
	else
		return 0;
}

int getSeq(unsigned int pacote) {
	pacote = pacote << 1;
	pacote = pacote >> 28;
	return pacote;
}

unsigned int incrSeq(unsigned int pacote) {

}
	

int main() {

	unsigned int pacote1 = 0x7801E3A2;
	unsigned int pacote2 = 0x0801FBA2;
	unsigned int novopacote;
	
	printf("PrioPac\n");	
	printf("prio pac1 = %s\n", isPrio(pacote1) ? "S" : "N");
	printf("prio pac2 = %s\n", isPrio(pacote2) ? "S" : "N");
	printf("GetSeq\n");
	printf("%d \n", getSeq(pacote1));	
	printf("%d \n", getSeq(pacote2));
	
	return 0;
} 	
