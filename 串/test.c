#define  _CRT_SECURE_NO_WARNINGS 1
#include"String1.h"
#include"String2.h"

void TestString2()
{
	HString str1;
	HString str2;
	HString str3;
	HString str4;
	StrAssign_H(&str1, "abcdefg");
	PrintHString(&str1);

	InitString_H(&str2);
	StrCopy_H(&str1, &str2);
	printf("复制后的str2：");
	PrintHString(&str2);

	StrAssign_H(&str2, "abygdd");
	printf("比较结果：%d（相等:0 大于:1 小于:-1）\n", StrCompare_H(&str1, &str2));

	printf("链接操作：");
	Concat_H(&str1, &str2, &str3);
	PrintHString(&str3);
	
	SubString_H(&str4, &str3, 3, 5);
	printf("截取的结果：");
	PrintHString(&str4);

	printf("str4在父串中的位置：%d\n",Index_H(&str3,&str4,2));
	
	StrDelete_H(&str3, 3, 3);
	printf("删除后的字符串为：");
	PrintHString(&str3);

	StrInsert_H(&str3, 5, &str4);
	printf("插入后的字符串为：");
	PrintHString(&str3);


}

int main()
{
	TestString2();
	return 0;
}