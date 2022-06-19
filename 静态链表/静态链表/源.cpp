#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAXSIZE 1000//���䴢��ռ�
#define OK 1
#define ERROR 0
typedef char ElemType;
typedef int Status;
typedef struct Component
{
	ElemType date;
	int cur;//�α꣬Ϊ0ʱ��ʾ��ָ��
}StaticLinkList[MAXSIZE];/*���ṹ����������¶���ΪStaticLinkList*/

Status visit(ElemType e)/*��ӡ*/
{
	printf("%c", e);
	return OK;
}

int Malloc_SSL(StaticLinkList L)/*��ȡ�����������пռ䣩���±�*/
{
	int i;
	i = L[0].cur;
	if (L[0].cur)
		L[0].cur = L[i].cur;/*�������������пռ䣩���±���и���*/
	return i;
}

Status Free_SSL(StaticLinkList L, int i)/*���ս��*/
{
	L[i].cur = L[0].cur;
	L[0].cur = i;
	return OK;
}

Status InitList(StaticLinkList L)//��ʼ������
{
	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		L[i].cur = i + 1;
		L[MAXSIZE - 1].cur = 0;//��������һ��Ԫ��cur������ŵ�һ������Ԫ�ص��±꣬�൱��ͷ���
	}
	return OK;
}

int ListLength(StaticLinkList L)/*��������Ԫ�ظ���*/
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}

Status ListInsert(StaticLinkList L, int i, ElemType e)/*������ĵ�i��λ�ò�������e*/
{
	int j, k, l;
	k = MAXSIZE - 1;
	if (i<1 || i>ListLength(L) + 1)
		return ERROR;
	j = Malloc_SSL(L);
	if (j)
	{
		L[j].date = e;
		for (l = 1; l <= i - 1; l++)
			k = L[k].cur;
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

Status ListTraverse(StaticLinkList L)/*��ӡ��������*/
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		visit(L[i].date);
		i = L[i].cur;
		j++;
	}
	return j;
	printf("\n");
	return OK;
}

Status ListDelete(StaticLinkList L, int i)/*ɾ����i��Ԫ��*/
{
	int k, j;
	if (i<1 || i>ListLength(L))
		return ERROR;
	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; j++)
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
	return OK;	
}

int main()
{
	StaticLinkList L;
	Status i;
	i=InitList(L);
	printf("��ʼ����L��L.length=%d\n", ListLength(L));
	i = ListInsert(L, 1, 'F');
	i = ListInsert(L, 1, 'E');
	i = ListInsert(L, 1, 'D');
	i = ListInsert(L, 1, 'B');
	i = ListInsert(L, 1, 'A');
	printf("�ڱ�ͷ���β���FEDBA��\nL.data=");
	ListTraverse(L);
	i = ListInsert(L, 3, 'C');
	printf("\n��L�ġ�B���롰D��֮����롰C����\nL.date=");
	ListTraverse(L);
	i = ListDelete(L, 1);
	printf("\n��ɾ��L�ġ�A����\nL.date=");
	ListTraverse(L);
	printf("\n");
	return 0;
}