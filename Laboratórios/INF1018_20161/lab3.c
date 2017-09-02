#include <stdio.h>
int main(void) {
  unsigned int x = 0x87654321;
  unsigned int y, z;

  /* o byte menos significativo de x e os outros bits em 0 */
  y = 0xFF & x;

  /* o byte menos significativo com todos os bits em '1' 
     e os outros bytes com o mesmo valor dos bytes de x */
  z = 0xff | x;

  printf("%08x %08x\n", y, z);
}
