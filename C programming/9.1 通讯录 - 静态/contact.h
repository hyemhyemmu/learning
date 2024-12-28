#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 100 //���������ϵ����Ϊ100
#define MAX_NAME 50
#define MAX_SEX 5
#define MAX_TEL 20
#define MAX_ADDR 60

//�������� - ÿһ���˵���Ϣ
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];

} PeoInfo;


//����ͨѶ¼
typedef struct Contact
{
	PeoInfo data[MAX];
	int count; //��¼��ǰͨѶ¼��ʵ������

}Contact;


//��ʼ������
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//��ӡͨѶ¼�е���Ϣ
void ShowContact(const Contact* pc);

//������ϵ�ˣ���������
int FindByName(Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//���Ҳ���ӡ��ϵ��
void SearchContact(Contact* pc);

//�޸�ָ����ϵ����Ϣ
void ModifyContact(Contact* pc);

//����
void SortContact(Contact* pc);