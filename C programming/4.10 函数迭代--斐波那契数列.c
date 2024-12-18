#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ʹ�ú�����������ʽ���쳲�������(�����������
int fib(int n)
{
    if (n == 1 || n == 2) // �� n = 1 �� n = 2 �����⴦��
    {
        return 1;
    }

    int a = 1, b = 1, c = 0;

    for (int i = 3; i <= n; i++) // �ӵ� 3 �ʼ����
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c; // ���ص� n ��Ľ��
}

int main()
{
    int n = 0;
    printf("����Ҫ�ڼ�λ��쳲���������> ");
    while (scanf("%d", &n) != 1 || n <= 0) // ������֤
    {
        printf("\n�������룡�����ԣ�>");
        while (getchar() != '\n'); // ��ջ�����
    }

    printf("����쳲���������Ϊ: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", fib(i)); // ���쳲��������е�ÿһ��
    }

    int output = fib(n); // ֻ����һ�� fib(n)
    printf("\n��%d����쳲�������Ϊ%d\n", n, output);

    return 0;
}
