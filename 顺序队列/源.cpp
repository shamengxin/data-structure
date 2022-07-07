#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int QElemType;
typedef int Status;

typedef struct//����ṹ
{
	QElemType date[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue* Q)//��ʼ��
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

Status QueueEmpty(SqQueue Q)//����Ƿ�Ϊ��
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}
Status EnQueue(SqQueue* Q, QElemType e)//����
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->date[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 0;
}

int QueueLength(SqQueue Q)//����г���
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status DeQueue(SqQueue* Q, QElemType* e)//ɾ��
{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->date[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

Status visit(QElemType e)//��ӡԪ��
{
	printf("%d ",e);
	return OK;
}

Status QueueTraverse(SqQueue Q)//��ӡ��������
{
	int i;
	i = Q.front;
	while (i != Q.rear)
	{
		visit(Q.date[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
	return OK;
}

Status GetHead(SqQueue Q, QElemType* e)//��ȡ����Ԫ��
{
	if (Q.front == Q.rear)
		return ERROR;
	*e = Q.date[Q.front];
	return OK;
}

Status ClearQueue(SqQueue* Q)//��ն���
{
	Q->front = Q->rear = 0;
	return OK;
}
int main()
{
	int k;
	int j;
	QElemType e;
	int i = 0;
	SqQueue Q;
	InitQueue(&Q);
	printf("��ʼ�����к󣬶����Ƿ�Ϊ�գ�%u(1:�� 0:��\n", QueueEmpty(Q));
	printf("���������ζ���Ԫ��(������%d��),-1Ϊ��ǰ��������\n",MAXSIZE - 1);
	do
	{
		/*scanf("%d", &d);*/
		e = i + 100;
		if (e == -1)
			break;
		i++;
		EnQueue(&Q, e);
	} while (i < MAXSIZE - 1);
	printf("���г���Ϊ%d\n", QueueLength(Q));
	printf("���ڶ��пշ�%u(1:�� 0:��)\n", QueueEmpty(Q));
	printf("����%d���ɶ�ͷɾ��Ԫ�أ���β����Ԫ�أ�\n", MAXSIZE);
	for (k = 1; k <= MAXSIZE; k++)
	{
		DeQueue(&Q, &e);
		printf("ɾ����Ԫ����%d,�����Ԫ�أ�%d\n",e,k+1000);
		e = k + 1000;
		EnQueue(&Q, e);
	}
	k = QueueLength(Q);
	printf("���ڶ����е�Ԫ��Ϊ��\n");
	QueueTraverse(Q);
	printf("�����β������%d��Ԫ��\n", i + MAXSIZE);
	if (k - 2 > 0)
	{
		printf("�����ɶ�ͷɾ��%d��Ԫ�أ�\n", k - 2);
		while (QueueLength(Q) > 2)
		{
			DeQueue(&Q, &e);
			printf("ɾ����Ԫ��ֵΪ%d\n", e);
		}
	}
	j = GetHead(Q, &e);
	if (j)
		printf("���ڶ�ͷԪ��Ϊ��%d\n", e);
	ClearQueue(&Q);
	printf("��ն��к󣬶��пշ�%u(1:�� 0:��)\n", QueueEmpty(Q));
	return 0;
}