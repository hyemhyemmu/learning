#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 3;
	int b = 5;
	printf("����֮ǰ��a=%d, b=%d\n", a, b);
	a = a ^ b; //3^5
	b = a ^ b; //(3^5)^5=3
	a = a ^ b; //(3^5)^3=5
	printf("����֮��a=%d, b=%d", a, b);


	return 0;
}