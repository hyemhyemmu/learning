//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <math.h>
//
////���1-100������
//
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 2; i <= 100; i++) //��2��ʼ����Ϊ1��������
//	{
//		int flag = 1; //��һ��flage����ʾ������ؼ�����
//		int j = 0;
//		for (j = 2; j <= i-1; j++) //�Ż���ʹ��sqrt(i)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break; //�������ѭ���壬Ҳ����for���� 
//			}
//
//		}
//		if (flag == 1) //����������ֵ��Գ�������ж�Ϊ����
//		{
//			
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\nThere are %d numbers.", count);
//
//
//
//	return 0;
//}