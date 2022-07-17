//课程相关的代码及宏函数的定义
#include<stdio.h>
#include<stdlib.h>

//状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define EQ 0    //equip
#define GT 1    //great than
#define LT -1   //less than
#ifndef Status_H_ //如果系统中已经有了下面状态码的定义，就不再重复定义了
	#define OVERFLOW -2 //堆栈上溢  超过所能表示的最大正数
	#define UNDERFLOW -3 //堆栈下溢  超过所能表示的最大负数
#endif // !1
typedef int Status; //自定义一个状态码的识别类型

