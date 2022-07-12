#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1

typedef int QElemType;
typedef int Status;

typedef struct QNode//构造节点
{
	QElemType date;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front, rear;
}LinkQueue;

Status InitQueue(LinkQueue* Q)//初始化
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		return ERROR;
	Q->front->next = NULL;
	return OK;
}

Status QueueEmpty(LinkQueue Q)//判断队列是否为空
{
	if (Q.front == Q.rear)
		return OK;
	else
		return ERROR;
}

int QueueLength(LinkQueue Q)//求队列长度
{
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status EnQueue(LinkQueue* Q, QElemType e)//插入元素
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)
		return ERROR;
	s->date = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}

Status visit(QElemType e)/*打印元素*/
{
	printf("%d ", e);
	return OK;
}
Status QueueTraverse(LinkQueue Q)//打印整个队列
{
	QueuePtr p;
	p = Q.front->next;
	while (p)
	{
		visit(p->date);
		p = p->next;
	}
	printf("\n");
	return OK;
}
Status GetHead(LinkQueue Q, QElemType* e)//获取队头元素
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->date;
	return OK;
}

Status DeQueue(LinkQueue* Q, QElemType* e)//删除队列元素
{
	if (Q->front == Q->rear)
		return ERROR;
	QueuePtr p;
	p = Q->front->next;
	*e = p->date;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}

Status ClearQueue(LinkQueue* Q)//清空队列
{
	QueuePtr p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

Status DestroyQueue(LinkQueue* Q)//销毁队列
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

int main()
{
	int i;
	QElemType e;
	LinkQueue q;
	i = InitQueue(&q);
	if (i)
		printf("成功的构造了一个空队列！\n");
	printf("是否空队列？%d(1:空 0:否)\n", QueueEmpty(q));
	printf("队列的长度为%d\n", QueueLength(q));
	EnQueue(&q, -5);
	EnQueue(&q, 5);
	EnQueue(&q, 10);
	printf("插入3个元素(-5,5,10)后,队列的长度为%d\n", QueueLength(q));
	printf("是否空队列？%d(1:空 0:否)\n", QueueEmpty(q));
	printf("队列的元素依次为：");
	QueueTraverse(q);
	i = GetHead(q, &e);
	if (i == OK)
	{
		printf("队头元素是%d\n", e);
		DeQueue(&q, &e);
		printf("删除了队头元素%d\n", e);
		i = GetHead(q, &e);
		if (i == OK)
			printf("队头元素是%d\n", e);
		ClearQueue(&q);
		printf("清空队列后，q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
		DestroyQueue(&q);
		printf("销毁队列后，q.front=%u q.rear=%u\n", q.front, q.rear);
	}
	return 0;
}