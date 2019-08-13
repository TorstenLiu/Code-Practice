#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"

void SListInit(SListNode **pphead)
{
	*pphead = NULL;
}
void SListDestory(SListNode **pphead)//�����ӣ���ͣ����ɾ��ͷɾ����ͷ,��������ѭ������
{
	if (*pphead==NULL)
	{
		return;
	}
	while ((*pphead)->next)
	{
		SListEraseAfter(*pphead);
	}
	free(*pphead);
	*pphead = NULL;
}
SListNode *BuySListNode(SLTDataType x)//��һ���µĽڵ�
{
	SListNode *tmp = (SListNode *)malloc(sizeof(SListNode));
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
void SListPushFront(SListNode **pphead, SLTDataType x)//ͷ��
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = (*pphead);
	(*pphead) = tmp;
}
void SListPopFront(SListNode **pphead)//ͷɾ--ͷ����Ϊ��
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode *tmp = (*pphead)->next;
	free(*pphead);
	(*pphead) = tmp;
}
SListNode *SListFind(SListNode *phead, SLTDataType x)// ��x
{
	SListNode *tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
	}
	return NULL;

}
void SListInsertAfter(SListNode *pos, SLTDataType x)// ��pos�ĺ�����в���
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}
void SListEraseAfter(SListNode *pos)//ɾ��pos����Ľڵ㣬��pos�ĵ�ַ���������ı�posָ��Ŀռ�
{
	SListNode *tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	tmp = NULL;
}
void SListRemove(SListNode **pphead, SLTDataType x)//ֻɾһ��
{
	SListNode *tmp;
	if (*pphead == NULL)
	{
		return;
	}
	if ((*pphead)->data == x)
	{
		SListPopFront(pphead);
		return;
	}
	for (tmp = *pphead; tmp->next; tmp = tmp->next)
	{
		if(tmp->next->data == x)
		{
			SListEraseAfter(tmp);
			return;
		}
	}
}
void SListRemoveall(SListNode **pphead, SLTDataType x)
{
	SListNode *tmp;
	if (*pphead == NULL)
	{
		return;
	}
	while (*pphead&&(*pphead)->data == x)
	{
		SListPopFront(pphead);
	}
	for (tmp = *pphead; tmp->next; tmp = tmp->next)
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
		}
		else
		{
			tmp = tmp->next;
		}
	}
}

//������������ַ���    ����������CSND:https://blog.csdn.net/qq_42913794/article/details/97621521
void SListReverse1(SListNode **pphead)
{
	SListNode *head = *pphead;//ÿ��ѭ����ʼ��ָ��ǰ�����ͷ
	SListNode *tmp = head->next;//ÿ��ѭ����ʼ��ָ��ɾ�Ľڵ�
	SListNode *oldhead = *pphead;//ÿ��ѭ����ʼ��ָ��ɾ��ǰһ���ڵ�

	while (tmp)//tmpΪ�գ����������������ͷ����β
	{
		oldhead->next = tmp->next;//�ܿ�tmp����ɾ����һ����
		tmp->next = head;//��tmp�����ͷ��ͷ�壩
		head = tmp;//��ͷ
		tmp = oldhead->next;//��tmp�����һ��ѭ���д�ɾ���Ľڵ�
	}
	*pphead = head;
}

void SListReverse2(SListNode **pphead)
{
	SListNode *pre = *pphead;//��ִ�в�����ǰһ���ڵ�
	SListNode *cur= pre->next;//��ִ�в����Ľڵ�
	SListNode *next = cur;//��ִ�в����ĺ�һ���ڵ�,��ʱָ��cur����ѭ����ʼ��ʱ����ת�����һ���ڵ�

	pre->next = NULL;//��ʱ��ͷ�������Ϊβ������Ҫ����β�ڵ� 
	while (next)
	{
		next = next->next;//��ǰ�����nextΪ�ա�
		cur->next = pre;//�ı��ͷ����
		pre = cur;//ѭ���ڵ����κ���
		cur = next;
	}
	*pphead = pre;//ѭ������ʱ��cur��next��ָ��գ���ʱ��ͷΪpre
}

//����������Ĺ����ڵ�
SListNode *getPublicPoint(SListNode *headA, SListNode *headB)//Ѱ�ҵ�������ཻ�ڵ�
{
	int lenA = 0;
	int lenB = 0;
	int gap = 0;
	int i = 0;
	SListNode *cur;
	SListNode *longerlist = headA;
	SListNode *shortlist = headB;
	for (cur = headA; cur; cur = cur->next)
	{
		lenA++;
	}
	for (cur = headB; cur; cur = cur->next)
	{
		lenB++;
	}
	gap = abs(lenA - lenB);
	if (lenA < lenB)
	{
		longerlist = headB;
		shortlist = headA;
	}
	for (; i < gap; i++)//�Ҷ���
	{
		longerlist = longerlist->next;
	}
	for (; longerlist&&shortlist; longerlist = longerlist->next, shortlist = shortlist->next)
	{
		if (longerlist->data == shortlist->data)
		{
			return longerlist;
		}
	}
	return NULL;
}

//�ж������Ƿ��л�
SListNode *JugdeCircle(SListNode *head)
{
	SListNode *fast = head;
	SListNode *slow = head;
	while (fast&&slow&&fast->next)//�����Ҳ���fast��next��next
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)//�Ҷ��룬�ҵ������㣬��˵���л�
		{
			return fast;
		}
	}
	return NULL;
}

SListNode *detectCircle(SListNode *head)
{
	//���л�,�������ڵ㣬һ��һ�������Σ�һ��һ����һ��
	SListNode *fast = head;
	SListNode *slow = head;
	while (fast&&slow&&fast->next)//�����Ҳ���fast��next��next
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)//�ҵ������㣬�Ҷ���
		{
			break;
		}
	}
	for (; fast&&fast->next; fast = fast->next,head = head->next)//�����ڵ���fast��headһ���ߣ��ҵ��Ĺ����ڵ���ǻ����
	{
		if (fast->data == head->data)
		{
			return fast;
		}
	}
	return NULL;
}

//������ĵ�����k���ڵ�
SListNode *FindK(SListNode *head, SLTDataType k)
{
	if (head == NULL)
	{
		return;
	}
	SListNode *fast = head;
	SListNode *slow = head;
	while (k)
	{
		if (fast == NULL)
		{
			return;
		}
		fast = fast->next;
		k--;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

void SListPrint(SListNode *phead)
{
	SListNode *tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		printf("%d->", tmp->data);
	}
	printf("NULL\n");
}