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
//定义串结构
typedef struct
{
	char ch[MAXSIZE + 1];
	int length;
}SString;

//对串T进行赋值
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


//对串S进行拷贝
Status StrCopy(SString* T, SString S)
{
	int i;
	T->length =S.length;
	for (i = 0; i < S.length; i++)
		T->ch[i] = S.ch[i];
	return OK;
}

//检测串是否为空
Status StrEmpty(SString S)
{
	if (S.length == 0)
		return TRUE;
	else
		return FALSE;
}

//比较串S和串T的大小
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

//求串长
int StrLenght(SString S)
{
	return S.length;
}

//连接串s1和s2，并用串T返回
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

//清空串
Status ClearString(SString* S)
{
	S->length = 0;
	return OK;
}

//用串Sub返回串S的第pos个字符起长度为len的子串
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
//删除串S的第pos个字符起长度为len的子串
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

//在串S的第pos个字符前插入串T
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

//返回子串T在主串S中的pos个字符之后的位置，若不存在返回0
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

//用V替换主串S中出现的所有于T相等的不重叠的子串
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

//对串进行打印
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
	printf("请输入串s1:");
	k = StrAssign(&s1, "abcd");
	if (!k)
	{
		printf("串长超过MAXSIZE(=%d)\n", MAXSIZE);
		exit(0);
	}
	StrPrint(s1);
	printf("串长为%d，串空否？%d(1:是 0:否）\n", StrLenght(s1), StrEmpty(s1));
	StrCopy(&s2, s1);
	printf("拷贝s1生成的串为：");
	StrPrint(s2);
	k = StrAssign(&s2, "efghijk");
	if (!k)
	{
		printf("串长超过MAXSIZE(=%d)\n", MAXSIZE);
		exit(0);
	}
	k = StrCompare(s1, s2);
	printf("串1和串2的比较结果为：%d(-1:小于,0:等于,1:大于)\n", k);
	k = Concat(&t, s1, s2);
	printf("串s1连接串s2得到的串t为：");
	StrPrint(t);
	if (k == FALSE)
		printf("串t有截断/n");
	ClearString(&s1);
	printf("清为空串后，串s1为：");
	StrPrint(s1);
	printf("串长为%d，串空否？%d(1:是 0:否）\n", StrLenght(s1), StrEmpty(s1));
	printf("求串t的字串，请输入字串的起始位置，字串的长度：");
	i = 2;
	j = 3;
	printf("%d,%d\n", i, j);
	k = SubString(&s2, t, i, j);
	if (k)
	{
		printf("字串s2为：");
		StrPrint(s2);
	}
	printf("从串t的第pos个字符起，删除len个字符，请输入pos，len：");
	i = 4;
	j = 2;
	printf("%d,%d\n", i, j);
	StrDelete(&t, i, j);
	printf("删除后的串t为：");
	StrPrint(t);
	i = StrLenght(s2) / 2;
	StrInsert(&s2, i, t);
	printf("在串s2的第%d个字符之前插入串t后，串s2为:", i);
	StrPrint(s2);
	i = Index(s2, t, 1);
	printf("s2的第%d个字母起和t第一次匹配\n", i);
	SubString(&t, s2, 1, 1);
	printf("串t为：");
	StrPrint(t);
	Concat(&s1, t, t);
	printf("串s1为：");
	StrPrint(s1);
	Replace(&s2, t, s1);
	printf("用串s1取代串s2中和串t相同的不重叠的串后，串s2为：");
	StrPrint(s2);
	return 0;
}