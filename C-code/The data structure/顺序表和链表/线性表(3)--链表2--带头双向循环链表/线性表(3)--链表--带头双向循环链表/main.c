#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"
int main()
{
	//���Ժ�������
	List list;//����һ���ṹ�壬����ֻ��һ��ָ��Ϊhead
	List list1;
	List list2;
	List list3;

	ListInit(&list);
	ListInit(&list1);
	ListInit(&list2);


	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushBack(&list, 5);
	ListPushBack(&list, 6);



	ListPopBack(&list);

	ListPushFront(&list, 4);
	ListPopFront(&list, 4);

	ListInsertFront(ListFind(&list, 3), 10);
	ListInsertafter(ListFind(&list,3), 10);

	ListErase(ListFind(&list, 3));
	//ListRemove(&list, 10);
//2.ȥ�أ���һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
	ListDistinct(&list);
	ListPrint(&list);
//2.��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//�⺯��ʵ�ַ�ʽ���⺯��������2�ϲ�������1
	ListPushBack(&list1, 1);
	ListPushBack(&list1, 2);
	ListPushBack(&list1, 3);
	ListPushBack(&list1, 4);
	ListPushBack(&list1, 5);
	ListPrint(&list1);

	ListPushBack(&list2, 2);
	ListPushBack(&list2, 4);
	ListPushBack(&list2, 6);
	ListPushBack(&list2, 7);
	ListPushBack(&list2, 9);
	ListPrint(&list2);
	
	ListPrint(ListMerger(&list1,&list2));
	system("pause");
	return 0;
}