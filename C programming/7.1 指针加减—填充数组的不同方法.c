#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�������Ĳ�ͬ����

int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);

	//����ķ���
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
		printf("%d ", arr[i]);
	}

	//ָ��ķ���1
	int* p = arr; //&arr[0]
	for (i = 0; i < sz; i++)
	{
		*p++ = i; //*p=i; *p++
		printf("%d ", arr[i]);
	}

	//ָ��ķ���2
	int* p = arr; //&arr[0]
	for (i = 0; i < sz; i++)
	{
		*(p+i) = i; //��[0]�Ҳ�ĵ�i�ֵΪi
		printf("%d ", arr[i]);
	}

	return 0;
}