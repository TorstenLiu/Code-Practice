#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define QueueMAX 5
typedef int QuDataType;

typedef struct Queue
{
	QuDataType data[QueueMAX];//data��һ����׼ֵ��ȫ�̲�����data��ʹ�Ǿ�̬���飬Ҳ�������ռ䡣�ѿռ����޴�����á��������鳤�ȹ���ʱ�ᵼ��ջը
	QuDataType *front;//β
	QuDataType *rear;//ͷ
	size_t size;//ʵ���Ͽ��Բ�Ҫ�����������һ��
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QuDataType x);
void QueuePop(Queue* pq);

QuDataType QueueFront(Queue* pq);
QuDataType QueueBack(Queue* pq);

#endif // !_QUEUE_H_
