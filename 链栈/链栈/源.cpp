#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;

typedef struct StackNode//创建节点
{
	SElemType date;
	struct StackNode* next;
}StackNode,*LinkStackPtr;
typedef struct//创建链表
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status InitStack(LinkStack* S)//对链表进行初始化
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S->top)
		return ERROR;
	S->top = NULL;
	S->count = 0;
	return OK;
}

Status Push(LinkStack* S, SElemType e)//入栈
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->date = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
}

Status visit(SElemType e)//打印
{
	printf("%d ", e);
	return OK;
}

Status StackTraverse(LinkStack S)//打印整个链表
{
	LinkStackPtr p;
	p= S.top;
	while (p)
	{
		visit(p->date);
		p = p->next;

	}
	printf("\n");
	return OK;
}

Status StackEmpty(LinkStack S)//检查链表是否为空
{
	if (S.count == 0)
		return TRUE;
	else
		return FALSE;
}

Status Pop(LinkStack* S, SElemType* e)//出栈
{
	LinkStackPtr p;
	if (StackEmpty(*S))
		return ERROR;
	*e = S->top->date;
	p = S->top;
	S->top = p->next;
	free(p);
	S->count--;
	return OK;
}

Status GetTop(LinkStack S, SElemType* e)//获取栈顶元素
{
	if (S.top==NULL)
		return ERROR;
	else
	*e = S.top->date;
	return OK;
}

int StackLength(LinkStack S)//求栈长
{
	return S.count;
}

Status ClearStack(LinkStack* S)//清空栈
{
	LinkStackPtr p, q;
	p = S->top;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	S->count = 0;
	return OK;
}

int main()
{
	LinkStack s;
	SElemType e;
	int j;
	if (InitStack(&s) == OK)
		for (j = 1; j <= 10; j++)
			Push(&s, j);
	printf("栈中元素依次为：");
	StackTraverse(s);
	Pop(&s, &e);
	printf("弹出栈顶元素e=%d\n", e);
	printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("栈顶元素e=%d 栈的长度为%d\n", e, StackLength(s));
	ClearStack(&s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	return 0;
}