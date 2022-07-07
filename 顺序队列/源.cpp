#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int QElemType;
typedef int Status;

typedef struct//定义结构
{
	QElemType date[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue* Q)//初始化
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

Status QueueEmpty(SqQueue Q)//检查是否为空
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}
Status EnQueue(SqQueue* Q, QElemType e)//插入
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->date[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 0;
}

int QueueLength(SqQueue Q)//求队列长度
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status DeQueue(SqQueue* Q, QElemType* e)//删除
{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->date[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

Status visit(QElemType e)//打印元素
{
	printf("%d ",e);
	return OK;
}

Status QueueTraverse(SqQueue Q)//打印整个队列
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

Status GetHead(SqQueue Q, QElemType* e)//获取队首元素
{
	if (Q.front == Q.rear)
		return ERROR;
	*e = Q.date[Q.front];
	return OK;
}

Status ClearQueue(SqQueue* Q)//清空队列
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
	printf("初始化队列后，队列是否为空？%u(1:空 0:否）\n", QueueEmpty(Q));
	printf("请输入整形队列元素(不超过%d个),-1为提前结束符：\n",MAXSIZE - 1);
	do
	{
		/*scanf("%d", &d);*/
		e = i + 100;
		if (e == -1)
			break;
		i++;
		EnQueue(&Q, e);
	} while (i < MAXSIZE - 1);
	printf("队列长度为%d\n", QueueLength(Q));
	printf("现在队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));
	printf("连续%d次由队头删除元素，队尾插入元素：\n", MAXSIZE);
	for (k = 1; k <= MAXSIZE; k++)
	{
		DeQueue(&Q, &e);
		printf("删除的元素是%d,插入的元素：%d\n",e,k+1000);
		e = k + 1000;
		EnQueue(&Q, e);
	}
	k = QueueLength(Q);
	printf("现在队列中的元素为：\n");
	QueueTraverse(Q);
	printf("共向队尾插入了%d个元素\n", i + MAXSIZE);
	if (k - 2 > 0)
	{
		printf("现在由队头删除%d个元素：\n", k - 2);
		while (QueueLength(Q) > 2)
		{
			DeQueue(&Q, &e);
			printf("删除的元素值为%d\n", e);
		}
	}
	j = GetHead(Q, &e);
	if (j)
		printf("现在队头元素为：%d\n", e);
	ClearQueue(&Q);
	printf("清空队列后，队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));
	return 0;
}