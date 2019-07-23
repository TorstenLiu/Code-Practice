#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define StackMax 5

typedef int STDataType;
typedef struct Stack
{
	STDataType _a[StackMax];
	//STDataType* _a;

	STDataType _top; // ջ��
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);//��ջ

void StackPop(Stack* ps);//��ջ
STDataType StackTop(Stack* ps);//����ջ��Ԫ��
int StackEmpty(Stack* ps);//�п�
int StackSize(Stack* ps);
#endif // !_STACK_H_

