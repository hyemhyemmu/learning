#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	//����
	int line = 0;
	printf("enter line number:>");
	while (scanf("%d", &line) != 1)
	{
		printf("enter error!\n");
		while (getchar() != '\n');
	}

	//��
	int i = 0;
	for (i = 0; i < line; i++)
	{
		//��ӡһ��
		//�ո�
		int j = 0;
		for (j = 0; j < line - 1-i; j++)
		{
			printf(" ");
		}
		//�Ǻ�
		for (j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//��
	for (i = 0; i < line-1; i++)
	{
		//��ӡһ��
		//�ո�
		int j = 0;
		for (j = 0; j <=i; j++)
		{
			printf(" ");
		}
		//�Ǻ�
		for (j = 0; j < 2 * (line - 1-i)-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}


	return 0;
}