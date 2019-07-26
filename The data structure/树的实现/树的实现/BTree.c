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
void BinaryTreePrevOrderNonR(BTNode* root)//ǰ��ǵݹ�
{
	//1.��ӡ���ڵ㡣2.���Ƿ������������оͽ�������ѹջ���ٿ��Ƿ������ӣ�������뵽���ӡ�3.��û������ʱ��cur���±�����ջ��Ԫ�ص�λ�ã���ջ
	Stack mystack;
	Bdata cur = root;
	StackInit(&mystack,50);
	while (cur || !StackEmpty(&mystack))
	{
		putchar(cur->_data);
		if (cur->_right)
		{
			StackPush(&mystack, cur->_right);
		}
		if (cur->_left)
		{
			cur = cur->_left;
		}
		else
		{
			cur = StackTop(&mystack);
			StackPop(&mystack);
		}
	}
}
void BinaryTreeInOrderNonR(BTNode* root)//����ǵݹ�
{
	//1.���Լ�ѹջ��2.���Ƿ������ӣ��н������ӣ�����ѹջ��ֱ������û��Ϊֹ��3.��ӡջ����curָ��ջ������ջ�������Һ���
	Stack mystack;
	Bdata cur = root;
	StackInit(&mystack,50);
	while (cur || !StackEmpty(&mystack))//cur(���ڱ����Ľڵ�)Ϊ�գ�ջΪ��(����Ҫ�����Ľڵ�)ʱ����
	{
		for (; cur; cur = cur->_left)//�ѵ�ǰ�������е�����ѹջ��һֱ���Ҳ�������Ϊֹ
		{

			StackPush(&mystack, cur);
		}

		if (!StackEmpty(&mystack))//ջΪ��
		{
			//���ӱ����꣬��һ��û�����ӵĽڵ���ǵ�һ����ջ�Ľڵ㡣
			//���Һ���Ϊ�գ�ջ������һ��Ҫ���ʵĽڵ㡣��Ϊ�գ����������������Ϊ���ĵ�һ��û�����ӵĽڵ�
			cur = StackTop(&mystack);
			putchar(cur->_data);
			StackPop(&mystack);
			cur = cur->_right;//�������͸�������������ʼ����������������Ϊ��������curΪ��ʱ��forѭ���������
		}
	}

}

void BinaryTreePostOrderNonR(BTNode* root)//����ǵݹ�
{
	Stack mystack;
	Bdata cur = root;
	StackInit(&mystack,50);
	int tag[32] = { 0 };//tag������Ϊ���Ĳ���

	while (cur || !StackEmpty(&mystack))
	{
		for (; cur; cur=cur->_left)//�������򣬽�������ջ
		{
			StackPush(&mystack, cur);//size+1
			tag[mystack.size] = 0;//���ӱ�����ǩ
		}
		while (!StackEmpty(&mystack) && tag[mystack.size] == 1)//���ӻ�û�������ʱ���ܽ���ѭ��
			//ȷ����ֻ�������������������ʱ���Ž������while
		{
			cur = StackTop(&mystack);
			putchar(cur->_data);
			StackPop(&mystack);//popһ��size-1
			cur = NULL;//ѭ��������������
		}
		if (!StackEmpty(&mystack))
		{
			tag[mystack.size] = 1;//֤���������������
			cur = StackTop(&mystack)->_right;//������������������
		}
	}
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

void StackInit(Stack * ps, size_t capacity)
{
	ps->_a = (QUDataType *)calloc(capacity, sizeof(QUDataType));
	ps->capacity = capacity;
	ps->size = 0;
}

void StackPush(Stack* ps, STDataType  x) //��ջ
{
	//����
	if (ps->size==ps->capacity)
	{
		ps->capacity *= 2;
		ps->_a = (QUDataType *)realloc(ps->_a, ps->capacity * sizeof(QUDataType));
	}
	else
	{
		ps->_a[ps->size] = x;
		ps->size++;
	}

}
void StackPop(Stack* ps)//��ջ
{
	//�п�
	if (ps->size==0)
	{
		return;
	}
	else
	{
		ps->size--;
	}
}
STDataType StackTop(Stack* ps)//����ջ��Ԫ��
{
	//�п�
	if (ps->size != 0)
	{
		return ps->_a[ps->size - 1];
	}
	return 0;
}
int StackEmpty(Stack* ps)//�п�
{
	return ps->size == 0;
}