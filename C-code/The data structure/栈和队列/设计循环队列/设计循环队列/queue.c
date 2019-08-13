#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

void QueueInit(Queue* pq)
{
	//ͷ��β��ָ��һ���ط�
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}
void QueueDestory(Queue* pq)
{
	//�ٻص�ԭ�㣬�������
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}
void QueuePush(Queue* pq, QuDataType x)//���
{
	//����
	if (pq->size == QueueMAX)//����size�������+1��Ϊ����һ���ռ䲻��Ԫ��
	{
		return;
	}
	//����size������
	/*if (pq->rear + 1 - QueueMAX == pq->data&&pq->front == pq->data || pq->rear + 1 == pq->front)
	{
		return;
	}*/
	*pq->rear = x;
	pq->rear++;
	pq->size++;
	//��Ҫ�ж�rear�Ƿ�ĩβ���������תָ�룬�������rear���Զ�������ʼ��data����Խ��϶
	if (pq->rear - pq->data == QueueMAX)//��ʱ��rearȡֵ��Խ��
	{	
		pq->rear = pq->data;
	}
}
void QueuePop(Queue* pq)//����
{
	//�п�
	if (pq->size == 0)
	{
		return;
	}
	pq->front++;
	pq->size--;
	//��Ҫ�ж�front�Ƿ�ĩβ
	if (pq->front - pq->data == QueueMAX)
	{
		pq->front = pq->data;
	}
}

QuDataType QueueFront(Queue* pq)
{
	//�ж�size�Ƿ�Ϊ0���Ƿ�Ϊ��
	if (pq->size == 0)
	{
		return (QuDataType)0;
	}
	else
	{
		return *pq->front;
	}
}
QuDataType QueueBack(Queue* pq)
{
	if (pq->rear == pq->data)
	{
		return pq->data[QueueMAX - 1];
	}
	else
	{
		return *(pq->rear - 1);
	}
}