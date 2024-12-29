#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//��̬��������
//Ҫ�󣺱�дһ�����������û�����һ������n��Ȼ��̬����һ���ܴ洢n�����������顣
//�������û�������n��������������������򲢴�ӡ���������Ҫ��ȷ�ͷ��ڴ档

//qsort�ȽϺ�����ʵ��
int compare_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}


int main()
{
	int n = 0;
	printf("�������������Ԫ�ظ���:>");
	if (scanf("%d", &n) != 1 || n <= 0)
	{
		printf("������Ч��������һ����������\n");
		return 1;
	}
	while (getchar() != '\n');

	int* arr = (int*)calloc(n, sizeof(int));

	if (arr == NULL)
	{
		printf("%s", strerror(errno));
	}

	int i = 0;
	printf("�������������Ԫ��:>");
	for (i = 0; i < n; i++)
	{
		if (scanf("%d", &arr[i]) != 1)
		{
			printf("������Ч�������˳���\n");
			free(arr); //��Ч��ʱ��ҲҪ�ͷ��ڴ�
			return 1;
		}
		while (getchar() != '\n');
	}
	

	//����
	qsort(arr, n, sizeof(int), compare_int);


	for (i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}


	free(arr);
	arr = NULL;
	return 0;
}