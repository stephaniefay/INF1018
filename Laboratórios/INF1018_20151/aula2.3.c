#include <ctype.h>
#include <stdio.h> 

int string2num (char *s, int par) {
  int a = 0;
  for (; *s; s++)
    if (isdifgit(s))
    	a = par*a + (*s - '0');
    else {
	a = par*a + (*s - 'a'+10);
  return a;
}

int main (void) {
  printf("==> %d\n", string2num("a"));
  printf("==> %d\n", string2num("a") + 1);
  printf("==> %d\n", string2num("a") + string2num("1"));
  return 0;
}
