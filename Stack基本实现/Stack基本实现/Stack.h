#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//使用数组来实现栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;//头指针
	int top;//栈顶
	int capacity;//栈的容量
}ST;

//接口：
//创建
void StackInit(ST* ps);
//销毁
void StackDestory(ST* ps);
//栈顶插入删除数据
void StackPush(ST* ps, STDataType x);//入栈
void StackPop(ST* ps);//出栈
//取栈顶元素
STDataType StackTop(ST* ps);
//求栈的元素个数
int StackSize(ST* ps);
//判断是否为空
bool StackEmpty(ST* ps);