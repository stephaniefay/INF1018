#include <ctype.h>
#include <stdio.h>  


void num2string(char *s, int num, int base){
   if (base < 2 || base > 16)
	return;
   
}

int main (void) {
  char * s = " ";
  num2string(s, 10, 10 );
  printf("==> %s\n", s);
  return 0;
}
