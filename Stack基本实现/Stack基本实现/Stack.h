#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//ʹ��������ʵ��ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;//ͷָ��
	int top;//ջ��
	int capacity;//ջ������
}ST;

//�ӿڣ�
//����
void StackInit(ST* ps);
//����
void StackDestory(ST* ps);
//ջ������ɾ������
void StackPush(ST* ps, STDataType x);//��ջ
void StackPop(ST* ps);//��ջ
//ȡջ��Ԫ��
STDataType StackTop(ST* ps);
//��ջ��Ԫ�ظ���
int StackSize(ST* ps);
//�ж��Ƿ�Ϊ��
bool StackEmpty(ST* ps);