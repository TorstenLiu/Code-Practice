#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

#define SWAP(a,b,tmp){\
                  tmp=a;\
                  a = b;\
                  b = tmp\
                     }
void swap(HPDataType *a, HPDataType *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap2()//���˼��
{

}
//���µ����㷨������Ϊ���
void HeapAdjust(Heap *hp, int n)//nΪ�������±�
{
	int cur = n;
	while (cur * 2 + 1 < hp->size)//����ڵ㣬ΪҶ��ʱ����
	{
		//С����
		//�������ޡ������Һ���Ϊ�յ���������ܻ����Խ��
		if (hp->_a[cur] < hp->_a[2 * cur + 1])
		{
			//ֻҪǰ��Ϊ1���治ִ�� ���Բ�Խ��
			if (cur * 2 + 2 >= hp->size || hp->_a[2 * cur + 1]> hp->_a[2 * cur + 2])//������ң����󻻣����±�
			{
				swap(&hp->_a[cur], &hp->_a[2 * cur + 1]);
				cur = cur * 2 + 1;
			}
			//�Ҵ����󣬷�����Һ��ӻ������±�
			else
			{
				swap(&hp->_a[cur], &hp->_a[2 * cur + 2]);
				cur = cur * 2 + 2;
			}
		}
		//�Ѿ���������С���ң����һ������±�
		//�Һ��Ӵ���ʱ�Ž�
		else if (cur * 2 + 2 < hp->size &&  hp->_a[2 * cur + 1] < hp->_a[2 * cur + 2])
		{
			swap(&hp->_a[cur], &hp->_a[2 * cur + 2]);
			cur = cur * 2 + 2;
		}
		//����󣬱��Ҵ�
		else
		{
			break;
		}
	}
}
void HeapInit(Heap *hp, HPDataType *a, int n)//�ӵ�һ����Ҷ�ӿ�ʼ���µ���
{
	int i = 0;
	hp->capacity = MAXSIZE > n ? MAXSIZE : n;//Ԥ��n>MAXSIZE
	hp->size = n;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*hp->capacity);
	if (!hp->_a)
	{
		return;
	}
	memcpy(hp->_a, a, sizeof(HPDataType)*n);

	for (i = n / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(hp, i);
	}
}
void HeapDestory(Heap *hp)
{
	if (hp->_a)
	{
		free(hp->_a);
		hp->capacity = hp->size = 0;
	}
}
void HeapPush(Heap *hp, HPDataType x)
{
	int cur = hp->size;//�ҵ��±�
	if (hp->size >= hp->capacity)
	{
		hp->capacity *= 2;
		hp->_a = (HPDataType *)realloc(hp->_a, sizeof(HPDataType)*hp->capacity);
	}
	//β��
	hp->_a[hp->size] = x;
	hp->size++;
	//���ϵ���
	while (cur)
	{
		if (hp->_a[cur] > hp->_a[(cur - 1) / 2])//���ڰ�
		{
			swap(&hp->_a[cur], &hp->_a[(cur - 1) / 2]);
			cur = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(Heap *hp)
{
	//swap(hp->_a, hp->_a + hp->size - 1);
	swap(&hp->_a[0], &hp->_a[hp->size - 1]);
	hp->size--;
	HeapAdjust(hp, 0);
}
HPDataType HeapTop(Heap *hp)
{
	if (!hp->size)
	{
		return (HPDataType)0;
	}
	return hp->_a[0];
}
int HeapSize(Heap *hp)
{
	return hp->size;
}
int HeapEmpty(Heap *hp)
{
	return hp->size == 0;
}
void HeapPrint(Heap *hp)
{
	int i = 0;
	int tag = 0;
	int tmp = 1;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->_a[i]);
		if (i == tag)
		{
			putchar('\n');
			tmp *= 2;
			tag += tmp;
		}
	}
}

// ������
void HeapSort(Heap *hp)
{
	int tmp = hp->size;
	while (hp->size >= 1)
	{
		HeapPop(hp);
	}
	hp->size = tmp;
}