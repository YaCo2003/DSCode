#include "Stack.h"

int main()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	//while (!StackEmpty(&st))
	//{
	//	printf("%d", StackTop(&st));
	//	printf("\n");
	//	StackPop(&st);
	//}
	printf("%d", StackTop(&st));
	printf("%d", StackSize(&st)); 
	StackDestory(&st);
}