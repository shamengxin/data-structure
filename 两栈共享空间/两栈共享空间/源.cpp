#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int SElemType;
typedef int Status;


typedef struct//创建结构
{
	SElemType date[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

Status InitStack(SqDoubleStack* S)//初始化栈
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
	printf("栈中元素依次为：");
	StackTraverse(s);
	printf("当前栈中元素有：%d\n", StackLength(s));
	Pop(&s, &e, 2);
	printf("弹出栈顶元素e=%d\n", e);
	printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	for (j = 6; j <= MAXSIZE - 2; j++)
		Push(&s, j, 1);
	printf("栈中元素依次为：");
		StackTraverse(s);
	printf("栈满否：%d(1:否 0:满)\n", Push(&s, 100, 1));
	ClearStack(&s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	return 0;
}