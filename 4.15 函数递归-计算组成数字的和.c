#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����һ��������ӡ�����ÿһλ�ĺ�

//Digit(1234)
//Digit(123)+4
//Digit(12)+3+4
//Digit(1)+2+3+4

int DigitSum(int n)
{
	if (n > 9)
	{
		return DigitSum(n / 10) + n % 10;
	}
	else
	{
		return n;
	}
}




int main()
{
	int n = 0;
	printf("enter number:> ");
	scanf("%d", &n);
	int sum = DigitSum(n);
	printf("%d", sum);

	return 0;
}