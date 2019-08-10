#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _SLIST_H_
#define _SLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//��ͷ�����ѭ������
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode *next;
}SListNode;

void SListInit(SListNode **phead);//дvoid��д����ֵ����ʱ����Ҫ����һ����Ҫ�������д��Ϊint
void SListDestory(SListNode **pphead);
SListNode *BuySListNode(SLTDataType x);//��һ���µĽڵ�
void SListPushFront(SListNode **phead, SLTDataType x);//ͷ��
void SListPopFront(SListNode **phead);//ͷɾ
SListNode *SListFind(SListNode *phead, SLTDataType x);// ��pos�ĺ�����в���
void SListInsertAfter(SListNode *pos, SLTDataType x);// ��pos��ǰ����в���
void SListEraseAfter(SListNode *pos);
void SListRemove(SListNode **phead, SLTDataType x);
void SListRemoveall(SListNode **phead, SLTDataType x);

void SListPrint(SListNode *phead);

void SListReverse1(SListNode **pphead);//����
void SListReverse2(SListNode **pphead);

SListNode *getPublicPoint(SListNode *headA, SListNode *headB);//�ҹ����ڵ�
SListNode *JugdeCircle(SListNode *head);//�ж��Ƿ��л�
SListNode *detectCircle(SListNode *head);//�һ������
SListNode *FindK(SListNode *head, SLTDataType k);//������ĵ�����k���ڵ�

#endif /*_SLIST_H_*/