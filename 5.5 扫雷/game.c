#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set; //��ʼ������
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------ɨ����Ϸ-----\n");
	
	for (j = 0; j <= col; j++) //��ӡ�к�
	{
		printf("%d ", j);
	}
	printf("\n");

	for (i = 1; i <= row; i++) //����Ĵ�ӡ�Ǵ�1��ʼ����row��������Ϊ��0�к͵�0���ǿյ�
	{	
		printf("%d ", i); //��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------ɨ����Ϸ-----\n");
}	

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	int i = 0, j = 0;
	while (count) //ֻҪ�׵ĸ���û���ͽ���ѭ��
	{
		i = rand() % row + 1; //+1����Ϊ�õ�����0-8��������Ҫ1-9
		j = rand() % col + 1;

		if (board[i][j] == '0') //�����жϵ�λ�Ƿ񱻲��ù�
		{
			board[i][j] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return (board[x - 1][y] + board[x - 1][y - 1] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0');
}

void Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	// ��������߽硢�Ѿ�����ʾ�������ף���ֹͣչ��
	if (x < 1 || x > row || y < 1 || y > col || show[x][y] != '*')
		return;

	// ��ȡ��ǰ������Χ�׵�����
	int count = get_mine_count(mine, x, y);
	if (count > 0)
	{
		// �����Χ���ף���ʾ�׵�������ֹͣ�ݹ�
		show[x][y] = count + '0'; // ת��Ϊ�ַ�
		return;
	}

	// �����Χû���ף�����ǰ���ӱ��Ϊ�ո񲢵ݹ�չ��
	show[x][y] = ' ';

	// �ݹ�����Χ�� 8 ������
	Expand(mine, show, row, col, x - 1, y - 1);
	Expand(mine, show, row, col, x - 1, y);
	Expand(mine, show, row, col, x - 1, y + 1);
	Expand(mine, show, row, col, x, y - 1);
	Expand(mine, show, row, col, x, y + 1);
	Expand(mine, show, row, col, x + 1, y - 1);
	Expand(mine, show, row, col, x + 1, y);
	Expand(mine, show, row, col, x + 1, y + 1);
}




void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int win = 0;
	

	while (win<row*col-EASY_COUNT)
	{
		printf("������Ҫ�Ų������:> ");
		scanf("%d %d", &x, &y);
		while (getchar() != '\n');
		if (x >= 1 && x <= row && y >= 1 && y <= col) //����Ƿ�Խ��
		{
			if (mine[x][y] == '1')  //���е���
			{
				printf("���е����ˣ���\n");
				printf("�������׶�������ɣ�\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else if (show[x][y] != '*') //�Ѿ��Ų����
				printf("���λ���Ѿ��Ų���ˣ�\n");
			else  //û���е��� //��Ҫ�ĵ����������ŵ����ַ���ASCIIֵ����˲���ֱ����ӡ�������1��0��ASCIIֵǡ�����1����˿��Կ����ַ����
			{
				win++; //û���е��׾Ϳ�����Ϊ����+1
				int count = get_mine_count(mine, x, y);
				if (count > 0)//�����Χ���ף���ô��Ҫչʾ��Χ�׵ĸ���
				{
					show[x][y] = count + '0'; //����ؽ�����ת��Ϊ�ַ���ASCII�룩
					
				}
				else if(count==0) //��Χû���ף���Ҫչ��һƬ
				{
					Expand(mine, show, row, col, x, y);
				}
				DisplayBoard(show, ROW, COL); //ѡ����ÿһ���Ų��չʾ����
			
			}
		}
		else
			printf("\n�������!");
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n");
		DisplayBoard(mine, ROW, COL);
	}
		
	
}