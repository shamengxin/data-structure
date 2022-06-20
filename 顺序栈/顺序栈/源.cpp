#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;

typedef struct//创建结构
{
	SElemType date[MAXSIZE];
	int top;
}SqStack;

Status InitStack(SqStack* S)//进行初始化
{
	S->top = -1;
	return OK;

}

Status Push(SqStack* S, SElemType e)//进行入栈操作
{
	if (S->top == MAXSIZE - 1)
	{
		return ERROR;
	}
	S->top++;
	S->date[S->top] = e;
	return OK;
}

Status visit(SElemType e)/*打印*/
{
	printf("%d ", e);
	return OK;
}
Status StackTraverse(SqStack S)//打印整个栈中元素
{
	int i = 0;
	while (i <= S.top)
	{
		visit(S.date[i++]);
	}
	printf("\n");
	return OK;
}

Status Pop(SqStack* S, SElemType* e)//删除栈顶元素，并用e返回其值
{
	if (S->top == -1)
	{
		return ERROR;
	}
	*e = S->date[S->top];
	S->top--;
	return OK;
}

Status StackEmpty(SqStack S)//判断栈是否为空
{
	if (S.top == -1)
	{
		return TRUE;
	}
	else
		return FALSE;
}

Status GetTop(SqStack S, SElemType* e)//获取栈顶元素
{
	if (S.top == -1)
		return ERROR;
	else
	*e = S.date[S.top];
	return OK;
}

int StackLength(SqStack S)//求栈中的元素个数
{
	return(S.top + 1);
}

Status ClearStack(SqStack* S)//清空栈
{
	S->top = -1;
	return OK;
}
int main()
{
	SqStack s;
	int j;
	SElemType e;
	if (InitStack(&s) == OK)
	{
		for (j = 1; j <= 10; j++)
			Push(&s, j);
		printf("栈中元素依次为：");
		StackTraverse(s);
		Pop(&s, &e);
		printf("弹出栈顶的元素e=%d\n", e);
		printf("栈是否为空：%d(1:空 0：非空）\n", StackEmpty(s));
		GetTop(s, &e);
		printf("栈顶元素e=%d 栈的长度为：%d\n", e, StackLength(s));
		ClearStack(&s);
		printf("清空栈后，栈是否为空：%d(1:空 0：非空）\n", StackEmpty(s));
		return 0;
	}
}