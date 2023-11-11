#include "SList.h"

void SListPrint(SLtNode* phead)
{
	SLtNode* cur = phead;
	while (cur!=NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLtNode* BuySListNode(SListDateType  x)
{
	SLtNode* newnode = (SLtNode*)malloc(sizeof(SLtNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPushBack(SLtNode** pphead, SListDateType x)
{
	SLtNode* newnode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找到尾节点，再进行插入
		SLtNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;

			tail->next = newnode;
		}
	}
}