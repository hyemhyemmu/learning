#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*������Ϊһ���������±�дһ���Ʒֳ�������������У�ÿ���˶�Ա���һ�������Ŀʱ������һ���ķ�����ÿ����Ŀ�ķ�����Ϊ�������֣�

�����÷֣�ÿ�α������˶�Ա�����ù̶��� 5 �֡�
�ۻ��÷֣�ÿ���˶�Ա�����Ŀ���ۻ��÷ֻ����ӣ���ʼֵΪ 10��ÿ�����һ����Ŀ���ۻ��÷����� 3 �֡�
Ҫ��
��дһ�� calculate_total_score ����������ÿ���˶�Ա��ɱ�������ܵ÷֡�
ʹ�� static �������洢 �ۻ��÷֣���֤ÿ����Ŀ���ʱ�ۻ��÷����ӣ�ֱ��������Ŀ��ɡ�
�� main ������ʹ��һ��ѭ��ģ���˶�Ա������� 6 ����Ŀ�����ÿ�������Ŀ����ܵ÷֡�*/

int calculate_total_score(int base)
{
	int basic = 5;
	static int bonus = 10;

	bonus += 3;
	return(base + basic + bonus);
}



int main()
{
	int i;
	int base = 0;

	for (i = 1; i < 7; i++)
	{
		printf("After completing level %d,your score is %d\n", i, calculate_total_score(base));
	}
}