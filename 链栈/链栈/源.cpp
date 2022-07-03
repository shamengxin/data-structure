#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;

typedef struct StackNode//�����ڵ�
{
	SElemType date;
	struct StackNode* next;
}StackNode,*LinkStackPtr;
typedef struct//��������
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status InitStack(LinkStack* S)//��������г�ʼ��
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S->top)
		return ERROR;
	S->top = NULL;
	S->count = 0;
	return OK;
}

Status Push(LinkStack* S, SElemType e)//��ջ
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->date = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
}

Status visit(SElemType e)//��ӡ
{
	printf("%d ", e);
	return OK;
}

Status StackTraverse(LinkStack S)//��ӡ��������
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

Status StackEmpty(LinkStack S)//��������Ƿ�Ϊ��
{
	if (S.count == 0)
		return TRUE;
	else
		return FALSE;
}

Status Pop(LinkStack* S, SElemType* e)//��ջ
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

Status GetTop(LinkStack S, SElemType* e)//��ȡջ��Ԫ��
{
	if (S.top==NULL)
		return ERROR;
	else
	*e = S.top->date;
	return OK;
}

int StackLength(LinkStack S)//��ջ��
{
	return S.count;
}

Status ClearStack(LinkStack* S)//���ջ
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
	printf("ջ��Ԫ������Ϊ��");
	StackTraverse(s);
	Pop(&s, &e);
	printf("����ջ��Ԫ��e=%d\n", e);
	printf("ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("ջ��Ԫ��e=%d ջ�ĳ���Ϊ%d\n", e, StackLength(s));
	ClearStack(&s);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
	return 0;
}