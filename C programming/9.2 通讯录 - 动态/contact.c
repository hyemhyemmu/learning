#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

//��ʼ��
int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data=(PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo)); //��ʼ��3���˵Ŀռ�
	if (pc->data == NULL)
	{
		printf("InitContact: %s\n", strerror(errno));
		return 1;
	}
	pc->capacity = DEFAULT_SZ;
	return 0;
}

//������麯��
void CheckCapacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInfo* temp = (PeoInfo*)realloc(pc, (DEFAULT_INC + pc->capacity) * sizeof(PeoInfo));
		if (temp == NULL)
		{
			printf("AddContact: %s\n", strerror(errno));
			return;
		}
		pc->data = temp;
		pc->capacity += DEFAULT_INC;
	}
}


//������ϵ��
void AddContact(Contact* pc)
{
	assert(pc);
	
	//��������ʱ����
	CheckCapacity(pc);

	printf("���������֣�>");
	scanf("%s", pc->data[pc->count].name);
	printf("���������䣺>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա�>");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰��>");
	scanf("%s", pc->data[pc->count].tel);
	printf("�������ַ��>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("���ӳɹ���\n");

}

//չʾͨѶ¼
void ShowContact(const Contact* pc) 
{
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�");
		return;
	}
	int i = 0;
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%20s\t%3d\t%5s\t%12s\t%30s\n",	pc->data[i].name, 
												pc->data[i].age,
												pc->data[i].sex,
												pc->data[i].tel,
												pc->data[i].addr);
	}
}


//������ϵ��
int FindByName(Contact* pc)
{
	assert(pc);

	char name[MAX_NAME] = { 0 };
	printf("����������:>");
	int i = 0;
	for (i = 0; i < MAX_NAME; i++)
	{
		scanf("%s", &name[i]);
	}

	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
	
}


//ɾ����ϵ��
void DelContact(Contact* pc)
{
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�");
		return;
	}
	int pos = FindByName(pc);
	if (pos == -1)
	{
		printf("���޴���");
		return;
	}
	//ɾ�� - ͨ��������ģ��ɾ��
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)  //��ֹԽ�磬���Լ�һ
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ������ڻ���%d����ϵ��\n", pc->count);
}



//���Ҳ���ӡ��ϵ��
void SearchContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�");
		return;
	}
	int index = FindByName(pc);
	if (index == -1)
	{
		printf("���˲����ڣ�");
		return;
	}

	//��ӡ��ϵ����Ϣ
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	
	printf("%20s\t%3d\t%5s\t%12s\t%30s\n", pc->data[index].name,
		pc->data[index].age,
		pc->data[index].sex,
		pc->data[index].tel,
		pc->data[index].addr);
}


//�޸�ָ����ϵ����Ϣ
void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�");
		return;
	}
	int index = FindByName(pc);
	if (index == -1)
	{
		printf("���˲����ڣ�");
		return;
	}

	printf("�ҵ���,���������µ���Ϣ��!");
	printf("���������֣�>");
	scanf("%s", pc->data[index].name);
	printf("���������䣺>");
	scanf("%d", &(pc->data[index].age));
	printf("�������Ա�>");
	scanf("%s", pc->data[index].sex);
	printf("������绰��>");
	scanf("%s", pc->data[index].tel);
	printf("�������ַ��>");
	scanf("%s", pc->data[index].addr);

	printf("�޸ĳɹ�\n");

}

//������
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

//����
void SortContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�");
		return;
	}
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_by_name);
	printf("����ɹ���");
}

//���տռ�
void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}