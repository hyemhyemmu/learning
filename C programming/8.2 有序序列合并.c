#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
�����������,

��һ�а�������������n,m,�ÿո�ָ���n��ʾ�ڶ��е�һ���������������ֵĸ�
��,m��ʾ�����еڶ����������������ֵĸ�����

�ڶ��а���n������,�ÿո�ָ���

�����а���m������,�ÿո�ָ���

�������:
���Ϊһ��,�������Ϊn+m����������,������Ϊn���������кͳ���Ϊm������
�����е�Ԫ�����½��������������кϲ���
*/

int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);

	int arr_1[1000];
	int arr_2[1000];
	int arr_3[2000];


	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", arr_1 + i);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d", arr_2 + i);
	}

	int j = 0;
	int k = 0;
	int r = 0;

	while (j < n && k < m)
	{
		if (arr_1[i] > arr_2[j])
		{
			arr_3[r++] = arr_1[i];
			j++;
		}
		else
		{
			arr_3[r++] = arr_2[k];
			i++;
		}
	}

	if (j < n)
	{
		for (; j < n; j++)
		{
			arr_3[r++] = arr_1[j];
		}
	}
	else
	{
		for (; k < m; k++)
		{
			arr_3[r++] = arr_2[k];
		}
	}
	return 0;
}