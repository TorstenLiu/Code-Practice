#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int QUDataType;
//�ڵ�ṹ��
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
//���нṹ��
typedef struct Queue
{
	QueueNode* _front; // ��ͷ
	QueueNode* _rear; // ��β
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);//���
void QueuePop(Queue* pq);//����
QUDataType QueueFront(Queue* pq);//��ö���Ԫ��
QUDataType QueueBack(Queue* pq);//��ö�βԪ��
int QueueEmpty(Queue* pq);//�п�


#endif // !_QUEUE_H_

