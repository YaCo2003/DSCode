#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);

	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = 0;//代表着top要指向栈顶的下一个元素
}
//销毁
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
//栈顶插入删除数据
void StackPush(ST* ps, STDataType x)//入栈
{
	assert(ps);

	//满了
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			printf("relloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)//出栈
{
	assert(ps->a);
	//如果栈空了，调用Pop,直接终止程序
	assert(ps->top > 0);

	ps->top--;
}
//取栈顶元素
STDataType StackTop(ST* ps)
{
	assert(ps);
	//如果栈空了，调用Pop,直接终止程序
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
//求栈的元素个数
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
//判断是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}