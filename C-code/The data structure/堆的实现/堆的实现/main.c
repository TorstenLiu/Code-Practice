#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

#define ARRSIZE(a)  (sizeof(a)/sizeof(a[0]))
int main()
{
	int a[] = { 1,6,3,9,8,7 };
	Heap hp;
	printf("��ʼ����\n");
	HeapInit(&hp, a, ARRSIZE(a));
	HeapPrint(&hp);
	printf("\n");

	printf("��100���\n");
	HeapPush(&hp, 100);
	HeapPrint(&hp);
	printf("\n");

	printf("����\n");
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("\n");

	printf("��öѶ�Ԫ��\n");
	HPDataType ret = HeapTop(&hp);
	printf("%d", ret);
	printf("\n");

	printf("������\n");
	HeapSort(&hp);
	HeapPrint(&hp);
	printf("\n");

	system("pause");
	return 0;
}