#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//��������ʱ����������ַ�������

/*
my_strlen("abc")
1+my_strlen("bc")
1+1+my_strlen("c")
1+1+1+my_strlen("")
1+1+1+0
*/


int my_strlen(char* str) //�������ָ��
{

	if (*str != '\0') //�����ã���ȡָ��������ľ���ֵ
		return 1 + my_strlen(str + 1); //������һλ��ʼ�ĵ�ַ
	else
		return 0;
}



int main()
{
	char arr[] = "abc";
	int len = my_strlen(arr);
	printf("%d", len);
	return 0;
}