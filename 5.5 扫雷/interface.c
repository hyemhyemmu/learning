#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void game()
{
	char mine[ROWS][COLS] = { 0 };   //�����õ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };   //����Ų���Ϣ
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');

	//������
	SetMine(mine, ROW, COL);
	DisplayBoard(show, ROW, COL); //��ӡ����

	//�Ų���
	FindMine(mine, show, ROW, COL);
}




void menu()
{
	printf("*************************\n");
	printf("****1. play 0. exit******\n");
	printf("*************************\n");
}


int main()
{
	int srand = ((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�");
			break;
		default:
			printf("ѡ�����");
			break;
		}
	} while (input);


	return 0;
}