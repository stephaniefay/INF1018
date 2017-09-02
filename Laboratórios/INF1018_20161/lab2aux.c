#include <stdio.h> 
void mostra (unsigned char* p, int tam) { 
int i; 
for (i=0;i<tam;i++) 
printf("%02x\n", *p++); 
printf("\n"); 
} 
int main() {
int num = 0x01020304;
mostra((unsigned char*) &num, sizeof(int));
return 0;
}
