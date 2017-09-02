#include <stdio.h>
#include "corotinas.h"

int boxx (int x) {
	int cont = 1;
	while (cont) {
		printf ("ping: %d\n", x);
		x = coro_yield (cont);
		cont++;
	}
	return -1;
}

int boyy (int y) {
	int cont = 1;
	while (cont) {
		printf ("pong: %d\n", y);
		y = coro_yield (cont);
		cont++;
	}
	return -1;
}

int main ( ) {
	
	int i, param;
	CoroP ping, pong;

	ping = coro_create ("ping", boxx);
	pong = coro_create ("pong", boyy);

	for (i=0;i<=6;i++){
	
		if (i%2 == 0) {
			param = coro_resume (ping, i);
		}
		else {
			param = coro_resume (pong, i);
		}

		printf ("main: %d\n", param);
	}


	return 0;
}
