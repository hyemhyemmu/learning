//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main()
//{
//	char password[100] = { 0 };
//	int ch = 0,result=0;
//
//	while (1)
//	{
//		printf("���������룺> ");
//		scanf("%s", password);
//		while ((ch = getchar()) != '\n' && ch != EOF); //����������е�\n��EOF
//
//		printf("��ȷ������(Y/N):>  %s\n", password);
//		result = getchar();
//		while ((ch = getchar()) != '\n' && ch != EOF); //��ϰ�ߣ�get�����ջ�����
//
//		if (result == 'Y')
//		{
//			printf("�ѱ��棬лл��");
//			break;
//		}
//		else if(result == 'N')
//		{
//			printf("���������룡");
//		}
//		else
//		{
//			printf("�������ֻ������Y/N��");
//		}
//
//		
//	}
//	return 0;
//}