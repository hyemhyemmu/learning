//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
////�������� - �����汾
//void bubble_sort(int* arr, int sz)
//{
//	int i = 0; //����ָ��
//	int j = 0; //j��ʾ����
//	for (j = 0; j < sz - 1; j++)
//	{
//		for (i = 0; i < sz - 1 - j; i++)
//		{
//			//������ڣ��������֣�ָ����ת
//			if (arr[i] > arr[i + 1])
//			{
//				int temp = 0;
//				temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;
//			}
//		}
//
//	}
//	
//}
//
//
////�ݹ鷽��
//void bubble_sort_2(int* arr, int sz)
//{
//	if (sz == 1)
//	{
//		return;
//	}
//	int i = 0;
//	
//	//�ȽϷ�ʽ��һ����
//	for (i = 0; i < sz - 1; i++)
//	{
//		//������ڣ��������֣�ָ����ת
//		if (arr[i] > arr[i + 1])
//		{
//			int temp = 0;
//			temp = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = temp;
//		}
//	}
//
//	bubble_sort_2(arr, sz - 1);
//}
//
//
////�Ż����� - qsort 
//int comp_int(void* e1, void* e2)
//{
//	return (*(int*) e1 - *(int*) e2);  //ǿ��ת��Ϊint���͵�ָ����ܽ�����
//}
//
//
//
//int main()
//{
//	int arr[] = { 9,7,3,2,1,5,6,7,8,9,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	bubble_sort(arr,sz);
//
//	int i = 0;
//	printf("ʹ�õ���������");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	int arr_2[] = { 9,7,3,2,1,5,6,7,8,9,2 };
//	bubble_sort_2(arr_2, sz);
//	printf("ʹ�õݹ鷽����");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr_2[i]);
//	}
//	printf("\n");
//
//	int arr_3[] = { 9,7,3,2,1,5,6,7,8,9,2 };
//	qsort(arr_3, sz, sizeof(arr[0]), comp_int);  //��ʼ��������Ԫ�ش�С���ȽϺ������Զ���) - Ҫ��һ����������void������int�ĺ���
//	printf("ʹ��qsort������");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr_3[i]);
//	}
//	return 0;
//}