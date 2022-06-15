#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct Node/*����ڵ�*/
{
	ElemType date;
	struct Node* next;
}Node;
typedef struct Node* LinkList;/*LinkLIstһ�����ͣ�Ϊstruct Node**/

Status InitList(LinkList* L)/*��ʼ�����Ա�*/
{
	*L = (LinkList)malloc(sizeof(Node));/*����ͷ�ڵ㣬��ʹLָ���ͷ�ڵ�*/
	if (!(*L))
		return ERROR;
	(*L)->next = NULL;
	return OK;
}

Status ListEmpty(LinkList L)/*���L�Ƿ�Ϊ��*/
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

Status visit(ElemType c)/*��ӡ����*/
{
	printf(" % d ", c);
	return OK;
}

Status ClearList(LinkList* L)/*������L��գ���ɾ�����нڵ㣬ֻʣһ��ͷ�ڵ�*/
{
	LinkList p, q;
	p = (*L)->next;/*ָ���һ���ڵ�*/
	while (p)/*�ж��Ƿ񵽴��β*/
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

int ListLength(LinkList L)/*����L��Ԫ�ظ���*/
{
	int i=0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, ElemType* e)/*��ȡ�����е�i��Ԫ�ص�ֵ�������丳ֵ��e*/
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	else
		*e = p->date;
	return OK;
}

int LocateElem(LinkList L, ElemType e)/*������L�У�Ѱ�ҵ�һ����e��ͬ��Ԫ�أ���������Ԫ�ص�λ��*/
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (p->date == e)
			return i;
		p = p->next;
	}
	return 0;
}

Status ListInsert(LinkList* L, int i, ElemType e)/*�ڵ�i��λ�ò���һ���µ�Ԫ��e*/
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));/*����һ���µĽڵ�*/
	s->date = e;
	s->next = p->next;
		p->next = s;
		return OK;
}

Status ListDelete(LinkList* L, int i, ElemType* e)/*ɾ����i��λ�õ�Ԫ�أ�����e������ֵ*/
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next&& j < i)
	{
		p = p->next;
			j++;
	}
	if (!(p->next) || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->date;
	free(q);
	return OK;
}

Status ListTraverse(LinkList L)/*��L�е�ÿ��Ԫ�����ν��д�ӡ*/
{
	LinkList p;
	p = L->next;
	while (p)
	{
		visit(p->date);
		p=p->next;
	}
	printf("\n");
	return OK;
}

void CreateListHead(LinkList* L, int n)//�������n��Ԫ�ص�ֵ��������ͷ���ĵ������Ա�L��ͷ�巨��
{
	LinkList p;
	int i;
	srand(time(0));;
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->date = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CreateListTail(LinkList* L, int n)//�������n��Ԫ�ص�ֵ��������ͷ���ĵ������Ա�L��β�巨��
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L= (LinkList)malloc(sizeof(Node));
	r = *L;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->date = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

int main()
{
	LinkList L;
	ElemType e;
	Status i;
	int j, k;
	i = InitList(&L);
	printf("��ʼ��L��LisrtLength(L)=%d\n", ListLength(L));
	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("��L��ͷ���β���1��5��L.date=");
	ListTraverse(L);
	printf("LisrtLength(L)=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L�Ƿ�Ϊ�գ�i=%d(1:�� 0:��)\n", i);
	i = ClearList(&L);
	printf("���L��LisrtLength(L)=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L�Ƿ�Ϊ�գ�i=%d(1:�� 0:��)\n", i);
	for (j = 1; j <= 10; j++)
	i = ListInsert(&L, j, j);
	printf("��L��β���β���1��10��L.date=");
	ListTraverse(L);
	printf("LisrtLength(L)=%d\n", ListLength(L));
	i = ListInsert(&L, 1, 0);
	printf("��L��ͷ����0��L.date=");
	ListTraverse(L);
	printf("LisrtLength(L)=%d\n", ListLength(L));
	GetElem(L, 5, &e);
	printf("�����Ԫ�ص�ֵΪ��%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("��%dԪ�ص�ֵΪ%d\n", k, j);
		else
			printf("û��ֵΪ%d��Ԫ��\n", j);
	}
	k = ListLength(L);
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e);
		if (i == ERROR)
			printf("ɾ����%d��Ԫ��ʧ��\n", j);
		else
			printf("ɾ����%d��Ԫ�ص�ֵΪ��%d\n",j,e);
	}
	printf("�������L��Ԫ�أ�");
	ListTraverse(L);
	j = 5;
	ListDelete(&L, j, &e);
	printf("ɾ����%d��Ԫ�ص�ֵΪ��%d\n", j, e);
	printf("�������L��Ԫ�أ�");
	ListTraverse(L);
	i = ClearList(&L);
	printf("\n���L��LisrtLength(L)=%d\n", ListLength(L));
	CreateListHead(&L, 20);
	printf("���崴��L��Ԫ�أ�ͷ�巨����");
	ListTraverse(L);
	i = ClearList(&L);
	printf("\n���L��LisrtLength(L)=%d\n", ListLength(L));
	CreateListTail(&L, 20);
	printf("���崴��L��Ԫ�أ�β�巨����");
	ListTraverse(L);
	return 0;
}
/*1.�����Ա���ҪƵ�����ң����ٽ��в����ɾ������ʱ���˲���˳��洢�ṹ��
  2.�����Ա��е�Ԫ�ظ����仯�Ƚϴ���߸�����֪���ж��ʱ������õ�����ṹ��*/