#define  _CRT_SECURE_NO_WARNINGS 1
#include"String2.h"
#include<string.h>
//初始化堆字符串
void InitString_H(HString* str)
{
	str->ch = NULL;
	str->length = 0;
}

//对串str进行赋值操作，值为chars
Status StrAssign_H(HString* str, char* chars)
{
	int len = strlen(chars);
	if (!len)
	{
		return ERROR;
	}
	InitString_H(str);
	str->ch = (char*)malloc(len*sizeof(char));//这里的len*是申请len个同样字节大小的空间
	if (!str->ch)
	{
		exit(EOVERFLOW);
	}
	for (int i = 0; i < len; i++)
	{
		str->ch[i] = chars[i];
	}
	str->length = len;
	return OK;
}

//打印堆字符串
void PrintHString(HString* str)
{
	if (!str->ch || str->length == 0)
	{
		printf("堆字符串为空！\n");
	}
	for (int i = 0; i < str->length; i++)
	{
		printf("%c", str->ch[i]);
	}
	printf("\n");
}

//将串str1中的内容复制到串str2
Status StrCopy_H(HString* str1, HString* str2)
{
	InitString_H(str2);
	if (IsEmpty_H(str1))
	{
		printf("被复制的字符串不能为空！\n");
		return ERROR;
	}
	str2->ch = (char*)malloc(sizeof(char) * str1->length);
	if (!str2->ch)
		exit(OVERFLOW);
	for (int i = 0; i < str1->length; i++)
	{
		str2->ch[i] = str1->ch[i];
	}
	str2->length = str1->length;
	return OK;	
}

//判断串是否为空
Status IsEmpty_H(HString* str)
{
	if (str->length == 0 || !str->ch)
	{
		return TRUE;
	}
	return FALSE;
}

//比较两个字符串的大小，str1==str2,return EQ;str1<str2,return LT;str1>str2,return GT;
Status StrCompare_H(HString* str1, HString* str2)
{
	int tmp = 0;
	for (int i = 1; i < str1->length && i < str2->length; i++)
	{
		if (str1->ch[i] != str2->ch[i])
		{
			if (str1->ch[i] - str2->ch[i]<0)
				return LT;
			else
				return GT;
		}
	}
	if (tmp>0||str1->length - str2->length > 0)
		return GT;
	else if (tmp<0||str1->length - str2->length < 0)
		return LT;
	else
		return EQ;
}
//连接两个串，连接的结果以串Str3返回
Status Concat_H(HString* str1, HString* str2, HString* str3)
{
	InitString_H(str3);
	str3->length = str1->length + str2->length;
	str3->ch = (char*)malloc(sizeof(char) * str3->length);
	if (!str3->ch)
		exit(OVERFLOW);
	//复制串str1
	for (int i = 0; i < str1->length; i++)
	{
		str3->ch[i] = str1->ch[i];
	}
	//复制str2
	for (int i = 0; i < str2->length; i++)
	{
		str3->ch[str1->length + i] = str2->ch[i];
	}
	return OK;
}

//从str字符串的pos位置(从1开始)处截取len长度的字符串到串str3中
Status SubString_H(HString* str3, HString* str, int pos, int len)
{
	InitString_H(str3);
	if (IsEmpty_H(str))
	{
		return ERROR;
	}
	if (pos < 1 || len<0 || pos>str->length||pos+len-1>str->length)
	{
		return ERROR;
	}
	str3->ch = (char*)malloc(sizeof(char) * len);
	if (!str3->ch)
		exit(OVERFLOW);
	for (int i = 0; i < len; i++)
	{
		str3->ch[i] = str->ch[pos + i - 1];
	}
	str3->length = len;
	return OK;
}

//返回从pos位置开始的子串child在父串parent中的位置
int Index_H(HString* parent, HString* child, int pos)
{
	if (pos < 0)
		return 0;
	HString str;
	InitString_H(&str);
	int i = pos;
	while (i + child->length - 1 <= parent->length)
	{
		//截取子串
		SubString_H(&str, parent, i, child->length);
		if (StrCompare_H(&str, child) != EQ)
		{
			i++;
		}
		else
		{
			return i;
		}
	}
	return 0;
}

//从pos位置处删除长度为len的字符串
Status StrDelete_H(HString* str, int pos, int len)
{
	if (IsEmpty_H(str))
		return ERROR;
	if (pos<0 || pos + len - 1>str->length || len < 0)
		return ERROR;
	for (int i = pos-1; i +len< str->length; i++)
	{
		str->ch[i] = str->ch[i + len];
	}
	str->length -= len;
	str->ch = (char*)realloc(str->ch, str->length * sizeof(char));
	return OK;
}

//向指定位置插入串insertStr
Status StrInsert_H(HString* str, int pos, HString* insertStr)
{
	if (pos<1 || pos>str->length + 1)
		return ERROR;
	if (IsEmpty_H(str))
		return ERROR;
	str->ch = (char*)realloc(str->ch, (str->length + insertStr->length) * sizeof(char));
	if (!str->ch)
		exit(OVERFLOW);
	for (int i = str->length - 1; i >= pos - 1; i--)
	{
		str->ch[i + insertStr->length] = str->ch[i];
	}
	for (int i = 0; i < insertStr->length; i++)
	{
		str->ch[pos+i] = insertStr->ch[i];
	}
	str->length += insertStr->length;
	return OK;
}

//将串str中的oldStr替换成newStr
Status Replace_H(HString* str, HString oldStr, HString newStr)
{
	if (IsEmpty_H(str))
		return ERROR;
	int pos = Index_H(str, &oldStr, 1);
	while (pos != 0)
	{
		StrDelete_H(str, pos, oldStr.length);
		StrInsert_H(str, pos, &newStr);
		pos += newStr.length;
		pos = Index_H(str, &oldStr, pos);
	}
	return OK;
}

//清空堆字符串
Status ClearStr_H(HString* str)
{
	if (str->ch)
	{
		free(str->ch);
		str->ch = NULL;
	}
	str->length = 0;
	return OK;
}