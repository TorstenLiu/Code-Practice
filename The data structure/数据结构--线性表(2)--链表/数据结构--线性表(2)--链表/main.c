#define _CRT_SECURE_NO_WARNINGS 1

#include"Slist.h"

int main()
{
	SListNode *phead=NULL;
	int value = 0;

	SListInit(&phead);//��ͷָ�����������ֻ��������õ�������ָ������ݣ�����ΪNULL


	SListPushFront(&phead, 6);

	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPushFront(&phead, 6);


	SListPrint(phead);

	SListRemove(&phead, 6);
	SListPrint(phead);
	/*SListPopFront(&phead, 4);
	SListPopFront(&phead, 3);*/

	value = SListFind(phead, 1);
    printf("%d\n", value);

	SListInsertAfter(SListFind(phead,2), 10);
	SListPrint(phead);


	SListEraseAfter(SListFind(phead, 2));
	SListPrint(phead);

	SListDestory(&phead);
	SListPrint(phead);
	system("pause");
	return 0;
}

//Լɪ�򻷲���
//int main()
//{
//	int i = 0;
//	int n = 0;//��������
//	int m = 0;//����������
//	SListNode* phead;
//	SListNode* plast=NULL;
//	SListNode* cur=NULL;
//	scanf("%d %d", &n, &m);
//	SListInit(&phead);
//	//�Ȱ��������Ž�ȥ
//	SListPushFront(&phead, m);
//	plast = phead;
//	//���η��������γ�����
//	for (i = m - 1; i >=1; i--)
//	{
//		SListPushFront(&phead, i);
//	}
//
//	plast->next = phead;//�γ�һ����
//	cur = plast;
//
//	for (; m > 1; m--)
//	{
//		for (i = 1; i < n; i++)	//����
//		{
//			cur = cur->next;
//		}
//		SListEraseAfter(cur);
//	}
//	printf("%d", cur->data);
//	free(cur);
//	system("pause");
//	return 0;
//}


//��תһ��������
//int main()
//{
//	SListNode *phead = NULL;
//	SListNode *tmp;
//	SListInit(&phead);
//
//	SListPushFront(&phead, 1);
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 3);
//	SListPushFront(&phead, 4);
//	SListPrint(phead);
//
//	//SListReverse1(&phead);
//	SListReverse2(&phead);
//	SListPrint(phead);
//	system("pause");
//	return 0;
//}