#include <stdio.h>

int main(void) {
  unsigned int x = 0x87654321;
  unsigned int y, z;

  unsigned int buffer = 0x000000FF;

  y = buffer&x;

  buffer = 0xFFFFFF00;
  
  z=buffer&x;
  z+= 0x000000FF;


  printf("%08x %08x\n", y, z);
  return 0;
}
