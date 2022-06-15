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

typedef struct Node/*定义节点*/
{
	ElemType date;
	struct Node* next;
}Node;
typedef struct Node* LinkList;/*LinkLIst一种类型，为struct Node**/

Status InitList(LinkList* L)/*初始化线性表*/
{
	*L = (LinkList)malloc(sizeof(Node));/*产生头节点，并使L指向此头节点*/
	if (!(*L))
		return ERROR;
	(*L)->next = NULL;
	return OK;
}

Status ListEmpty(LinkList L)/*检测L是否为空*/
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

Status visit(ElemType c)/*打印函数*/
{
	printf(" % d ", c);
	return OK;
}

Status ClearList(LinkList* L)/*将链表L清空，即删除所有节点，只剩一个头节点*/
{
	LinkList p, q;
	p = (*L)->next;/*指向第一个节点*/
	while (p)/*判断是否到达表尾*/
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

int ListLength(LinkList L)/*计算L中元素个数*/
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

Status GetElem(LinkList L, int i, ElemType* e)/*获取链表中第i个元素的值，并将其赋值给e*/
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

int LocateElem(LinkList L, ElemType e)/*在链表L中，寻找第一个与e相同的元素，并返回其元素的位序*/
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

Status ListInsert(LinkList* L, int i, ElemType e)/*在第i个位置插入一个新的元素e*/
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
	s = (LinkList)malloc(sizeof(Node));/*创建一个新的节点*/
	s->date = e;
	s->next = p->next;
		p->next = s;
		return OK;
}

Status ListDelete(LinkList* L, int i, ElemType* e)/*删除第i个位置的元素，并用e返回其值*/
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

Status ListTraverse(LinkList L)/*对L中的每个元素依次进行打印*/
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

void CreateListHead(LinkList* L, int n)//随机产生n个元素的值，建立带头结点的单链线性表L（头插法）
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

void CreateListTail(LinkList* L, int n)//随机产生n个元素的值，建立带头结点的单链线性表L（尾插法）
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
	printf("初始化L后：LisrtLength(L)=%d\n", ListLength(L));
	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("在L表头依次插入1～5后：L.date=");
	ListTraverse(L);
	printf("LisrtLength(L)=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L是否为空：i=%d(1:是 0:否)\n", i);
	i = ClearList(&L);
	printf("清空L后：LisrtLength(L)=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L是否为空：i=%d(1:是 0:否)\n", i);
	for (j = 1; j <= 10; j++)
	i = ListInsert(&L, j, j);
	printf("在L表尾依次插入1～10后：L.date=");
	ListTraverse(L);
	printf("LisrtLength(L)=%d\n", ListLength(L));
	i = ListInsert(&L, 1, 0);
	printf("在L表头插入0后：L.date=");
	ListTraverse(L);
	printf("LisrtLength(L)=%d\n", ListLength(L));
	GetElem(L, 5, &e);
	printf("第五个元素的值为：%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("第%d元素的值为%d\n", k, j);
		else
			printf("没有值为%d的元素\n", j);
	}
	k = ListLength(L);
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e);
		if (i == ERROR)
			printf("删除第%d个元素失败\n", j);
		else
			printf("删除第%d个元素的值为：%d\n",j,e);
	}
	printf("依次输出L的元素：");
	ListTraverse(L);
	j = 5;
	ListDelete(&L, j, &e);
	printf("删除第%d个元素的值为：%d\n", j, e);
	printf("依次输出L的元素：");
	ListTraverse(L);
	i = ClearList(&L);
	printf("\n清空L后：LisrtLength(L)=%d\n", ListLength(L));
	CreateListHead(&L, 20);
	printf("整体创建L的元素（头插法）：");
	ListTraverse(L);
	i = ClearList(&L);
	printf("\n清空L后：LisrtLength(L)=%d\n", ListLength(L));
	CreateListTail(&L, 20);
	printf("整体创建L的元素（尾插法）：");
	ListTraverse(L);
	return 0;
}
/*1.若线性表需要频繁查找，很少进行插入和删除操作时，宜采用顺序存储结构。
  2.当线性表中的元素个数变化比较大或者根本不知道有多大时，最好用单链表结构。*/