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
	printf("请按层序输入节点的值（整形），0表示空节点，输入999结束。节点数≤%d：\n", MAX_TREE_SIZE);
	while (i < 10)
	{
		T[i] = i + 1;
		if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil)
		//子节点（p)与父节点（i）的关系：i=(p+1)/2-1
		{
			printf("出现无双亲的非根节点%d/n", T[i]);
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
//在顺序存储结构中，两个函数的实现原理是相同的，所以可以 这样定义

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
	//深度为k的二叉树之多有2^k-1个节点
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
	printf("建立二叉树后，树空否？%d（1:是 0:否）树的深度=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
	i = Root(T, &e);
	if (i)
	{
		printf("二叉树的根为：%d\n", e);
	}
	else
	{
		printf("空树，无根\n");
	}
	return 0;
}