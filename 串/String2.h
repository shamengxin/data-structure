//串的顺序结构实现
#include"String1.h"
/*
* 定长方式实现字符串的顺序结构——缺点是浪费空间
#define MAXSIZE 100
typedef struct
{
	char ch[MAXSIZE + 1];
	int length;
}SString;
*/

//串的堆式顺序存储结构（Heap 堆）
typedef struct
{
	char* ch;  //如果是非空串，那么就按照指定长度分配内存，否则ch就指向NULL
	int length;  //串长
}HString;

//初始化堆字符串
void InitString_H(HString* str);

//对串str进行赋值操作，值为chars
Status StrAssign_H(HString* str, char* chars);

//打印堆字符串
void PrintHString(HString* str);

//将串srcStr中的内容复制到串destStr
Status StrCopy_H(HString* str1, HString* str2);

//比较两个字符串的大小，str1==str2,return EQ;str1<str2,return LT;str1>str2,return GT;
Status StrCompare_H(HString* str1, HString* str2);

//判断串是否为空
Status IsEmpty_H(HString* str);

//连接两个串，连接的结果以串Str3返回
Status Concat_H(HString* str1, HString* str2, HString* str3);

//从str字符串的pos位置(从1开始)处截取len长度的字符串到串str3中
Status SubString_H(HString* str3, HString* str, int pos, int len);

//返回从pos位置开始的子串child在父串parent中的位置
int Index_H(HString* parent, HString* child, int pos);

//从pos位置处删除长度为len的字符串
Status StrDelete_H(HString* str, int pos, int len);

//向指定位置插入串insertStr
Status StrInsert_H(HString* str, int pos, HString* insertStr);

//将串str中的oldStr替换成newStr
Status Replace_H(HString* str, HString oldStr, HString newStr);

//清空堆字符串
Status ClearStr_H(HString* str);