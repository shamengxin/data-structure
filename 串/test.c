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
	printf("���ƺ��str2��");
	PrintHString(&str2);

	StrAssign_H(&str2, "abygdd");
	printf("�ȽϽ����%d�����:0 ����:1 С��:-1��\n", StrCompare_H(&str1, &str2));

	printf("���Ӳ�����");
	Concat_H(&str1, &str2, &str3);
	PrintHString(&str3);
	
	SubString_H(&str4, &str3, 3, 5);
	printf("��ȡ�Ľ����");
	PrintHString(&str4);

	printf("str4�ڸ����е�λ�ã�%d\n",Index_H(&str3,&str4,2));
	
	StrDelete_H(&str3, 3, 3);
	printf("ɾ������ַ���Ϊ��");
	PrintHString(&str3);

	StrInsert_H(&str3, 5, &str4);
	printf("�������ַ���Ϊ��");
	PrintHString(&str3);


}

int main()
{
	TestString2();
	return 0;
}