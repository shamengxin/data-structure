#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define MAXSIZE 100


typedef int Status;
typedef char TElemType;

//用于构造二叉树
int treeIndex = 1;
typedef char String[24];
String str;
Status StrAssign(String T, char* chars)
{
	int i;
	if (strlen(chars) > MAXSIZE)
	{
		return ERROR;
	}
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
		{
			T[i] = *(chars + i - 1);
		}
		return OK;
	}
}
//==============================================
Status visit(TElemType e)
{
	printf("%c", e);
	return OK;
}

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
//有一个BiTree的指针，指向这个节点

//构造空二叉树
Status InitBiTree(BiTree* T)
{
	*T = NULL;
	return OK;
}

//销毁二叉树
void DestroyBiTree(BiTree* T)
{
	if (*T)
	{
		if ((*T)->lchild)
			DestroyBiTree(&(*T)->lchild);
		if ((*T)->rchild)
			DestroyBiTree(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
}

//#表示空，构造二叉链表表示二叉数T
void CreateBiTree(BiTree* T)
{
	TElemType ch;
	ch = str[treeIndex++];

	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild); 
		CreateBiTree(&(*T)->rchild); 
	}
}

//判断二叉树是否为空
Status BiTreeEmpty(BiTree T)
{
	if (T)
		return FALSE;
	else
		return TRUE;
}

//清空二叉树
#define ClearBiTree DestroyBiTree
//清空和销毁操作是相同的

//查询二叉树的深度
int BiTreeDepth(BiTree T)
{
	int i, j;
	if (!T)
	{
		return 0;
	}
	if (T->lchild)
		i = BiTreeDepth(T->lchild);
	else
		i = 0;
	if (T->rchild)
		j = BiTreeDepth(T->rchild);
	else
		j = 0;
	return i > j ? i + 1 : j + 1;
}

//返回二叉树的根
TElemType Nil = ' ';//字符型以空格符为空
TElemType Root(BiTree T)
{
	if (BiTreeEmpty(T))
		return Nil;
	else
		return T->data;

}

//返回p所指向的结点的值
TElemType Value(BiTree p)
{
	return p->data;
}

//给p所指向的结点赋值
void Assign(BiTree p, TElemType value)
{
	p->data = value;
}

//前序遍历
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//中序遍历
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PreOrderTraverse(T->lchild);
	printf("%c", T->data);
	PreOrderTraverse(T->rchild);
}

//后序遍历
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
	printf("%c", T->data);
}

int main()
{
	BiTree T;
	TElemType e;
	InitBiTree(&T);
	StrAssign(str, "ABDH#K###E##CFI###G#J##");
	CreateBiTree(&T);
	printf("构造空二叉树后，树空否？%d(1：是 0：否)\n", BiTreeEmpty(T));
	printf("树的深度=%d\n", BiTreeDepth(T));
	e = Root(T);
	printf("二叉树的根为：%c\n", e);
	printf("前序遍历二叉树：");
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树：");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树：");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n清除二叉树后，树空否？%d(1：是 0：否)\n", BiTreeEmpty(T));
	printf("树的深度=%d\n", BiTreeDepth(T));
	if (!Root(T))
	{
		printf("树空，无根\n");
	}
	return 0;
}