#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"
void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));//plist->_head�൱��*pphead
	plist->_head->_prev = plist->_head;
	plist->_head->_next = plist->_head;
}
void ListDestory(List* plist)
{
	while (plist->_head != plist->_head)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;
}
void ListPushBack(List* plist, LTDataType x)//���--����˫����Ψһ�Ĳ��뷽ʽ
{
	ListInsertafter(plist->_head, x);
}
void ListPopBack(List* plist)//βɾ
{
	ListErase(plist->_head->_prev);
}
void ListPushFront(List* plist, LTDataType x)//ͷ��
{
	ListInsertafter(plist->_head, x);
}
void ListPopFront(List* plist)//ͷɾ
{
	ListErase(plist->_head->_next);
}

ListNode* ListFind(List* plist, LTDataType x)// ��pos��ǰ����в���
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (cur == x)
		{
			return cur;
		}
	}
	return NULL;
}
void ListInsertafter(ListNode* pos, LTDataType x)// ɾ��posλ�õĽڵ�
{
	//pos������� ���
	ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_next;
	cur->_data = x;

	pos->_next = cur;
	cur->_prev = pos;
	tmp->_prev = cur;
	cur->_next = tmp;
}

void ListErase(ListNode* pos)//ɾ��posλ�õĽڵ�
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
void ListRemove(List* plist, LTDataType x)
{
	ListNode* cur = ListFind(plist, x);
	if (cur)
	{
		ListErase(cur);
	}
}
void ListPrint(List* plist)
{
	//˫����ı���ͷ
	ListNode * cur;
	for (cur = plist->_head->_next; cur!= plist->_head; cur = cur->_next)
	{
		printf("%d->", plist->_head->_data);
	}
}