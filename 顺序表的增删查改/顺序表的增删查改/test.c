#include "SeqList.h"

void test1()
{
	SeqList mylist;
	SeqListInit(&mylist);

	SeqListPushBack(&mylist, 1);
	SeqListPushBack(&mylist, 2);
	SeqListPushBack(&mylist, 3);
	SeqListPushBack(&mylist, 4);
	SeqListPushBack(&mylist, 4);
	SeqListPushBack(&mylist, 4);
	SeqListPushBack(&mylist, 4);

	SeqListPrint(&mylist);

	SeqListDestroy(&mylist);
}

void test2()
{
	SeqList mylist;
	SeqListInit(&mylist);

	SeqListPushBack(&mylist, 1);
	SeqListPushBack(&mylist, 2);
	SeqListPushBack(&mylist, 3);
	SeqListPushBack(&mylist, 4);

	SeqListPushFront(&mylist, 0);

	SeqListPrint(&mylist);

	SeqListDestroy(&mylist);
}

void test3()
{
	SeqList mylist;
	SeqListInit(&mylist);

	SeqListPushBack(&mylist, 1);
	SeqListPushBack(&mylist, 2);
	SeqListPushBack(&mylist, 3);
	SeqListPushBack(&mylist, 4);

	SeqListPushFront(&mylist, 0);
	SeqListPrint(&mylist);

	SeqListPopFront(&mylist);

	SeqListPrint(&mylist);

	SeqListDestroy(&mylist);
}

void test4()
{
	SeqList mylist;
	SeqListInit(&mylist);

	SeqListPushBack(&mylist, 1);
	SeqListPushBack(&mylist, 2);
	SeqListPushBack(&mylist, 3);
	SeqListPushBack(&mylist, 4);

	SeqListPushFront(&mylist, 0);
	SeqListPrint(&mylist);

	SeqListPopFront(&mylist);
	SeqListPrint(&mylist);

	SeqListPopBack(&mylist);
	SeqListPrint(&mylist);

	SeqListErase(&mylist, 1);
	SeqListPrint(&mylist);
	SeqListDestroy(&mylist);
}

void test5()
{
	SeqList mylist;
	SeqListInit(&mylist);

	SeqListPushBack(&mylist, 1);
	SeqListPushBack(&mylist, 2);
	SeqListPushBack(&mylist, 3);
	SeqListPushBack(&mylist, 4);

	SeqListPushFront(&mylist, 0);
	SeqListPrint(&mylist);
	int flag = SeqListFind(&mylist, 3);
	if ( flag == -1)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了，下标是：%d\n", flag);
	}
	SeqListDestroy(&mylist);
}

void test6()
{
	SeqList mylist;
	SeqListInit(&mylist);

	SeqListPushBack(&mylist, 1);
	SeqListPushBack(&mylist, 2);
	SeqListPushBack(&mylist, 3);
	SeqListPushBack(&mylist, 4);
	SeqListPushBack(&mylist, 5);
	SeqListPushBack(&mylist, 6);
	SeqListPushBack(&mylist, 7);

	SeqListPrint(&mylist);

	SeqListInsert(&mylist, 2, 0);

	SeqListPrint(&mylist);
	SeqListDestroy(&mylist);
}


int main()
{
	test4();
}