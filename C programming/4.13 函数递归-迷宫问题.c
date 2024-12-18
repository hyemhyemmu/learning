#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
 ��������һ�� n �� m ���Թ��У���Ҫ�����Ͻǵ���㣨���� (0, 0)��
 �ߵ����½ǵ��յ㣨���� (n-1, m-1)����
 ��ֻ�����»������ƶ������Ҳ����߳��Թ��ı߽硣
 ����дһ���ݹ麯���������㵽�յ��ж����ֲ�ͬ��·����

����Ҫ��
���룺�Թ��Ĵ�С m �� n������ n �� m ��Ϊ��������
���������㵽�յ��·��������
*/


//f(m,n)=f(m-1,n)+f(m,n-1)
int route(int m, int n)
{
	if (m==1||n==1) 
	{
		return 1;
	}

	else
	{
		return route(m - 1, n) + route(m, n - 1);
	}

}




int main()
{
	int m = 0, n = 0;
	int output = 0;
	printf("How big? >");
	while (scanf("%d %d", &m, &n) != 2 || m <= 0||n<=0)
	{
		printf("invalid input!");
		while (getchar() != '\n');
	} //ensure valid input

	output = route(m, n);
	printf("%d", output);


	return 0;
}