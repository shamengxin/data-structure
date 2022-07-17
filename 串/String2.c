#define  _CRT_SECURE_NO_WARNINGS 1
#include"String2.h"
#include<string.h>
//��ʼ�����ַ���
void InitString_H(HString* str)
{
	str->ch = NULL;
	str->length = 0;
}

//�Դ�str���и�ֵ������ֵΪchars
Status StrAssign_H(HString* str, char* chars)
{
	int len = strlen(chars);
	if (!len)
	{
		return ERROR;
	}
	InitString_H(str);
	str->ch = (char*)malloc(len*sizeof(char));//�����len*������len��ͬ���ֽڴ�С�Ŀռ�
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

//��ӡ���ַ���
void PrintHString(HString* str)
{
	if (!str->ch || str->length == 0)
	{
		printf("���ַ���Ϊ�գ�\n");
	}
	for (int i = 0; i < str->length; i++)
	{
		printf("%c", str->ch[i]);
	}
	printf("\n");
}

//����str1�е����ݸ��Ƶ���str2
Status StrCopy_H(HString* str1, HString* str2)
{
	InitString_H(str2);
	if (IsEmpty_H(str1))
	{
		printf("�����Ƶ��ַ�������Ϊ�գ�\n");
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

//�жϴ��Ƿ�Ϊ��
Status IsEmpty_H(HString* str)
{
	if (str->length == 0 || !str->ch)
	{
		return TRUE;
	}
	return FALSE;
}

//�Ƚ������ַ����Ĵ�С��str1==str2,return EQ;str1<str2,return LT;str1>str2,return GT;
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
//���������������ӵĽ���Դ�Str3����
Status Concat_H(HString* str1, HString* str2, HString* str3)
{
	InitString_H(str3);
	str3->length = str1->length + str2->length;
	str3->ch = (char*)malloc(sizeof(char) * str3->length);
	if (!str3->ch)
		exit(OVERFLOW);
	//���ƴ�str1
	for (int i = 0; i < str1->length; i++)
	{
		str3->ch[i] = str1->ch[i];
	}
	//����str2
	for (int i = 0; i < str2->length; i++)
	{
		str3->ch[str1->length + i] = str2->ch[i];
	}
	return OK;
}

//��str�ַ�����posλ��(��1��ʼ)����ȡlen���ȵ��ַ�������str3��
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

//���ش�posλ�ÿ�ʼ���Ӵ�child�ڸ���parent�е�λ��
int Index_H(HString* parent, HString* child, int pos)
{
	if (pos < 0)
		return 0;
	HString str;
	InitString_H(&str);
	int i = pos;
	while (i + child->length - 1 <= parent->length)
	{
		//��ȡ�Ӵ�
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

//��posλ�ô�ɾ������Ϊlen���ַ���
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

//��ָ��λ�ò��봮insertStr
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

//����str�е�oldStr�滻��newStr
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

//��ն��ַ���
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