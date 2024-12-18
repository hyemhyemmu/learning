#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*�����ݹ�
��ŵ������
���������ӣ�A����B����C������n ����С���ȵ�Բ�̣�ֱ����С�������һ����С���������棩��
���������Բ�̶����� A ���ϡ������ǽ�����Բ�̰������¹����ƶ��� C ���ϣ�
1. ÿ��ֻ���ƶ�һ��Բ�̡�
2. Բ��ֻ�ܴ�һ�������Ƶ���һ�������ϡ�
3. ���ƶ������У��κ�ʱ�򶼱��뱣��ÿ�������ϵ�Բ�̰���С�����˳�����У�����Բ�̲��ܷ���СԲ�����棩��

**Ŀ�꣺** ʹ�����ٵĲ��裬������Բ�̴� A ���ƶ��� C ����
*/

void move(char pos1,char pos2) // function for moving
{
	printf("%c->%c ", pos1, pos2);
}


void hanoi(int n, char pos1, char pos2, char pos3) 
/*
main function for hanoi:
n --> nunmber of plates
pos1 --> starting pos
pos2 --> act as transfer pos
pos3 --> destination pos
*/
{
	if (n == 1)
	{
		move(pos1, pos3); //if only one plate, we can just move it straightforwardly
	}
	else
	{
		hanoi(n - 1, pos1,pos3, pos2); // use hanoi function when need to transit lots of plates at once 
		move(pos1, pos3);
		hanoi(n - 1, pos2, pos1, pos3);
	}
}




int main()
{
	int n = 0;
	char pos1 = 'A';
	char pos2 = 'B';
	char pos3 = 'C';

	printf("How many plates do you have? >");
	while (scanf("%d", &n) != 1) //ensure valid input
	{
		printf("\ninvalid input, try again! >");
		while (getchar() != '\n');
	}
	hanoi(n,pos1,pos2,pos3); //start hanoi!!



	return 0;
}