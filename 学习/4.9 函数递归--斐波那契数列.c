#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�����ݹ�ʵ�ּ���쳲���������

/*
fib(n)=1,n<=2
fib(n)=fib(n-1)+fib(n-2),n>2
*/

int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}




int main()
{
	int n = 0;
	printf("����Ҫ�ڼ�λ��쳲���������> ");
	while (scanf("%d", &n) != 1 || n <= 0)
	{
		printf("\n�������룡�����ԣ�>");
		while (getchar() != '\n');
	}

	printf("����쳲���������Ϊ: ");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ",fib(i));
	}

	int output = fib(n);
	printf("\n��%d����쳲�������Ϊ%d", n, fib(n));


	return 0;
}