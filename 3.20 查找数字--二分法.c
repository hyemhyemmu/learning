#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = 0;
	printf("��������Ҫ���ҵ����֣�");
	scanf("%d", &n);

	
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	int in_left = 0;
	int in_right = sz - 1;
	
	
	while (in_left <= in_right)
	{
		int in_mid = (in_left + in_right) / 2;
		
		if (arr[in_mid] < n)
		{
			in_left = in_mid + 1;
		}
		else if (arr[in_mid] > n)
		{
			in_right = in_mid - 1;
		}
		else if (arr[in_mid] == n)
		{
			printf("�ҵ��ˣ�����λ��%d", in_mid + 1);
			break;
		}

	}
	if (in_left > in_right)
	{
		printf("��⣬������ֲ���������Ŷ��");
	}
	


	return 0;
}