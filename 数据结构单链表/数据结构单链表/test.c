#include "SList.h"

void test01()
{
	SLtNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
}
int main()
{
	test01();
	return 0;
}
