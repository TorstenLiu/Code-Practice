#define _CRT_SECURE_NO_WARNINGS 1

#include"Slist.h"
//1����������
//int main()
//{
//	SListNode *phead=NULL;
//	int value = 0;
//
//	SListInit(&phead);//��ͷָ�����������ֻ��������õ�������ָ������ݣ�����ΪNULL
//
//
//	SListPushFront(&phead, 6);
//
//	SListPushFront(&phead, 1);
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 3);
//	SListPushFront(&phead, 4);
//	SListPushFront(&phead, 6);
//
//
//	SListPrint(phead);
//
//	SListRemove(&phead, 6);
//	SListPrint(phead);
//	/*SListPopFront(&phead, 4);
//	SListPopFront(&phead, 3);*/
//
//	value = SListFind(phead, 1);
//    printf("%d\n", value);
//
//	SListInsertAfter(SListFind(phead,2), 10);
//	SListPrint(phead);
//
//
//	SListEraseAfter(SListFind(phead, 2));
//	SListPrint(phead);
//
//	SListDestory(&phead);
//	SListPrint(phead);
//	system("pause");
//	return 0;
//}

////2.Լɪ�򻷲��� ���CSDN��https://mp.csdn.net/mdeditor/98895581
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
//
//	//���η��������γ�����
//	for (i = m - 1; i >=1; i--)
//	{
//		SListPushFront(&phead, i);
//	}
//	plast->next = phead;//�γ�һ����
//
//	cur = plast;//ֻ�е�һ�����ĸ�����һ�����������Ա�֤��һ�ε���ȷ
//
//	for (; m > 1; m--)
//	{
//		for (i = 1; i < n; i++)	//��������n-1��ɾ
//		{
//			cur = cur->next;
//			printf("%d�ű�%d\n", cur->data, i);
//		}
//		printf("%d�ų�Ȧ\n", cur->next->data, i);
//		SListEraseAfter(cur);
//	}
//	printf("%d��ʤ��\n", cur->data);
//	free(cur);
//	system("pause");
//	return 0;
//}


//3.��תһ��������
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

//4.������������ĵ�һ�������ڵ�
//�Ҷ��룬�������߲�ֵ������һ�����
//int main()
//{
//	int i = 0;
//	int j = 0;
//	SListNode* phead1;
//	SListNode* phead2;
//	SListInit(&phead1);
//	SListInit(&phead2);
//
//	SListPushFront(&phead1, 5);
//	SListPushFront(&phead1, 4);
//	SListPushFront(&phead1, 8);
//	SListPushFront(&phead1, 1);
//	SListPushFront(&phead1, 4);
//
//	SListPushFront(&phead2, 5);
//	SListPushFront(&phead2, 4);
//	SListPushFront(&phead2, 8);
//	SListPushFront(&phead2, 1);
//	SListPushFront(&phead2, 0);
//	SListPushFront(&phead2, 5);
//
//
//	SListNode* ret=getPublicPoint(phead1, phead2);
//	if (ret==NULL)
//	{
//		printf("NULL\n");
//	}
//	else
//	{
//		printf("%d\n", ret->data);
//	}
//	system("pause");
//
//	return 0;
//}

//5.����ж������Ƿ��л�
//��һ���ڵ�һ�������Σ�һ����һ�Ρ��������������һ���ǻ����ܵ���ͷ����û��
//int main()
//{
//	SListNode *phead;
//	SListNode *plast = NULL;
//	SListInit(&phead);
//
//	SListPushFront(&phead, 1);
//	plast = phead;
//
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 3);
//	SListPushFront(&phead, 4);
//
//	plast->next = phead;
//	SListNode * ret = JugdeCircle(phead);
//	printf("%d\n", ret->data);
//	system("pause");
//	return 0;
//}

//6.����һ�������жϻ�����������ʼ�뻷�ĵ�һ���ڵ㣬�޻�����NULL
//���ͷ����ǻ���ڣ�һ���ڵ�һ����������һ����һ������ͷ����ǻ����
//���ͷ��㲻�ǻ���ڣ������Ĳ��ֵ�����ڵĳ��Ⱥ������㵽����ڵĳ�����ͬ��
//�����������ڵ��ͷ���һ��һ����ʼ�ߣ��ҵ������㣬����൱��������Ҷ��롣
//Ȼ�������ڵ���fast��headһ���ߣ��ҵ��Ĺ����ڵ���ǻ����
//int main()
//{
//	SListNode *phead;
//	SListNode *plast=NULL;
//
//	SListInit(&phead);
//
//	SListPushFront(&phead, 1);
//	plast = phead;
//
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 3);
//	SListPushFront(&phead, 4);
//
//	plast->next = phead;
//
//	SListNode *ret = detectCircle(phead);
//	printf("%d", ret->data);
//	SListPrint(phead);
//	system("pause");
//	return 0;
//}

int main()
{
	SListNode *phead;
	SListInit(&phead);

	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
	SLTDataType k = 0;
	scanf("%d", &k);
	SListNode *ret = FindK(phead, k);
	printf("%d", ret->data);
	system("pause");
	return 0;
}

