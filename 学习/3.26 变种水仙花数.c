#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
����ˮ�ɻ��� - Lily Number : �����������, ���м��ֳ���������, ����1461��
�Բ�ֳ�(1��461), (14��61), (146��1), ������в�ֺ�ĳ˻�֮�͵�������,
����һ��Lily Number��
���� :
655 = 6 * 55 + 65 * 5
1461 = 1 * 461 + 14 * 61 + 146 * 1
���5λ���е�����Lily Number��
*/

int islily(int i)
{
	//�ж�
	int j = 0;
	int arr[4] = { 0 };

	for (j = 1; j <= 4; j++)
	{
		int power = (int)pow(10, j);
		arr[j - 1] = (i / power) * (i % power);
	}

	int sum = 0;
	for (j = 0; j <= 3; j++)
	{
		sum += arr[j];
	}

	return sum == i;

}



int main()
{
	char ch = 0;
	int i = 0;
	for (i = 10000; i < 100000; i++)
	{
		if (islily(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}