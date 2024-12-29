#define _CRT_SECURE_NO_WARNINGS
#include "system.h"

enum Options
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	SHOW
};


void menu()
{
	printf("******************************\n");
	printf("******1. add      2. del******\n");
	printf("******3. search***************\n");
	printf("******0. exit           ******\n");
	printf("******************************\n");

}


int main()
{
	//����ϵͳ
	System sys;
	//��ʼ��ϵͳ
	if (Init(&sys))
	{
		printf("��ʼ��ʧ�ܣ������ڴ�ʧ�ܣ�");
		return 1;
	}

	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddStu(&sys);
			break;
		case DEL:
			DelStu(&sys);
			break;
		case SEARCH:
			SearchStu(&sys);
			break;
		case EXIT:
			Exit(&sys);
			printf("�˳�ϵͳ");
			break;
		default:
			printf("ѡ�����");
			break;

		}

	} while (input!=EXIT);
	return 0;
}