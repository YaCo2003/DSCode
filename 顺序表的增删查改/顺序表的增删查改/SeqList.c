#include "SeqList.h"
void SeqListCheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->size >= psl->capacity)
	{
		SLDateType* temp = (SLDateType*)realloc(psl->a, sizeof(SLDateType) * 8);
		if (temp == NULL)
		{
			perror("realloc fail");
		}
		psl->a = temp;
		psl->capacity *= 2;
	}
}
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->size = 0;
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->capacity = 4;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	assert(ps->a);
	ps->size = 0;
	ps->capacity = 0;
	ps->a = NULL;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	
	//for (int i = 0; i < ps->size; i++)
	//{
	//	printf("%d ", ps->a[i]);
	//}

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}

	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;

}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	//int end = ps->size - 1;
	//while(end>=0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}
	//for (int i = ps->size - 1; i >= 0; i--)
	//{
	//	ps->a[i + 1] = ps->a[i];
	//}
	//ps->a[0] = x;
	SeqListInsert(ps, 0, x);
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
		//向前挪动
	int start = 0;
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;

}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->a[ps->size - 1] = 0;
	ps->size--;
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps);

	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	//向前挪动
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;

}