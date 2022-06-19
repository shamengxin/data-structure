#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAXSIZE 1000//分配储存空间
#define OK 1
#define ERROR 0
typedef char ElemType;
typedef int Status;
typedef struct Component
{
	ElemType date;
	int cur;//游标，为0时表示无指向
}StaticLinkList[MAXSIZE];/*将结构体的名字重新定义为StaticLinkList*/

Status visit(ElemType e)/*打印*/
{
	printf("%c", e);
	return OK;
}

int Malloc_SSL(StaticLinkList L)/*获取备用链表（空闲空间）的下标*/
{
	int i;
	i = L[0].cur;
	if (L[0].cur)
		L[0].cur = L[i].cur;/*将备用链表（空闲空间）的下标进行更改*/
	return i;
}

Status Free_SSL(StaticLinkList L, int i)/*回收结点*/
{
	L[i].cur = L[0].cur;
	L[0].cur = i;
	return OK;
}

Status InitList(StaticLinkList L)//初始化链表
{
	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		L[i].cur = i + 1;
		L[MAXSIZE - 1].cur = 0;//链表的最后一个元素cur用来存放第一个插入元素的下标，相当于头结点
	}
	return OK;
}

int ListLength(StaticLinkList L)/*计算链表元素个数*/
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

Status ListInsert(StaticLinkList L, int i, ElemType e)/*在链表的第i个位置插入数据e*/
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

Status ListTraverse(StaticLinkList L)/*打印整个链表*/
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

Status ListDelete(StaticLinkList L, int i)/*删除第i个元素*/
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
	printf("初始化后L后：L.length=%d\n", ListLength(L));
	i = ListInsert(L, 1, 'F');
	i = ListInsert(L, 1, 'E');
	i = ListInsert(L, 1, 'D');
	i = ListInsert(L, 1, 'B');
	i = ListInsert(L, 1, 'A');
	printf("在表头依次插入FEDBA后：\nL.data=");
	ListTraverse(L);
	i = ListInsert(L, 3, 'C');
	printf("\n在L的“B”与“D”之间插入“C”后：\nL.date=");
	ListTraverse(L);
	i = ListDelete(L, 1);
	printf("\n在删除L的“A”后：\nL.date=");
	ListTraverse(L);
	printf("\n");
	return 0;
}