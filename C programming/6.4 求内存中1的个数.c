#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//��ĳ���������ڴ��еĶ������е�1�ĸ���


int main()
{
	int n = 0;
	printf("����һ����:> ");
	while (scanf("%d", &n) != 1)
	{
		printf("invalid input!\n");
		while (getchar() != '\n');
	}

	int count = 0;
	while (n != 0)
	{
		if ((n & 1) == 1)
		{
			count++;
		}
		n=n >> 1; //����������������λ
	}
	printf("%d�Ķ������ڴ��ַ����%d��1��", n, count);

	return 0;
}