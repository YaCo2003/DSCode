#pragma once
#include <stdio.h>
#include <malloc.h>
typedef int SListDateType;

typedef struct SListNode
{
	SListDateType data;
	struct SListNode* next;
}SLtNode;

//��ӡ
void SListPrint(SLtNode* phead);
//β����
void SListPushBack(SLtNode** pphead, SListDateType x);
//ͷ����
//void SLitPushFront(SLtNode* phead, SListDateType x);
