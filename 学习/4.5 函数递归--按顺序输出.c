#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����һ������ֵ������˳���ӡÿһλ

/*
�ݹ���̣�
print(1234)
print(123) 4
print(12) 3 4
print(1) 2 3 4
1 2 3 4 
*/

void print(int num)
{
	if (num > 9)
	{
		print(num / 10); //�ٳ���λ���ݹ�ǰ��λ��
	}
	printf("%d ",num % 10); //�����λ
}




int main()
{
	int num = 0;
	printf("Please enter number you want to output:> ");
	scanf("%d", &num);
	while (getchar() != '\n');

	print(num);

	return 0;
}