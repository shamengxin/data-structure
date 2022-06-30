#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int SElemType;
typedef int Status;


typedef struct//�����ṹ
{
	SElemType date[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

Status InitStack(SqDoubleStack* S)//��ʼ��ջ
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

Status Push(SqDoubleStack* S, SElemType e, int StackNumber)
{
	if (S->top1 + 1 == S->top2)
		return ERROR;
	if (StackNumber == 1)
		S->date[++S->top1] = e;
	if (StackNumber == 2)
		S->date[--S->top2] = e;
	return OK;
}

Status visit(SElemType c)
{
	printf("%d ", c);
	return OK;
}
Status StackTraverse(SqDoubleStack S)
{
	int i;
	i = 0;
	while (i <= S.top1)
	{
		visit(S.date[i++]);
	}
	i = S.top2;
	while (i < MAXSIZE)
	{
		visit(S.date[i++]);
	}
	printf("\n");
	return OK;
}

Status Pop(SqDoubleStack* S, SElemType* e, int StackNumber)
{
	if (StackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR;
		*e = S->date[S->top1--];
	}
	else if (StackNumber == 2)
	{
		if (S->top2 == MAXSIZE)
			return ERROR;
		*e = S->date[S->top2++];
	}
	return OK;
}
int StackLength(SqDoubleStack S)
{
	return (S.top1 + 1) + (MAXSIZE - S.top2);
}

Status StackEmpty(SqDoubleStack S)
{
	if (S.top1 == -1 && S.top2 == MAXSIZE)
		return TRUE;
	else
		return FALSE;
}
Status ClearStack(SqDoubleStack* S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}
int main()
{
	int j;
	SElemType e;
	SqDoubleStack s;
	if (InitStack(&s) == OK)
	{
		for (j = 1; j <= 5; j++)
			Push(&s, j, 1);
		for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
			Push(&s, j, 2);
	}
	printf("ջ��Ԫ������Ϊ��");
	StackTraverse(s);
	printf("��ǰջ��Ԫ���У�%d\n", StackLength(s));
	Pop(&s, &e, 2);
	printf("����ջ��Ԫ��e=%d\n", e);
	printf("ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
	for (j = 6; j <= MAXSIZE - 2; j++)
		Push(&s, j, 1);
	printf("ջ��Ԫ������Ϊ��");
		StackTraverse(s);
	printf("ջ����%d(1:�� 0:��)\n", Push(&s, 100, 1));
	ClearStack(&s);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
	return 0;
}