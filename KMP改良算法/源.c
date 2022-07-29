#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 200

typedef int Status;

//定义结构
typedef struct
{
	char ch[MAXSIZE];
	int length;
}String;

//对串T进行赋值
Status StrAssign(String* T, char* chars)
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

//清空串
Status ClearString(String* S)
{
	S->length = 0;
	return OK;
}

//对串进行打印
void StrPrint(String T)
{
	int i;
	for (i = 0; i < T.length; i++)
	{
		printf("%c", T.ch[i]);
	}
	printf("\n");
}

//输出next数组
void NextPrint(int next[], int length)
{
	int i;
	for (i = 1; i <= length; i++)
	{
		printf("%d", next[i]);
	}
	printf("\n");
}

//返回串长
int StrLength(String S)
{
	return S.length;
}

//获取next数组
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

//KMP匹配算法
int Index_KMP(String S, String T, int pos)
{
	int n = 0;
	int i = pos - 1;
	int j = 0;
	int next[255];
	get_next(T, next);
	while (i < S.length && j < T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
			printf("n=%d i=%d j=%d\n", ++n, i, j);
		}
	}
	if (j > T.length - 1)
	{
		return i - T.length + 1;
	}
	else
	{
		return 0;
	}

}

//获取nextval数组
void get_nextval(String T, int* nextval)
{
	int i, j;
	j = 0;
	i = 1;
	nextval[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			i++;
			j++;
			if (T.ch[i] != T.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
		{
			j = nextval[j];
		}
	}

}

//KMP优化匹配算法
int Index_KMP1(String S, String T, int pos)
{
	int n = 0;
	int i = pos - 1;
	int j = 0;
	int next[255];
	get_nextval (T, next);
	while (i < S.length && j < T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
			printf("n=%d i=%d j=%d\n", ++n, i, j);
		}
	}
	if (j > T.length - 1)
	{
		return i - T.length + 1;
	}
	else
	{
		return 0;
	}

}
int main()
{
	String s1, s2;
	StrAssign(&s1, "000000000200000000020000000002000000000200000000020000000001");
	printf("主串为：");
	StrPrint(s1);
	StrAssign(&s2, "0000000001");
	printf("子串为：");
	StrPrint(s2);
	printf("主串和子串在第%d个字符处首次匹配（KMP算法）\n", Index_KMP(s1, s2, 1));
	printf("主串和子串在第%d个字符处首次匹配（KMP优化算法）\n", Index_KMP1(s1, s2, 1));
	return 0;
}
//运行程序可以看到KMP优化算法的改良地点