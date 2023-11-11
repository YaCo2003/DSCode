#pragma once
#include <stdio.h>
#include <malloc.h>
typedef int SListDateType;

typedef struct SListNode
{
	SListDateType data;
	struct SListNode* next;
}SLtNode;

//打印
void SListPrint(SLtNode* phead);
//尾插入
void SListPushBack(SLtNode** pphead, SListDateType x);
//头插入
//void SLitPushFront(SLtNode* phead, SListDateType x);
