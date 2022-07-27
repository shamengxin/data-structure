#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;

typedef struct 
{
	char ch[MAXSIZE];
	int length;
}String;

Status StrAssign(String* T, char* chars)
{
	int i;
	if (strlen(chars) > MAXSIZE)
		return ERROR;
	else
	{
		T->length = strlen(chars);
		for (i = 0; i < T->length; i++)
			T->ch[i] = chars[i];
	}
	return OK;
}

Status ClearString(String* S)
{
	S->length = 0;
	return OK;
}

void StrPrint(String T)
{
	int i;
	for (i = 0; i < T.length; i++)
	{
		printf("%c", T.ch[i]);
	}
	printf("\n");
}

int StrLength(String S)
{
	return S.length;
}

int Index(String S, String T, int pos)
{
	int i = pos-1;
	int j = 0;
	while (i < S.length && j < T.length)
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
		return i - T.length+1;
	else
		return 0;
}

void get_next(String T, int* next)
{
	int i, j;
	j = 0;
	i = 1;
	next[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
	
}

void NextPrint(int next[], int length)
{
	int i;
	for (i = 1; i <= length; i++)
	{
		printf("%d", next[i]);
	}
	printf("\n");
}

int Index_KMP(String S, String T, int pos)
{
	int i = pos - 1;
	int j = 0;
	int next[255];
	get_next(T, next);
	while (i < S.length && j < T.length)
	{
		if (j==0||S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > T.length - 1)
	{
		return i - T.length+1;
	}
	else
	{
		return 0;
	}
	
}
int main()
{
	int i,*p;
	String s1, s2;
	StrAssign(&s1, "abcdex");
	printf("子串为：");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc(i * sizeof(int));
	get_next(s1, p);
	printf("Next为：");
	NextPrint(p, StrLength(s1));
	StrAssign(&s1, "ababaaaba");
	printf("子串为：");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc(i * sizeof(int));
	get_next(s1, p);
	printf("Next为：");
	NextPrint(p, StrLength(s1));
	StrAssign(&s1, "aaaaaaaab");
	printf("子串为：");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc(i * sizeof(int));
	get_next(s1, p);
	printf("Next为：");
	NextPrint(p, StrLength(s1));
	StrAssign(&s1, "ababaaaba");
	printf("子串为：");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc(i * sizeof(int));
	get_next(s1, p);
	printf("Next为：");
	NextPrint(p, StrLength(s1));
	StrAssign(&s1, "0000000000000000001");
	printf("主串为：");
	StrPrint(s1);
	StrAssign(&s2, "00000001");
	printf("子串为：");
	StrPrint(s2);
	printf("主串和子串在第%d个字符处首次匹配（朴素模式匹配算法）\n", Index(s1, s2, 1));
	printf("主串和子串在第%d个字符处首次匹配（KMP算法）\n", Index_KMP(s1, s2, 1));
	StrAssign(&s1, "98637213720201739");
	printf("主串为：");
	StrPrint(s1);
	StrAssign(&s2, "202017");
	printf("子串为：");
	StrPrint(s2);
	printf("主串和子串在第%d个字符处首次匹配（朴素模式匹配算法）\n", Index(s1, s2, 1));
	printf("主串和子串在第%d个字符处首次匹配（KMP算法）\n", Index_KMP(s1, s2, 1));
	return 0;
}