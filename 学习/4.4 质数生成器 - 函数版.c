#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//���1-100������

int is_prime(int i)
{
	int j = 0;
	for (j = 2; j < i - 1; j++)
	{
		if (i % j == 0)
			return 0;
	}
	return 1;  //return 1 when i is a prime num
}



int main()
{
	int i = 0;
	int count = 0;
	for (i = 2; i <= 100; i++)
	{
		if (is_prime(i)) //�������ֵΪ1����ִ�У���֮��ִ�С�
		{
			count++;
			printf("%d ", i);
		}
	}
	printf("\nThere are %d numbers.", count);

	return 0;
}