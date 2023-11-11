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
	ps->top = 0;//������topҪָ��ջ������һ��Ԫ��
}
//����
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
//ջ������ɾ������
void StackPush(ST* ps, STDataType x)//��ջ
{
	assert(ps);

	//����
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
void StackPop(ST* ps)//��ջ
{
	assert(ps->a);
	//���ջ���ˣ�����Pop,ֱ����ֹ����
	assert(ps->top > 0);

	ps->top--;
}
//ȡջ��Ԫ��
STDataType StackTop(ST* ps)
{
	assert(ps);
	//���ջ���ˣ�����Pop,ֱ����ֹ����
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
//��ջ��Ԫ�ظ���
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
//�ж��Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}