#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void bubble_sort(int arr[],int sz)
{
	//��һ��������
	int j = 0;
	for (j = 0; j < sz - 1; j++)
	{
		int k = 0;
		for (k=0;k<sz-1-j;k++) //һ��ð���������������������һλ������֮��ÿһ��������Ժ�����������
			if (arr[k] > arr[k + 1]) //���������Ƚϴ�С���Ѵ�Ļ�������ȥ
			{
				int temp = arr[k + 1];
				arr[k + 1] = arr[k];
				arr[k] = temp;
			}
	}


}




int main()
{
	int arr[] = { 0,3,4,2,1,5,6,9,7,8 };
	//Ŀ������� 0 1 2 3 4  5 6  7 8 9
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);  //sz�����ں����м��㣬��Ϊ����arr[]�����ֻ�ǵ�һ�����ֵĵ�ַ
	bubble_sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}


	return 0;
}