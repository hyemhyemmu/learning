#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����
//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;
//}

//����
int check_sys()
{
	union
	{
		char a;
		int b;
	}u;
	
	u.b = 1;
	return u.a;
}



int main()
{
	int ret = check_sys();
	if (ret == 1)
		printf("С��\n");
	else
		printf("���\n");
	return 0;
}