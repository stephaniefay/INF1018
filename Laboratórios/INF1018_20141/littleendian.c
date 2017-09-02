#include <stdio.h>

int is_little() {
  int x = 1;
  if (*(char *)&x == 1)
	return 1;
  else 
	return 0;
}

int main ( ) {
	int x;
	 x = is_little ();
	if ( x == 0 ) 
		printf ("Big Endian");
	else
		printf ("Little Endian");

	return 0;
}
