#ifndef _BTREE_H_
#define _BTREE_H_

#include<stdio.h>
#include<stdlib.h>

#define ENGTAG '#'

typedef char BTDataType;
typedef char QUDataType;


typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

typedef BTNode* Bdata;

//�ڵ�ṹ��
typedef struct QueueNode
{
	struct QueueNode* _next;
	Bdata _data;
}QueueNode;

//���нṹ��
typedef struct Queue
{
	QueueNode* _front; // ��ͷ
	QueueNode* _rear; // ��β
}Queue;


// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a);//��ȷ��a�Ƿ����ַ���,ֻҪ�ַ�����ȷ����һ���ܻ�ԭ�������ṹ�����Զ��˳�

void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ����(�ݹ����)
void BinaryTreePrevOrder(BTNode* root);//ǰ��
void BinaryTreeInOrder(BTNode* root);//����
void BinaryTreePostOrder(BTNode* root);//����


void BinaryTreeLevelOrder(BTNode* root);// �������(�ǵݹ����)
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

void QueueInit(Queue* pq);//��ʼ��
QueueNode * BuyQueueNode(Bdata x);//���һ���ӵ��½ڵ�
void QueuePush(Queue* pq, Bdata x);//���
void QueuePop(Queue* pq);//����

Bdata QueueFront(Queue* pq);//��ö���Ԫ��
int QueueEmpty(Queue* pq);//�п�
#endif // !_BTREE_H_

