#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QueueInit(Queue* pq)
{
	pq->_front  = (QueueNode*)malloc(sizeof(QueueNode));
	if (pq->_front == NULL)
	{
		return;
	}
	else
	{
		pq->_rear = pq->_front;
		pq->_front->_next = NULL;
	}
}
void QueueDestory(Queue* pq)
{
	//��ͷ�ڵ㿪ʼɾ��,��ͣ�ĺ�ɾ
	while (pq->_front != NULL)
	{
		//���ҵ�ͷ������Ľڵ�
		pq->_rear = pq->_front->_next;
		free(pq->_front);
		pq->_front = pq->_rear;
	}
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode *cur = (QueueNode*)malloc(sizeof(QueueNode));
	if (cur != NULL)
	{
		cur->_data = x;
		cur->_next = NULL;
		return cur;
	}
	else
	{
		return NULL;
	}
}
void QueuePush(Queue* pq, QUDataType x)//���--β��
{
	QueueNode *tmp = BuyQueueNode(x);
	pq->_rear->_next = tmp;
	pq->_rear = tmp;
}
void QueuePop(Queue* pq)//����--ͷɾ
{
	if (QueueEmpty(&pq) == 0)
	{
		return;
	}
	QueueNode*tmp = pq->_front->_next;
	free(pq->_front);
	pq->_front = tmp;
}
QUDataType QueueFront(Queue* pq)//��ö�ͷԪ��
{
	if (QueueEmpty(&pq) == 0)
	{
		return (QUDataType*)0;
	}
	return pq->_front->_next->_data;
}
QUDataType QueueBack(Queue* pq) // ��ö�βԪ��
{
	if (QueueEmpty(&pq) == 0)
	{
		return;
	}
	return pq->_rear->_data;
}
int QueueEmpty(Queue* pq)//�п�
{
	if (pq->_front == pq->_rear)
	{
		return 0;
	}
	return 1;
}