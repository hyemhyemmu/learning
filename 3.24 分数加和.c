#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����1/1-1/2+......+1/100�ĺ�
//ż����Ϊ-1

int main()
{
	int flag = 1;
	int i = 0;
	double sum = 0; //��С����������������
	for (i = 1; i <= 100; i++)
	{
		 sum = sum + flag*(1.0 / i);
		 flag = -flag;
	}
	printf("%lf", sum);

	return 0;
}