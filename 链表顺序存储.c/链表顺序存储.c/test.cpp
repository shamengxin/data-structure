#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20
typedef int ElemType;
typedef int Status;

typedef struct    /*  定义链表*/
{
	ElemType date[MAXSIZE];
	int length;
}SqList;

Status visit(ElemType c)  /* 打印函数*/
{
    printf("%d ", c);
    return OK;
}

Status InitList(SqList* L)    /*初始化线性表*/
{
	L->length = 0;
	return OK;
}

Status ListEmpty(SqList L)/*检测线性表是否初始化成功*/
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList* L)/*清空线性表*/
{
	L->length = 0;
	return OK;
}

int ListLenght(SqList L)/*显示线性表中元素个数*/
{
	return L.length;
}

Status GetElem(SqList L, int i, ElemType *e)/*获取线性表中第i位的元素*/
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	else
		*e = L.date[i - 1];
	return OK;
}

int LocateElem(SqList L, ElemType e)/*返回线性表中第一个与e相同元素的位序*/
{
	int i;
	if (L.length == 0)
		return 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.date[i] == e)
			break;
	}
	if (i >= L.length)
	    return 0;
	return i+1;
}

Status ListInsert(SqList* L, int i, ElemType e)/*在线性表中第i位插入元素e*/
{
	int k;
	if (L->length == MAXSIZE)
		return ERROR;
	if (i<1 || i>L->length+1)/*注：这里一定要是i > L->length+1,不能是i > L->length，因为在此之前length=0，你要插入的话最
							 少要在第一位就是i=1的地方，如果为i > L->length的话，这个函数就会在这里报错并退出。*/
		return ERROR;
	if (i <= L->length)
	{
		for (k = L->length - 1; k >= i - 1; k--)
			L->date[k + 1] = L->date[k];
	}
	L->date[i - 1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList* L, int i, ElemType *e)/*删除线性表中第i位元素，并用e返回其值*/
{
	int k;
	if (L->length == 0)
		return ERROR;
	if (i<1 || i>L->length)
		return ERROR;
	if (i <= L->length)
	{
		*e = L->date[i - 1];
		for (k = i - 1; k <= L->length - 1; k++)
			L->date[k] = L->date[k + 1];
	}
	L->length--;
	return OK;
}

Status ListTraverse(SqList L)/*依次对线性表中的元素进行输出*/
{
	int i;
	for (i = 0; i <= L.length - 1; i++)
		visit(L.date[i]);
	printf("\n");
	return OK;
}

void unionL(SqList* La, SqList Lb)/*把在Lb中而不在La中的元素插入到La中*/
{
	int La_len, Lb_len, i;
	ElemType e;
	La_len = ListLenght(*La);
	Lb_len = ListLenght(Lb);
	for (i = 1; i < Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e))
			ListInsert(La, ++La_len, e);
	}
}

int main()
{
	SqList L;
	SqList Lb;
	ElemType e;
	Status i;
	int j, k;
	i = InitList(&L);
	printf("初始化后：L.length=%d\n", L.length);
	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("在L的表头插入1-5后：L.date=");
	ListTraverse(L);
	printf("L.length=%d\n", L.length);
	i = ListEmpty(L);
	printf("L是否为空：i=%d（1：是 0：否）\n", i);
	i = ClearList(&L);
	printf("清空L后：L.length=%d\n", L.length);
	i = ListEmpty(L);
	printf("L是否为空：i=%d（1：是 0：否）\n", i);
	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("在表尾依次插入1-10后：L.date=");
	ListTraverse(L);
	printf("L.length=%d\n", L.length);
	ListInsert(&L, 1, 0);
	printf("在表头插入0后：L.date=");
	ListTraverse(L);
	printf("L.length=%d\n", L.length);
	GetElem(L, 5, &e);
	printf("第5个元素的值为 % d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("第%d个元素的值为%d\n", k, j);
		else
			printf("没有值为%d的元素\n", j);
	}
	k = ListLenght(L);
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e);
		if (i == ERROR)
			printf("删除第%d个数据失败\n", j);
		else
			printf("删除第%d个的元素值为：%d\n", j, e);
	}
	printf("依次输出L的元素：");
	ListTraverse(L);
	j = 5;
	ListDelete(&L, j, &e);
	printf("删除第%d个的元素值为：%d\n",j,e);
	printf("依次输出L的元素：");
	ListTraverse(L);
	i = InitList(&Lb);
	for (j = 6; j <= 15; j++)
		i = ListInsert(&Lb, 1, j);
	unionL(&L, Lb);
	printf("依次输出合并了Lb的L的元素：");
		ListTraverse(L);
	return 0;
}