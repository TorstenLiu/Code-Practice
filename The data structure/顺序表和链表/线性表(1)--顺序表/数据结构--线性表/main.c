#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"//include���ã���seqlist.h��������к�����ͷ�ļ����������ȥ����չ��.h���õ�ͷ�ļ�����չ������ĺ�������


int main()
{

	SeqList test;
	SeqListInit(&test, 10);

	 SeqListPushBack(&test, 10);
	 SeqListPushBack(&test, 9);
	 SeqListPushBack(&test, 8);
	 SeqListPushBack(&test, 8);
	 SeqListPushBack(&test, 8);

	 SeqListPushBack(&test, 7);
	 SeqListPushBack(&test, 6);


	 SeqListPopBack(&test, 6);

	 SeqListPushFront(&test, 6);
	 SeqListPopFront(&test, 6);

	 SLDataType ret1 = SeqListFind(&test, 10);
	 printf("Ԫ��10���±��ǣ�%d\n", ret1);

	 SeqListInsert(&test, SeqListFind(&test,8), 15);
	 SeqListPrint(&test);
	 //SeqListErase(&test, SeqListFind(&test, 15));
	 SeqListRemove(&test,15);
	 SeqListPrint(&test);

	 SeqListModify(&test, SeqListFind(&test, 8), 18);
	 SeqListPrint(&test);

	 SeqListBubbleSort(&test);

	 SeqListPrint(&test);
	 SLDataType ret2 = SeqListBinaryFind(&test, 10);
	 printf("10���±��ǣ�%d\n", ret2);

	 //SeqListRemoveAll1(&test, 8);
	 SeqListRemoveAll2(&test, 8);
	 SeqListPrint(&test);

	 SeqListDestory(&test);
	 SeqListPrint(&test);
	system("pause");
	return 0;
}
