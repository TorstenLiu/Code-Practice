#define _CRT_SECURE_NO_WARNINGS 1

#include"Stackto.h"

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
	if (StackEmpty)
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

void QueuePush(SQueue *ps, STDataType data)//���
{
	StackInit(&(ps->s1));
	StackInit(&(ps->s2));

	StackPush(&(ps->s1), data);
}
void QueuePop(SQueue *ps)//����
{
	//ջp2Ϊ��,s1�ﻹ��Ԫ��ʱ��,�Ȱ�s1Ԫ��ȫѹ��s2,�ٰ�s2��Ԫ�س�ջ
	if (StackEmpty(&(ps->s2)))
	{
		while (!StackEmpty(&(ps->s1)))
		{
			StackPush(&(ps->s2), StackTop(&(ps->s1)));
			StackPop(&(ps->s1));
		}
	}
	//ջ2Ϊ�ǿ�ʱ��ֱ�ӽ�ջ2��ջ��Ԫ�ص���
	StackPop(&(ps->s2));
}
STDataType QueueFront(SQueue *ps)//��ö���Ԫ��
{
	if (StackEmpty(&(ps->s2)) == 0)
	{
		return (STDataType*)0;
	}
	return StackTop(&(ps->s2));
}
STDataType QueueBack(SQueue *ps)//��ö�βԪ��
{
	if (StackEmpty(&(ps->s1)) == 0)
	{
		return (STDataType*)0;
	}
	return StackTop(&(ps->s1));
}