#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
���дһ�� C ���Գ���ʵ�����¹��ܣ�

�����û�������������飨������ 10 ��Ԫ�أ�������ð���������鰴��С�����˳�����С�
������������Ԫ�أ�����֮���ÿո�ָ���
����û���������ֳ��� 10 ����ֻ����ǰ 10 �����֣��������ֺ��ԡ�
���������Ϊ�գ��û�����ĸ���Ϊ 0������ʾ�û�������Ϊ�գ��޷����򡣡�
*/

void bubble_sort(int arr[], int n)
{
	int j = 0;
	for (j = 0; j < n - 1; j++) //����
	{
		int k = 0;
		for (k = 0; k < n - 1 - j; k++) //ÿһ���ߵĲ���
		{
			if (arr[k] > arr[k + 1])
			{
				int temp = arr[k + 1];
				arr[k + 1] = arr[k];
				arr[k] = temp;
			}
		}
	}
}





int main()
{
	printf("How many number do you want to process? > ");
	int n = 0;
	int arr[10];

	while (scanf("%d", &n) != 1)
	{
		printf("invalid input. Please check! > ");
		while (getchar() != '\n');
	}

	/*while (scanf("%d", &n) == 0)
	{
		printf("Your array is empty and can't be ranked.");
		while (getchar() != '\n');
	}
		���ﲻ����while����Ϊscanfû��ɨ��������ʱ�򷵻صľ���0��
		������0�����˻�����ҲӰ����ǰ��һ������������ж�
	*/      

	if (n == 0)
	{
		printf("Your array is empty and can't be ranked.\n");
		return 0;
	}
	if (n > 10)
	{
		printf("That's too much! I will only process 10 of them. \n");
		n = 10; //top 10 figures
	}


	printf("Please enter your numbers:> ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]); //����治��Ҫ�������������Ȼ��������ֶ�û��
			}
	
	bubble_sort(arr, n);

	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}