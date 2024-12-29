#define _CRT_SECURE_NO_WARNINGS
#include "system.h"

//��ʼ��ϵͳ
int Init(System* sys)
{
	assert(sys);
	
	sys->count = 0;
	sys->data = (StuInfo*)calloc(DEFAULT_SYS_CAPACITY, sizeof(StuInfo));
	if (sys->data == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	sys->capacity = DEFAULT_SYS_CAPACITY;
	return 0;
}


//���ϵͳ�Ƿ�Ϊ��
int CheckIfEmpty(System* sys)
{
	if (sys->count == 0)
	{
		printf("ϵͳΪ�գ�");
		return 1;
	}
	return 0;
}



//�����������Ҫʱ����
void CheckCapacity(System* sys)
{
	if (sys->capacity == sys->count)
	{
		StuInfo* temp = (StuInfo*)realloc(sys->data, (DEFAULT_INC + sys->capacity) * sizeof(StuInfo));
		if (temp == NULL)
		{
			printf("%s\n", strerror(errno));
			return;
		}
		sys->data = temp;
		sys->capacity += DEFAULT_INC;
	}
}


//���
void AddStu(System* sys)
{
	assert(sys);
	CheckCapacity(sys);

	printf("������������>");
	scanf("%s", sys->data[sys->count].name);
	printf("������ѧ�ţ�>");
	scanf("%d", &(sys->data[sys->count].stu_num));
	printf("������ɼ���>");
	scanf("%d", &(sys->data[sys->count].grade));

	sys->count++;
	printf("���ӳɹ���\n");
}

//ͨ�����ֲ��ң���������
int FindByName(const System* sys)
{

	char name[] = { 0 };
	printf("������Ҫ���ҵ�ѧ��������>");
	fgets(name, MAX_NAME, stdin);
	name[strcspn(name, "\n")] = 0;

	int i = 0;
	for (i = 0; i < sys->count; i++)
	{
		if (strcmp(sys->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}


//ɾ��ָ��ѧ����Ϣ
void DelStu(System* sys)
{
	assert(sys);
	if (CheckIfEmpty(sys))
	{
		return 1;
	}
	
	int index = FindByName(sys);
	if (index == -1)
	{
		printf("���˲����ڣ�");
		return;
	}

	//ͨ��������ģ��ɾ��
	int i = 0;
	for (i = index; i < sys->count - 1; i++)
	{
		sys->data[i] = sys->data[i + 1];
	}
	sys->count--;
	printf("ɾ���ɹ������ڻ���%d��ѧ��\n", sys->count);

}

//����ѧ������ӡ
void SearchStu(const System* sys)
{
	assert(sys);
	if (CheckIfEmpty(sys))
	{
		return 1;
	}

	int index = FindByName(sys);
	if (index == -1)
	{
		printf("���˲����ڣ�");
		return;
	}

	//��ӡ��ϵ����Ϣ
	printf("%-10s\t%-10s\t%-10s\n", "����", "ѧ��", "�ɼ�");
	printf("%-10s\t%-10d\t%-10d\n",
		sys->data[index].name,
		sys->data[index].stu_num,
		sys->data[index].grade);
}

//�˳�ϵͳ���ͷ��ڴ�
void Exit(System* sys)
{
	if (sys->data)
	{
		free(sys->data);
		sys->data = NULL;
	}
}