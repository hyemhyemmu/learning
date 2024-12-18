#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("*****  1. play 0. exit  *****\n");
	printf("*****************************\n");
}


void game() //��Ϸ��������
{
	//����Ҫ��ʼ������
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL); //����ϣ�������̴�СҲһ���룬���������Ĭ��Ϊ3

	//��ӡ����
	DisplayBoard(board, ROW, COL);
	
	char ret = 0;
	//����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') //ֻҪ���Ǽ�����ȫ���˳�
			break;
		//���Լ�����
		CompMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ�ˣ�\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ�ˣ�\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��~\n");
	}
}




int main()
{
	int input = 0;
	srand((unsigned int)time(NULL)); //������������
	do
	{
		menu(); //��ӡ�˵�
		printf("��ѡ��> ");
		scanf("%d", &input); //��ȡ����
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input != 0); //�˵����ٳ���һ��




	return 0;
}