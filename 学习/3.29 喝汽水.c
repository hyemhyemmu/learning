#define _CRT_SECURE_NO_WARNINGS

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ������Ǯ�������ܺȶ���ƿ��ˮ��

#include <stdio.h>

int main()
{
	int money = 0;
	printf("what is your money? :>");
	scanf("%d", &money);

	int total = money;
	int empty = money;

	while (empty / 2 != 0)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}

	printf("Total coke you can drink is %d!", total);

	return 0;
}