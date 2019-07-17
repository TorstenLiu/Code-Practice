
#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _SEQLIST_H_
#define _SEQLIST_H_

// ˳���Ķ�̬�洢
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int SLDataType;//����ı�����

typedef struct SeqList
{
	SLDataType* array; // ָ��̬���ٵ�����
	size_t size; // ��Ч���ݸ���
	size_t capacity; // �����ռ�Ĵ�С
}SeqList;

void SeqListInit(SeqList* psl, size_t capacity);

void SeqListDestory(SeqList* psl);
void CheckCapacity(SeqList* psl);//ÿ����һ�β�����Ҫ�����ж�
void SeqListPushBack(SeqList* psl, SLDataType x);//β��
void SeqListPopBack(SeqList* psl);//βɾ
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);//��������
void SeqListRemove(SeqList* psl, SLDataType x);//�Ƴ�����,�Ƴ�����ֵΪx��Ԫ�� O(N)
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);//�޸ģ���pos��ֵ�ĳ�x O(1)
void SeqListPrint(SeqList* psl);//O(N)void SeqListBubbleSort(SeqList* psl);int SeqListBinaryFind(SeqList* psl, SLDataType x);

void SeqListRemoveAll1(SeqList* psl, SLDataType x);//ʱ�临��O(n) �ռ临��O(1)void SeqListRemoveAll2(SeqList* psl, SLDataType x);//ʱ�临��O(n)  �ռ临��O(n)#endif