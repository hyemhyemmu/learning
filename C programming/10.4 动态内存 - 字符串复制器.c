#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ַ���������
//Ҫ�󣺱�дһ������������һ���ַ�����Ϊ���룬��̬�����ڴ����洢����ַ����ĸ�����
//������ָ�����ַ�����ָ�롣
//ע�⴦���ڴ����ʧ�ܵ������

#define MAX_INPUT 100

char* stringDup(const char* str)
{
	//����Ŀ����ǿ�ָ��
	if (str == NULL)
	{
		return NULL;
	}

	//�����ڴ�
	int len = strlen(str) + 1;
	char* new_pstr = (char*)malloc(len * sizeof(char));

	//��֤������
	if (new_pstr == NULL)
	{
		return NULL;
	}

	//�����ַ���
	strcpy(new_pstr, str);
	return new_pstr;
}


int main()
{
	char str[MAX_INPUT];
	printf("����������Ҫ�洢���ַ��������100���ַ�Ŷ��:>");
	//�����ַ���ȥ�����з�
	fgets(str, MAX_INPUT, stdin);
	str[strcspn(str, "\n")] = 0;

	//����Ϊ����
	char* new_pstr=stringDup(str);

	if (new_pstr == NULL)
	{
		printf("����ʧ�ܣ�");
		return 1;
	}
	
	//���
	printf("ԭʼ�ַ�����%s\n", str);
	printf("���Ƶ��ַ�����%s\n", new_pstr);

	free(new_pstr);
	new_pstr = NULL;
	return 0;
}
