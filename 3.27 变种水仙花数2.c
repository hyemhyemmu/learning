#define _CRT_SECURE_NO_WARNINGS

//���0-10000֮�����еġ�ˮ�ɻ����������
//��ˮ�ɻ�������һ��nλ������λ����n�η�֮��ǡ�õ��ڱ���

#include <stdio.h>
#include <math.h>

int is_num(int n)
{
	int i = 0;
	int temp = n;//����
	//�ж�λ��
	while (temp / 10 != 0)
	{
		temp = temp / 10;
		i++;
	}
	i++; //i��ŵ���λ��
	 temp = n;//����
	//�Ӻ�
	int sum = 0;
	int num = i; //ѭ����������λ��
	int j = 0;
	

	for (j = 0; j < i; j++)
	{
		int digit = 0;
		digit = temp % 10;  //ÿ�ζ�ȡ���һλ����
		sum += pow(digit, i);
		temp = temp / 10;   //�������һλ
	}
	//��֤�Ƿ�Ϊˮ�ɻ���
	if (n == sum)
	{
		return 1;
	}

	return 0;
}



int main()
{
	int n = 0;
	for (n = 0; n <= 10000; n++)
	{
		
		if (is_num(n))
		{
			printf("%d ", n);
		}
	}
	


	return 0;
}