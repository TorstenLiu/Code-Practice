#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"
void StackInit(Stack * ps)
{
	ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	ps->_top = 0;
}
void StackPush(Stack* ps, STDataType x) //��ջ
{
	//����
	if (StackSize == 0)
	{
		return;
	}
	else
	{
		ps->_a[ps->_top] = x;
		ps->_top++;
	}
}
void StackPop(Stack* ps)//��ջ
{
	//�п�
	if (StackEmpty(&ps) == 0)
	{
		return;
	}
	else
	{
		ps->_top--;
	}
}
STDataType StackTop(Stack* ps)//����ջ��Ԫ��
{
	//�п�
	if (StackEmpty(&ps))
	{
		return ps->_a[ps->_top - 1];
	}
	return 0;
}
int StackEmpty(Stack* ps)//�п�
{
	if (ps->_top == 0)
	{
		return 0;
	}
	return 1;
}
int StackSize(Stack* ps)//����
{
	if (ps->_top == StackMax - 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}