#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

//�׵ĸ���
#define EASY_COUNT 10

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
//չʾ����
void DisplayBoard(char board[ROWS][COLS], int row, int col); 
//���õ���
void SetMine(char board[ROWS][COLS], int row, int col);

//���ܣ�չ��һƬ��ͨ���ݹ�ʵ�֣�
void Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);
//�Ų���� ��ϸ�ڣ�FindMine����������Expand����,���Ա����Expand����ǰ�棩
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);