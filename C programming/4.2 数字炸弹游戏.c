#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*��Ŀ˵��������ը����Ϸ
��Ϸ����
ϵͳ�������һ������ը�������� 1-100����
��������²�������֡�(1-4��)
ÿ���������һ�����֣�
�������̫���̫С����ʾ��ҡ�
�����Ҳ����ˣ�ϵͳ����˭��ʤ��
����²�����������ƣ����� 10 �Σ�����Ϸ�Զ�����������ʾ�𰸡�
��Ϸ��������ҿ���ѡ�����¿�ʼ���˳���*/

void menu()
{
	printf("******************************\n");
	printf("***** 1. Play  0. Exit  ******\n");
	printf("******************************\n");
}

void game()
{
	int players = 1;
	int turn = 1;
	int maxGuesses = 10;
	int guess = 0;
	int currentplayer = 1;
	printf("How many players do you have?>");
	while (scanf("%d", &players) != 1 || players < 1 || players>4)
	{
		printf("Invalid input. Try again!");
		while (getchar() != '\n');
	} //ensure valid input

	int num = rand() % 100 + 1; //generate random #bombs

	printf("A random bomb number has been generated (1-100). Guess it!\n");

	for (turn = 1; turn <= maxGuesses; turn++)
	{
        printf("Player %d, What is your guess:>", currentplayer);
		while (scanf("%d", &guess) != 1 || guess < 1 || guess>100)
		{
			printf("invalid input. try again!");
			while (getchar() != '\n');
		}

		if (guess > num)
		{
			printf("Too big!\n");
		}
		else if (guess < num)
		{
			printf("Too small!\n");
		}
		else
		{
			printf("Congrats! Player #%d, You made it!\n",currentplayer);
			return; //exit game
		}

		currentplayer = (currentplayer + 1) % players;
	}
	printf("out of chance! The bomb was %d. Game over!\n", num);

}

int main()
{
	srand((unsigned int)time(NULL)); //initial for rand
		int choice = 0;
	
	do // as least display menu once, will exit when input 0
	{
		menu();
		printf("Choose next step:>");
		while (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1)) //ensure valid input
			{
				printf("Invalid input. Enter again!");
				while (getchar() != '\n'); //clear buffer
			}

		switch (choice)
		{
		case 1:
			printf("Let's start!");
			game();
			break;
		case 0:
			printf("Goodbye!");
			return;
		}

			
	} while (choice != 0);

	return 0;
}