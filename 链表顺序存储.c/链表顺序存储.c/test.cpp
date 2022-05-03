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

typedef struct    /*  ��������*/
{
	ElemType date[MAXSIZE];
	int length;
}SqList;

Status visit(ElemType c)  /* ��ӡ����*/
{
    printf("%d ", c);
    return OK;
}

Status InitList(SqList* L)    /*��ʼ�����Ա�*/
{
	L->length = 0;
	return OK;
}

Status ListEmpty(SqList L)/*������Ա��Ƿ��ʼ���ɹ�*/
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList* L)/*������Ա�*/
{
	L->length = 0;
	return OK;
}

int ListLenght(SqList L)/*��ʾ���Ա���Ԫ�ظ���*/
{
	return L.length;
}

Status GetElem(SqList L, int i, ElemType *e)/*��ȡ���Ա��е�iλ��Ԫ��*/
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	else
		*e = L.date[i - 1];
	return OK;
}

int LocateElem(SqList L, ElemType e)/*�������Ա��е�һ����e��ͬԪ�ص�λ��*/
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

Status ListInsert(SqList* L, int i, ElemType e)/*�����Ա��е�iλ����Ԫ��e*/
{
	int k;
	if (L->length == MAXSIZE)
		return ERROR;
	if (i<1 || i>L->length+1)/*ע������һ��Ҫ��i > L->length+1,������i > L->length����Ϊ�ڴ�֮ǰlength=0����Ҫ����Ļ���
							 ��Ҫ�ڵ�һλ����i=1�ĵط������Ϊi > L->length�Ļ�����������ͻ������ﱨ���˳���*/
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

Status ListDelete(SqList* L, int i, ElemType *e)/*ɾ�����Ա��е�iλԪ�أ�����e������ֵ*/
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

Status ListTraverse(SqList L)/*���ζ����Ա��е�Ԫ�ؽ������*/
{
	int i;
	for (i = 0; i <= L.length - 1; i++)
		visit(L.date[i]);
	printf("\n");
	return OK;
}

void unionL(SqList* La, SqList Lb)/*����Lb�ж�����La�е�Ԫ�ز��뵽La��*/
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
	printf("��ʼ����L.length=%d\n", L.length);
	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("��L�ı�ͷ����1-5��L.date=");
	ListTraverse(L);
	printf("L.length=%d\n", L.length);
	i = ListEmpty(L);
	printf("L�Ƿ�Ϊ�գ�i=%d��1���� 0����\n", i);
	i = ClearList(&L);
	printf("���L��L.length=%d\n", L.length);
	i = ListEmpty(L);
	printf("L�Ƿ�Ϊ�գ�i=%d��1���� 0����\n", i);
	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("�ڱ�β���β���1-10��L.date=");
	ListTraverse(L);
	printf("L.length=%d\n", L.length);
	ListInsert(&L, 1, 0);
	printf("�ڱ�ͷ����0��L.date=");
	ListTraverse(L);
	printf("L.length=%d\n", L.length);
	GetElem(L, 5, &e);
	printf("��5��Ԫ�ص�ֵΪ % d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
		else
			printf("û��ֵΪ%d��Ԫ��\n", j);
	}
	k = ListLenght(L);
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e);
		if (i == ERROR)
			printf("ɾ����%d������ʧ��\n", j);
		else
			printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
	}
	printf("�������L��Ԫ�أ�");
	ListTraverse(L);
	j = 5;
	ListDelete(&L, j, &e);
	printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
	printf("�������L��Ԫ�أ�");
	ListTraverse(L);
	i = InitList(&Lb);
	for (j = 6; j <= 15; j++)
		i = ListInsert(&Lb, 1, j);
	unionL(&L, Lb);
	printf("��������ϲ���Lb��L��Ԫ�أ�");
		ListTraverse(L);
	return 0;
}