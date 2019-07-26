#ifndef _BTREE_H_
#define _BTREE_H_

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define ENGTAG '#'

typedef char BTDataType;
typedef char QUDataType;

//���ڵ�ṹ��
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

typedef BTNode* Bdata;

//�ӽڵ�ṹ��
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

//ջ�ṹ��

typedef BTNode* STDataType;

typedef struct Stack
{
	//STDataType _a[StackMax];
	STDataType* _a;

	size_t size;
	size_t capacity; 
}Stack;

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

int BinaryTreeComplete(BTNode* root);// �ж϶������Ƿ�����ȫ������

void BinaryTreePrevOrderNonR(BTNode* root);//ǰ��ǵݹ�
void BinaryTreeInOrderNonR(BTNode* root);//����ǵݹ�
void BinaryTreePostOrderNonR(BTNode* root);//����ǵݹ�


//����
void QueueInit(Queue* pq);//��ʼ��
QueueNode * BuyQueueNode(Bdata x);//���һ���ӵ��½ڵ�
void QueuePush(Queue* pq, Bdata x);//���
void QueuePop(Queue* pq);//����

Bdata QueueFront(Queue* pq);//��ö���Ԫ��
int QueueEmpty(Queue* pq);//�п�

//ջ
void StackInit(Stack* ps);
void StackPush(Stack* ps, STDataType x);//��ջ
void StackPop(Stack* ps);//��ջ
STDataType StackTop(Stack* ps);//����ջ��Ԫ��
int StackEmpty(Stack* ps);//�п�

#endif // !_BTREE_H_