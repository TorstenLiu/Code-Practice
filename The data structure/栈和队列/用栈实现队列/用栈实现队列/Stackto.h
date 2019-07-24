#ifndef _STACKTO_H_
#define _STACKTO_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define StackMax 10

typedef int STDataType;

//ջ�ṹ��
typedef struct Stack
{
	STDataType _a[StackMax];
	STDataType _top;
}Stack;

//���нṹ��
typedef struct
{
	Stack s1;//���
	Stack s2;//����

}SQueue;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);//��ջ
void StackPop(Stack* ps);//��ջ
STDataType StackTop(Stack* ps);//����ջ��Ԫ��
int StackEmpty(Stack* ps);//�п�
int StackSize(Stack* ps);

void QueuePush(SQueue *ps, STDataType data);//���
void QueuePop(SQueue *ps);//����
STDataType QueueFront(SQueue *ps);//��ö���Ԫ��
STDataType QueueBack(SQueue *ps);//��ö�βԪ��
#endif // !_STACKTO_H_

