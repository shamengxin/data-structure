#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#define OK 1
#define ERROR 0
#define MAX_TREE_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int TElemType;
typedef TElemType SqBiTree[MAX_TREE_SIZE];

TElemType Nil = 0;

Status visit(TElemType c)
{
	printf("%d", c);
	return OK;
}

Status InitBiTree(SqBiTree T)
{
	int i;
	for (i = 0; i < MAX_TREE_SIZE; i++)
	{
		T[i] = Nil;
	}
	return OK;
}

Status CreateBiTree(SqBiTree T)
{
	int i = 0;
	printf("�밴��������ڵ��ֵ�����Σ���0��ʾ�սڵ㣬����999�������ڵ�����%d��\n", MAX_TREE_SIZE);
	while (i < 10)
	{
		T[i] = i + 1;
		if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil)
		//�ӽڵ㣨p)�븸�ڵ㣨i���Ĺ�ϵ��i=(p+1)/2-1
		{
			printf("������˫�׵ķǸ��ڵ�%d/n", T[i]);
			exit(ERROR);
		}
		i++;
	}
	while (i < MAX_TREE_SIZE)
	{
		T[i] = Nil;
		i++;
	}
	return OK;
}

#define ClearBiTree InitBiTree
//��˳��洢�ṹ�У�����������ʵ��ԭ������ͬ�ģ����Կ��� ��������

Status BiTreeEmpty(SqBiTree T)
{
	if (T[0] == Nil)
		return TRUE;
	else
		return FALSE;
}

int BiTreeDepth(SqBiTree T)
{
	int i, j = -1;
	for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
	{
		if (T[i] != Nil)
			break;
	}
	i++;
	do
		j++;
	while (i >= pow(2, j)-1);
	//���Ϊk�Ķ�����֮����2^k-1���ڵ�
	return j;
}

Status Root(SqBiTree T, TElemType* e)
{
	if (BiTreeEmpty(T))
		return ERROR;
	else
	{
		*e = T[0];
		return OK;
	}
}

int main()
{
	int i;
	TElemType e;
	SqBiTree T;
	InitBiTree(T);
	CreateBiTree(T);
	printf("���������������շ�%d��1:�� 0:���������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
	i = Root(T, &e);
	if (i)
	{
		printf("�������ĸ�Ϊ��%d\n", e);
	}
	else
	{
		printf("�������޸�\n");
	}
	return 0;
}