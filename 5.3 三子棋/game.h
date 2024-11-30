#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COL 3

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
//�ҿհ׵ĵط��������
void CompMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
/*
��� - "*"
���� - "#"
ƽ�� - "Q"
���� - "C"
*/
char IsWin(char board[ROW][COL], int row, int col);