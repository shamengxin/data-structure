//����˳��ṹʵ��
#include"String1.h"
/*
* ������ʽʵ���ַ�����˳��ṹ����ȱ�����˷ѿռ�
#define MAXSIZE 100
typedef struct
{
	char ch[MAXSIZE + 1];
	int length;
}SString;
*/

//���Ķ�ʽ˳��洢�ṹ��Heap �ѣ�
typedef struct
{
	char* ch;  //����Ƿǿմ�����ô�Ͱ���ָ�����ȷ����ڴ棬����ch��ָ��NULL
	int length;  //����
}HString;

//��ʼ�����ַ���
void InitString_H(HString* str);

//�Դ�str���и�ֵ������ֵΪchars
Status StrAssign_H(HString* str, char* chars);

//��ӡ���ַ���
void PrintHString(HString* str);

//����srcStr�е����ݸ��Ƶ���destStr
Status StrCopy_H(HString* str1, HString* str2);

//�Ƚ������ַ����Ĵ�С��str1==str2,return EQ;str1<str2,return LT;str1>str2,return GT;
Status StrCompare_H(HString* str1, HString* str2);

//�жϴ��Ƿ�Ϊ��
Status IsEmpty_H(HString* str);

//���������������ӵĽ���Դ�Str3����
Status Concat_H(HString* str1, HString* str2, HString* str3);

//��str�ַ�����posλ��(��1��ʼ)����ȡlen���ȵ��ַ�������str3��
Status SubString_H(HString* str3, HString* str, int pos, int len);

//���ش�posλ�ÿ�ʼ���Ӵ�child�ڸ���parent�е�λ��
int Index_H(HString* parent, HString* child, int pos);

//��posλ�ô�ɾ������Ϊlen���ַ���
Status StrDelete_H(HString* str, int pos, int len);

//��ָ��λ�ò��봮insertStr
Status StrInsert_H(HString* str, int pos, HString* insertStr);

//����str�е�oldStr�滻��newStr
Status Replace_H(HString* str, HString oldStr, HString newStr);

//��ն��ַ���
Status ClearStr_H(HString* str);