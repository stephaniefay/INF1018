#include <ctype.h>
#include <stdio.h>

void num2string(char *s, int num, int base) {
 char buffer[10] = "";
 int i = 0;
 while (num>0) {
    buffer[i] = num%base+'0';
    num /= base;
    i++;
  }
 for (; i>=0; *s++) {
   *s = buffer [i-1];
   i--;
 }
 *s++;
 *s = "\0";
}


int main (void) {
  char s [10] = "";
  num2string(s, 100, 10 );
  printf("==> %s\n", s);
  return 0;
}
