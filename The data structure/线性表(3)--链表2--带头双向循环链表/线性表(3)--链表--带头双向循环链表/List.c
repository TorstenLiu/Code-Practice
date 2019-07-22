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
void ListPushBack(List* plist, LTDataType x)//β��--����˫����Ψһ�Ĳ��뷽ʽ
{
	ListInsertFront(plist->_head, x);
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
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}
void ListInsertFront(ListNode* pos, LTDataType x)//ǰ��
{
	ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_prev;//��¼ԭʼֵ  posָ��ᷢ���仯
	cur->_data = x;

	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next= cur;
	cur->_prev = tmp;
}
void ListInsertafter(ListNode* pos, LTDataType x)// ���
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
void ListRemove(List* plist, LTDataType x)//ɾ����һ��ֵΪx�Ľڵ�
{
	ListNode* cur = ListFind(plist, x);
	if (cur)
	{
		ListErase(cur);
	}
}
void ListDistinct(List* plist)
{
	ListNode*cur;
	for (cur = plist->_head->_next; cur != plist->_head->_prev;)//cur != plist->_head->_next���Ƚ�ͷ���������
	{
		if (cur->_data == cur->_next->_data)
		{
			ListErase(cur->_next);//���ﲻ��ɾ��cur����ڵ㣬��Ϊɾ������if����Ͳ��ܷ���cur->next��
		}
		else
		{
			cur = cur->_next;
		}
	}
}
List* ListMerger(List* plist1, List* plist2)//�ϲ�
{
	ListNode * cur1 = plist1->_head->_next;//cur1��cur2����������ĵ�һ������
	ListNode * cur2 = plist2->_head->_next;
	ListNode * tmp1;
	ListNode * tmp2;

	while (cur1 != plist1->_head && cur2 != plist2->_head)
	{
		if (cur1->_data > cur2->_data)//����1��ǰ��ֵ��������2��ǰ��ֵ��������2��ֵ��������1��ֵ��ǰ��
		{
			tmp1 = cur1->_prev;//���ݣ�cur1->_prev�ᱻ�޸�
			tmp2 = cur2->_next;//���ݣ�cur2->_next�ᱻ�޸�

			//ListInsertFront(cur1, cur2->_data);//�������������һ���½ڵ�嵽cur1ǰ�棬������ԭ���Ľڵ�

			cur1->_prev = cur2;	
			cur2->_next = cur1;
			tmp1->_next = cur2;
			cur2->_prev = tmp1;/*��cur2����cur1��tmp1(cur1����һ���ڵ㣩֮��*/

			cur2 = tmp2;//cur2�ҵ�������һ���ڵ�
		}
		else
		{
			cur1 = cur1->_next;
		}
	}
	if (cur1==plist1->_head)//��������ʱ��list1��ĩβ��list2��û��������list2ʣ�µĽڵ�ֵ����list1������Ҫ��list2ʣ�µĽڵ�ֵ����cur1����
	{
		tmp2 = plist2->_head->_prev;//��¼list2Ҫ�ҵ����һ���ڵ㣬cur2�ǵ�һ��Ҫ�ҵĽڵ㣬tmp2�����һ��Ҫ�ҵ�

		cur2->_prev = cur1->_prev;//cur2ǰ��list1�����һ���ڵ㣬��ʱcur1==plist1->_head����������ڵ����cur1��prev
		cur1->_prev->_next = cur2;//list1β�ڵ����cur2.�˴�ʱcur2����list1��β��

		tmp2->_next = cur1;
		cur1->_prev = tmp2;//tmp2��Ϊ��list1��β�ڵ�
	}
	return plist1;
	//��������list2��ĩβʱ����list2Ԫ��ȫ��list1����
	free(plist2->_head);//�ͷ�list2��ʣ��ͷ��
}

void ListPrint(List* plist)
{
	//˫����ı���ͷ
	ListNode * cur;
	printf("head->");
	for (cur = plist->_head->_next; cur!= plist->_head; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("head\n");
}