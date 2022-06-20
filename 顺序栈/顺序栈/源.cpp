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

typedef struct//�����ṹ
{
	SElemType date[MAXSIZE];
	int top;
}SqStack;

Status InitStack(SqStack* S)//���г�ʼ��
{
	S->top = -1;
	return OK;

}

Status Push(SqStack* S, SElemType e)//������ջ����
{
	if (S->top == MAXSIZE - 1)
	{
		return ERROR;
	}
	S->top++;
	S->date[S->top] = e;
	return OK;
}

Status visit(SElemType e)/*��ӡ*/
{
	printf("%d ", e);
	return OK;
}
Status StackTraverse(SqStack S)//��ӡ����ջ��Ԫ��
{
	int i = 0;
	while (i <= S.top)
	{
		visit(S.date[i++]);
	}
	printf("\n");
	return OK;
}

Status Pop(SqStack* S, SElemType* e)//ɾ��ջ��Ԫ�أ�����e������ֵ
{
	if (S->top == -1)
	{
		return ERROR;
	}
	*e = S->date[S->top];
	S->top--;
	return OK;
}

Status StackEmpty(SqStack S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S.top == -1)
	{
		return TRUE;
	}
	else
		return FALSE;
}

Status GetTop(SqStack S, SElemType* e)//��ȡջ��Ԫ��
{
	if (S.top == -1)
		return ERROR;
	else
	*e = S.date[S.top];
	return OK;
}

int StackLength(SqStack S)//��ջ�е�Ԫ�ظ���
{
	return(S.top + 1);
}

Status ClearStack(SqStack* S)//���ջ
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
		printf("ջ��Ԫ������Ϊ��");
		StackTraverse(s);
		Pop(&s, &e);
		printf("����ջ����Ԫ��e=%d\n", e);
		printf("ջ�Ƿ�Ϊ�գ�%d(1:�� 0���ǿգ�\n", StackEmpty(s));
		GetTop(s, &e);
		printf("ջ��Ԫ��e=%d ջ�ĳ���Ϊ��%d\n", e, StackLength(s));
		ClearStack(&s);
		printf("���ջ��ջ�Ƿ�Ϊ�գ�%d(1:�� 0���ǿգ�\n", StackEmpty(s));
		return 0;
	}
}