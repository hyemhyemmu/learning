#define _CRT_SECURE_NO_WARNINGS
//����������
//����ֻ��һ�У��������ڣ����������գ�������֮�������û�зָ�����
//���������
//���У���һ��Ϊ������ݣ��ڶ���Ϊ�����·ݣ�������Ϊ�������ڡ����ʱ����·ݻ�����Ϊ1λ������Ҫ��1λ��ǰ�油0��

#include <stdio.h>

int main()
{
	int year = 0, month = 0, date = 0;
	scanf("%4d%2d%2d", &year, &month, &date);
	printf("year=%d\n", year);
	printf("month=%02d\n", month);
	printf("date=%02d\n", date);

	return 0;
}