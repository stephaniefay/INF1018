#include <stdio.h>

double foo3 (double *a, int n);

int main(void) {
	double  a [2]= {0,1};

	printf("%f\n", foo3(a,2));
	return 0;
}
