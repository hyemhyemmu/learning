#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int calculate_score(int base) {  // ���ջ���������Ϊ����
    int increase = 2;             // ÿ�����ӵ����ǹ̶���
    static int bonus = 3;         // ��̬���� bonus����ʼΪ 3��ÿ�ε���ʱ�����ϴε�ֵ

    bonus += 2;                   // ÿ�ε��ú�ӳɷ������� 2

    return (base + increase + bonus);  // �����ܷ�
}

int main() {
    int i;
    int base = 2;                 // ÿ�ιؿ��Ļ��������ǹ̶��� 2 ��

    // ģ������������ 5 ���ؿ�
    for (i = 1; i <= 5; i++) {
        printf("After completing level %d, your score is %d\n", i, calculate_score(base));
    }

    return 0;
}
