#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//ð�������Ż� - ��ͨ�á�������

void Swap(char* p1, char* p2, int width)
{
	//���λ������ַ
	char temp;
	int i = 0;
	for (i = 0; i < width; i++)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}


void bubble_sort(void* base, int sz,int width,int (*cmp)(const void*e1,const void*e2)) //cmp�ǱȽϺ���
{
	int i = 0; //����ָ��
	int j = 0; //j��ʾ����
	int flag = 0; //��һ���鱾����������
	for (j = 0; j < sz - 1; j++)
	{
		for (i = 0; i < sz - 1 - j; i++)
		{
			//ǰ�ߴ��ں���ʱ������
			if (cmp((char*)base + i * width, (char*)base + (i + 1) * width)) //Ҫ����취������ cmp(base+i,base+i+1)
			{
				Swap((char*)base + i * width, (char*)base + (i + 1) * width,width);
				flag = 1;
			}
			
		}
		if (flag == 0)
		{
			break;
		}
	}
	
}

struct Stu
{
	char name[20];
	int age;
};

int cmp_int(void* e1, void* e2)
{
	return (*(int*) e1 - *(int*) e2);  //ǿ��ת��Ϊint���͵�ָ����ܽ�����
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

int main()
{
	int arr[] = { 9,7,3,2,1,5,6,7,8,9,2 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);

	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	printf("�������飺");
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	struct Stu s[] = { {"Messi,38"},{"Ronaldo",39},{"Yamal",17} };
	int sz_2 = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz_2, sizeof(s[0]), cmp_stu_by_name);
	printf("����ṹ�壺");
	for (i = 0; i < sz_2; i++)
	{
		printf("%s %d ", s[i].name,s[i].age);
	}



	return 0;
}