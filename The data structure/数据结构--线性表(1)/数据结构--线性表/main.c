#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"//include���ã���seqlist.h��������к�����ͷ�ļ����������ȥ����չ��.h���õ�ͷ�ļ�����չ������ĺ�������


int main()
{

	SeqList test;
	SeqListInit(&test, 10);

	 SeqListPushBack(&test, 10);
	 SeqListPushBack(&test, 9);
	// SeqListPopBack(&test,);
	// SeqListPushFront(SeqList* psl, SLDataType x);
	// SeqListPopFront(SeqList* psl);
	//SeqListFind(SeqList* psl, SLDataType x);
	// SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
	// SeqListErase(SeqList* psl, size_t pos);//��������
	// SeqListRemove(SeqList* psl, SLDataType x);//�Ƴ�����,�Ƴ�����ֵΪx��Ԫ�� O(N)
	// SeqListModify(SeqList* psl, size_t pos, SLDataType x);//�޸ģ���pos��ֵ�ĳ�x O(1)
	// SeqListPrint(SeqList* psl);//O(N)	// SeqListBubbleSort(SeqList* psl);	//SeqListBinaryFind(SeqList* psl, SLDataType x);
	//// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
	//void SeqListRemoveAll1(SeqList* psl, SLDataType x);//O(n) �ռ临��O(1)	//void SeqListRemoveAll2(SeqList* psl, SLDataType x)//ʱ�临��O(n)  �ռ临��O(n)

	 SeqListPrint(&test);
	//SeqListDestory(&test);
	system("pause");
	return 0;
}
