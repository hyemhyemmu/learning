#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	//�������������ӡһ��������
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡ����
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|"); //���һ����治�ٴ�ӡ�ָ���
		}
		printf("\n");
		  
		//��ӡ�ָ���
		if (i < row - 1) //������ͼ��ж�����Ϊ��������Ӱ��ָ���������
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|"); //���һ����治�ٴ�ӡ�ָ���
			}
			printf("\n");
		}
	}
}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("�ֵ�����ˣ�\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����������:> ");
		if (scanf("%d %d", &x, &y) != 2)
		{
			printf("���������������������\n");
			while (getchar() != '\n'); // ������뻺����
			continue;
		}

		// ��Χ�Ϸ����жϺ�������
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			// �жϸ����Ƿ�����
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*'; // ����
				break;
			}
			else
			{
				printf("�����Ѿ������ˣ�\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}


void CompMove(char board[ROW][COL], int row, int col)
{
	printf("�ֵ������ˣ�\n");
	int x = 0;
	int y = 0;

	

	while (1)
	{
		x = rand() % row; //0-2
		y = rand() % col; //0-2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#'; 
			break;
		}
	}



}



//�ж��Ƿ����ˣ� ���˷���1����������0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}





char IsWin(char board[ROW][COL], int row, int col)
{
	//��
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0]; //������һ�����������ƣ��������ж�
		}
	}
	//��
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[0][j]; 
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') //��Խ���
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') //�ҶԽ���
	{
		return board[0][2];
	}

	//�����ʱ��û����������ж��Ƿ�ƽ��
	//Ҫ�ȿ��Ƿ�����ˣ���Ϊ�ж���Ӯ�Ĳ�����ÿһ������֮�󶼻���е�
	if (IsFull(board, row, col)) 
	{
		return 'Q';
	}

	//��Ȼ��Ϸ�ͼ���
	return 'C';
}