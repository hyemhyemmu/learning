#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//ģ��ʵ��strlen����ַ�������

int my_strlen(char str[])
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
		return count;
}




int main()
{
	char arr[] = "abcdefg"; //[a b c d e f g \0]
	int len = my_strlen(arr);
	printf("%d", len);


	return 0;
}