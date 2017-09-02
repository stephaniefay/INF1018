#include <stdio.h>
#include <string.h>
#include <math.h>


void num2string(char *s, int num, int base, int maxSize)
{
	if(base < 2 || base > 16)
		return;

	const char c[] = "0123456789ABCDEF";
	int m;
	int count = ceil(log(num) / log(base));
	if(count+1 > maxSize)
		return;

	s[count] = '\0';
	while(num > 0) {
		m = num % base;
		num -= m;
		s[--count] = c[m];
		num /= base;
	}
}

int main()
{
	char str[128];
	num2string(str, 11, 2, 128);
	printf("(11;2) %s\n", str);
	num2string(str, 12, 10, 128);
	printf("(12;10) %s\n", str);
	num2string(str, 100, 16, 128);
	printf("(100;16) %s\n", str);
	num2string(str, 0x1234, 16, 128);
	printf("(0x1234;16) %s\n", str);
	num2string(str, 100, 8, 128);
	printf("(100;8) %s\n", str);
	return 0;
}

