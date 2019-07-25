#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"
																																															
BTNode* BinaryTreeCreate(BTDataType* a)//��ԭ��
{
	BTNode *cur;
	static int i = 0;
	if (a[i] == ENGTAG)
	{
		i++;
		return NULL;
	}
	else
	{
		cur = (BTNode*)malloc(sizeof(BTNode));
		cur->_data = a[i];
		i++;
		cur->_left = BinaryTreeCreate(a);
		cur->_right = BinaryTreeCreate(a);
		return cur;
	}
}
void BinaryTreeDestory(BTNode** root)
{

}
int BinaryTreeSize(BTNode* root)
{

}
int BinaryTreeLeafSize(BTNode* root)
{

}
int BinaryTreeLevelKSize(BTNode* root, int k)
{

}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{

}
// ����
void BinaryTreePrevOrder(BTNode* root)//ǰ��
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
void BinaryTreeInOrder(BTNode* root)//����
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
void BinaryTreePostOrder(BTNode* root)//����
{
	if (root != NULL)
	{  
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);
	}
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	//�Ƚ�A�ڵ�push��ȥ����ӡ���������ͨ�����ҵ�����Ľڵ㣬������ѹһ�����Ľڵ㣬�˽ڵ��data����ΪBTNode*
	Queue myqueue;
	QueueInit(&myqueue);
	QueuePush(&myqueue, root);
	
	//��ø����ڵ㣬���ҵ����Һ��ӣ��ж��Ƿ�Ϊ�գ����վ�ѹ��ȥ
	while (QueueEmpty(&myqueue))
	{
		QueueNode *tmp = BuyQueueNode(QueueFront(&myqueue));
		printf("%c", tmp->_data->_data);
		if (tmp->_data->_left != NULL)
		{
			QueuePush(&myqueue, tmp->_data->_left);
		}
		if (tmp->_data->_right != NULL)
		{
			QueuePush(&myqueue, tmp->_data->_right);
		}
		//����(��ͷ)
		QueuePop(&myqueue);
	}
	
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{

}
void BinaryTreePrevOrderNonR(BTNode* root)
{

}
void BinaryTreeInOrderNonR(BTNode* root)
{

}
void BinaryTreePostOrderNonR(BTNode* root)
{

}

void QueueInit(Queue* pq)
{
	pq->_front = (QueueNode*)malloc(sizeof(QueueNode));
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
QueueNode * BuyQueueNode(Bdata x)
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
void QueuePush(Queue* pq, Bdata x)//���--β��
{
	QueueNode  *tmp = BuyQueueNode(x);
	if (pq->_front->_next == NULL)
	{
		pq->_front->_next = tmp;
		pq->_rear = tmp;
	}
	else
	{
		pq->_rear->_next = tmp;
		pq->_rear = tmp;
	}
}
void QueuePop(Queue* pq)//����--ͷɾ
{
	if (QueueEmpty(&pq) == 0)
	{
		return;
	}
	QueueNode*tmp = pq->_front->_next;
	if (tmp->_next == NULL)
	{
		pq->_rear = pq->_front;
	}
	pq->_front->_next = tmp->_next;
	free(tmp);
	tmp = NULL;
}
Bdata QueueFront(Queue* pq)//��ö�ͷԪ��
{
	if (QueueEmpty(&pq) == 0)
	{
		return (Bdata)0;
	}
	return pq->_front->_next->_data;
}
int QueueEmpty(Queue* pq)//�п�
{
	if (pq->_front == pq->_rear)
	{
		return 0;
	}
	return 1;
}