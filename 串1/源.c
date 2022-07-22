#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 40
#define EQ 0
#define LT -1
#define GT 1

typedef int Status;
//���崮�ṹ
typedef struct
{
	char ch[MAXSIZE + 1];
	int length;
}SString;

//�Դ�T���и�ֵ
Status StrAssign(SString* T, char* chars)
{
	int i;
	if (strlen(chars) > MAXSIZE)
		return ERROR;
	else
	{
		T->length = strlen(chars);
		for (i = 0; i < T->length; i++)
		{
			 T->ch[i] = chars[i];
		}
		return OK;
	}
}


//�Դ�S���п���
Status StrCopy(SString* T, SString S)
{
	int i;
	T->length =S.length;
	for (i = 0; i < S.length; i++)
		T->ch[i] = S.ch[i];
	return OK;
}

//��⴮�Ƿ�Ϊ��
Status StrEmpty(SString S)
{
	if (S.length == 0)
		return TRUE;
	else
		return FALSE;
}

//�Ƚϴ�S�ʹ�T�Ĵ�С
Status StrCompare(SString T, SString S)
{
	int i;
	for (i = 0; i < T.length && i < S.length; i++)
	{
		if (T.ch[i] != S.ch[i])
		{
			if (T.ch[i] - S.ch[i] > 0)
				return GT;
			else
				return LT;
		}
	}
	if (T.length - S.length > 0)
		return GT;
	else if (T.length - S.length < 0)
		return LT;
	else
		return EQ;
}

//�󴮳�
int StrLenght(SString S)
{
	return S.length;
}

//���Ӵ�s1��s2�����ô�T����
Status Concat(SString* T, SString s1, SString s2)
{
	if (s1.length + s2.length <= MAXSIZE)
	{
		for (int i = 0; i < s1.length; i++)
		{
			T->ch[i] = s1.ch[i];
		}
		for (int i = 0; i < s2.length; i++)
		{
			T->ch[s1.length + i] = s2.ch[i];
		}
		T->length = s1.length + s2.length;
		return TRUE;
	}
	else
	{
		for (int i = 0; i < s1.length; i++)
		{
			T->ch[i] = s1.ch[i];
		}
		for (int i = 0; i < MAXSIZE-s1.length; i++)
		{
			T->ch[s1.length + i] = s2.ch[i];
		}
		T->length = MAXSIZE;
		return FALSE;
	}
}

//��մ�
Status ClearString(SString* S)
{
	S->length = 0;
	return OK;
}

//�ô�Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
Status SubString(SString* Sub, SString S, int pos, int len)
{
	if (pos<1 || pos>S.length || len<0 || pos + len>S.length)
		return ERROR;
	for (int i = 0; i < len; i++)
	{
		Sub->ch[i] = S.ch[pos - 1 + i];
	}
	Sub->length = len;
	return OK;
}
//ɾ����S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
Status StrDelete(SString* S, int pos, int len)
{
	if (pos<1 || pos>S->length || len<0 || pos + len>S->length)
		return ERROR;
	for (int i = 0; i < len; i++)
	{
		S->ch[pos - 1 + i] = S->ch[pos - 1 + len + i];
	}
	S->length -= len;
	return OK;
}

//�ڴ�S�ĵ�pos���ַ�ǰ���봮T
Status StrInsert(SString* S, int pos, SString T)
{
	if (pos<1 || pos>S->length)
		return ERROR;
	if (S->length + T.length <= MAXSIZE)
	{
		for (int i = S->length-1; i >=pos-1; i--)
		{
			S->ch[i + T.length] = S->ch[i];
		}
		for (int i = 0; i < T.length; i++)
		{
			S->ch[pos - 1 + i] = T.ch[i];
		}
		S->length += T.length;
		return TRUE;
	}
	else
	{
		for (int i = MAXSIZE-1; i >= pos - 1; i--)
		{
			int k = MAXSIZE - S->length;
			S->ch[i] = S->ch[i-k];
		}
		for (int i = 0; i < T.length; i++)
		{
			S->ch[pos - 1 + i] = T.ch[i];
		}
		S->length =MAXSIZE;
		return FALSE;
	}
}

//�����Ӵ�T������S�е�pos���ַ�֮���λ�ã��������ڷ���0
int Index(SString S, SString T, int pos)
{
	int i = pos - 1;
	int j = 0;
	while (i < S.length && i < T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j > T.length - 1)
		return i - T.length +1;
	else
		return 0;
}

//��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
Status Replace(SString* S, SString T, SString V)
{
	int i = 0;
	if (StrEmpty(T))
		return ERROR;
	do
	{
		i = Index(*S, T, i);
		if (i)
		{
			StrDelete(S, i, StrLenght(T));
			StrInsert(S, i, V);
			i += StrLenght(V);
		}
	} while (i);
	return OK;
}

//�Դ����д�ӡ
void StrPrint(SString T)
{
	int i;
	for (i = 0; i < T.length; i++)
	{
		printf("%c", T.ch[i]);
	}
	printf("\n");
}

int main()
{

	Status k;
	SString s1,s2,t;
	int i, j;
	printf("�����봮s1:");
	k = StrAssign(&s1, "abcd");
	if (!k)
	{
		printf("��������MAXSIZE(=%d)\n", MAXSIZE);
		exit(0);
	}
	StrPrint(s1);
	printf("����Ϊ%d�����շ�%d(1:�� 0:��\n", StrLenght(s1), StrEmpty(s1));
	StrCopy(&s2, s1);
	printf("����s1���ɵĴ�Ϊ��");
	StrPrint(s2);
	k = StrAssign(&s2, "efghijk");
	if (!k)
	{
		printf("��������MAXSIZE(=%d)\n", MAXSIZE);
		exit(0);
	}
	k = StrCompare(s1, s2);
	printf("��1�ʹ�2�ıȽϽ��Ϊ��%d(-1:С��,0:����,1:����)\n", k);
	k = Concat(&t, s1, s2);
	printf("��s1���Ӵ�s2�õ��Ĵ�tΪ��");
	StrPrint(t);
	if (k == FALSE)
		printf("��t�нض�/n");
	ClearString(&s1);
	printf("��Ϊ�մ��󣬴�s1Ϊ��");
	StrPrint(s1);
	printf("����Ϊ%d�����շ�%d(1:�� 0:��\n", StrLenght(s1), StrEmpty(s1));
	printf("��t���ִ����������ִ�����ʼλ�ã��ִ��ĳ��ȣ�");
	i = 2;
	j = 3;
	printf("%d,%d\n", i, j);
	k = SubString(&s2, t, i, j);
	if (k)
	{
		printf("�ִ�s2Ϊ��");
		StrPrint(s2);
	}
	printf("�Ӵ�t�ĵ�pos���ַ���ɾ��len���ַ���������pos��len��");
	i = 4;
	j = 2;
	printf("%d,%d\n", i, j);
	StrDelete(&t, i, j);
	printf("ɾ����Ĵ�tΪ��");
	StrPrint(t);
	i = StrLenght(s2) / 2;
	StrInsert(&s2, i, t);
	printf("�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t�󣬴�s2Ϊ:", i);
	StrPrint(s2);
	i = Index(s2, t, 1);
	printf("s2�ĵ�%d����ĸ���t��һ��ƥ��\n", i);
	SubString(&t, s2, 1, 1);
	printf("��tΪ��");
	StrPrint(t);
	Concat(&s1, t, t);
	printf("��s1Ϊ��");
	StrPrint(s1);
	Replace(&s2, t, s1);
	printf("�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ��󣬴�s2Ϊ��");
	StrPrint(s2);
	return 0;
}