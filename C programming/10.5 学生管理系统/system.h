#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_NAME 50
#define DEFAULT_SYS_CAPACITY 10
#define DEFAULT_INC 5


//����
typedef struct StuInfo
{
	char name[MAX_NAME];
	int stu_num;
	int grade;
}StuInfo;


//ϵͳ
typedef struct System
{
	StuInfo* data;
	int count;  //��ǰѧ������
	int capacity;  //ϵͳ����
}System;

//��ʼ��ϵͳ
int Init(System* sys);

//���ϵͳ�Ƿ�Ϊ��
int CheckIfEmpty(System* sys);

//�����������Ҫʱ����
void CheckCapacity(System* sys);

//���
void AddStu(System* sys);

//����
int FindByName(const System* sys);


//ɾ��
void DelStu(System* sys);

//���Ҳ�չʾ
void SearchStu(const System* sys);

//�˳�ϵͳ���ͷ��ڴ�
void Exit(System* sys);