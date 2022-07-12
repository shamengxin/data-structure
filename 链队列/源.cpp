#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1

typedef int QElemType;
typedef int Status;

typedef struct QNode//����ڵ�
{
	QElemType date;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front, rear;
}LinkQueue;

Status InitQueue(LinkQueue* Q)//��ʼ��
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		return ERROR;
	Q->front->next = NULL;
	return OK;
}

Status QueueEmpty(LinkQueue Q)//�ж϶����Ƿ�Ϊ��
{
	if (Q.front == Q.rear)
		return OK;
	else
		return ERROR;
}

int QueueLength(LinkQueue Q)//����г���
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

Status EnQueue(LinkQueue* Q, QElemType e)//����Ԫ��
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

Status visit(QElemType e)/*��ӡԪ��*/
{
	printf("%d ", e);
	return OK;
}
Status QueueTraverse(LinkQueue Q)//��ӡ��������
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
Status GetHead(LinkQueue Q, QElemType* e)//��ȡ��ͷԪ��
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->date;
	return OK;
}

Status DeQueue(LinkQueue* Q, QElemType* e)//ɾ������Ԫ��
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

Status ClearQueue(LinkQueue* Q)//��ն���
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

Status DestroyQueue(LinkQueue* Q)//���ٶ���
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
		printf("�ɹ��Ĺ�����һ���ն��У�\n");
	printf("�Ƿ�ն��У�%d(1:�� 0:��)\n", QueueEmpty(q));
	printf("���еĳ���Ϊ%d\n", QueueLength(q));
	EnQueue(&q, -5);
	EnQueue(&q, 5);
	EnQueue(&q, 10);
	printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n", QueueLength(q));
	printf("�Ƿ�ն��У�%d(1:�� 0:��)\n", QueueEmpty(q));
	printf("���е�Ԫ������Ϊ��");
	QueueTraverse(q);
	i = GetHead(q, &e);
	if (i == OK)
	{
		printf("��ͷԪ����%d\n", e);
		DeQueue(&q, &e);
		printf("ɾ���˶�ͷԪ��%d\n", e);
		i = GetHead(q, &e);
		if (i == OK)
			printf("��ͷԪ����%d\n", e);
		ClearQueue(&q);
		printf("��ն��к�q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
		DestroyQueue(&q);
		printf("���ٶ��к�q.front=%u q.rear=%u\n", q.front, q.rear);
	}
	return 0;
}