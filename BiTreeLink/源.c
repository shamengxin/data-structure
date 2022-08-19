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

//���ڹ��������
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
//��һ��BiTree��ָ�룬ָ������ڵ�

//����ն�����
Status InitBiTree(BiTree* T)
{
	*T = NULL;
	return OK;
}

//���ٶ�����
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

//#��ʾ�գ�������������ʾ������T
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

//�ж϶������Ƿ�Ϊ��
Status BiTreeEmpty(BiTree T)
{
	if (T)
		return FALSE;
	else
		return TRUE;
}

//��ն�����
#define ClearBiTree DestroyBiTree
//��պ����ٲ�������ͬ��

//��ѯ�����������
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

//���ض������ĸ�
TElemType Nil = ' ';//�ַ����Կո��Ϊ��
TElemType Root(BiTree T)
{
	if (BiTreeEmpty(T))
		return Nil;
	else
		return T->data;

}

//����p��ָ��Ľ���ֵ
TElemType Value(BiTree p)
{
	return p->data;
}

//��p��ָ��Ľ�㸳ֵ
void Assign(BiTree p, TElemType value)
{
	p->data = value;
}

//ǰ�����
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//�������
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PreOrderTraverse(T->lchild);
	printf("%c", T->data);
	PreOrderTraverse(T->rchild);
}

//�������
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
	printf("����ն����������շ�%d(1���� 0����)\n", BiTreeEmpty(T));
	printf("�������=%d\n", BiTreeDepth(T));
	e = Root(T);
	printf("�������ĸ�Ϊ��%c\n", e);
	printf("ǰ�������������");
	PreOrderTraverse(T);
	printf("\n���������������");
	InOrderTraverse(T);
	printf("\n���������������");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n��������������շ�%d(1���� 0����)\n", BiTreeEmpty(T));
	printf("�������=%d\n", BiTreeDepth(T));
	if (!Root(T))
	{
		printf("���գ��޸�\n");
	}
	return 0;
}