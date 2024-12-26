#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//����һ��10λ�������飬ʵ��һ������ʹ�����е������������ǰ�벿�֣�
//����ż��������ĺ�벿��

void move_odd_even(int* arr, int sz)
{
	int left = 0;
	int right = sz - 1;

	//�ӣ�����Ǵ�����/ż�����飬���п��ܷ�������Խ��
	while (left<right)
	{
		//ż��
		while (left < right && arr[left] % 2 == 1)
		{
			left++;
		}

		//����
		while (left < right && arr[right] % 2 == 0)
		{
			right--;
		}

		//����
		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;

			left++;
			right--;
		}
	}
		
}


int main()
{
	//����
	int arr[10] = { 0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", arr + i);
	}
	//����
	int sz = sizeof(arr) / sizeof(arr[0]);
	move_odd_even(&arr, sz);
	//���
	for (i = 0; i < 10; i++)
	{
		printf("%d", arr[i]);
	}

	return 0;
}