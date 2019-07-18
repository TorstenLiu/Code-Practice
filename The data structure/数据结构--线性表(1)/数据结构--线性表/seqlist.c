#define _CRT_SECURE_NO_WARNINGS 1


#include "seqlist.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->array = (SLDataType *)calloc(psl->array, psl->capacity * sizeof(SLDataType));
	psl->capacity = capacity;
	int size = 0;
}
void SeqListDestory(SeqList* psl)
{
	if (psl)
	{
		free(psl->array);
		psl->array = NULL;
	}
	psl->size = 0;
	psl->capacity = 0;
}
void CheckCapacity(SeqList* psl)//ÿ����һ��push������Ҫ�����ж�,����������Ҫ������
{
	if (psl->size >= psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capacity * sizeof(SLDataType));
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)//β��
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)//βɾsize--�Ϳ�
{
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)//ͷ�壬Ϊ�˷�ֹ������Ҫ�Ӻ���ǰ����������ǵ�size++
{
	int i;
	CheckCapacity(psl);
	for (i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)//ͷɾ��������ǰǰ��һλ�Ϳɣ�ɾ��ǵ�size--
{
	int i=0;
	for (i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//��ֵΪx��Ԫ�ص��±�
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			break;
		}
	}
	return i;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//��pos��λ�ò���x����posλ�������ƣ���ͷɾ��ͬ
{
	int i;
	CheckCapacity(psl);
	for (i = psl->size - 1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos)//����posλ�õ����ݣ���ͷɾ��ͬ
{
	int i = 0;
	for (i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void SeqListRemove(SeqList* psl, SLDataType x)//�Ƴ�����,ɾ��ֵΪx��ֵ
{
	SeqListErase(psl, SeqListFind(psl, x));//�Ƴ���һ��ֵΪx��Ԫ��

}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//�޸ģ���pos��ֵ�ĳ�x
{
	int i = 0;
	for (i = psl->size - 1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListPrint(SeqList* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d", psl->array[i]);
	}
}
void SeqListBubbleSort(SeqList* psl)
{
	int i, j = 0;
	for (i = 0; i < psl->size; i++)
	{
		for (j = i+1; j < psl->size; j++)
		{
			int tmp = 0;
			if (psl->array[i] > psl->array[j])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[i];
				psl->array[i] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	int left = 0;
	int right = psl->array[psl->size];
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (psl->array[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->array[mid] > x)
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	return -1;
	
}
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
void SeqListRemoveAll1(SeqList* psl, SLDataType x)//�������ֵΪx�����ݣ���λ
{
	int gap = 0;
	int i = 0;
	for (i = 0; i < psl->size - gap; i++)
	{
		if (psl->array[i + gap] == x)
		{
			gap++;
			if ((gap + i) >= psl->capacity)
			{
				break;
			}
		}
		psl->array[i] = psl->array[i + gap];
	}
	psl->size = psl->size - gap;
}
void SeqListRemoveAll2(SeqList* psl, SLDataType x)//�����в�Ϊx��ֵ����������һ������tmp��
{
	SLDataType * tmp= (SLDataType *)calloc(psl->capacity, psl->capacity * sizeof(SLDataType));
	int i, j = 0;
	for (i = 0, j = 0; i < psl->size; i++)
	{
		if (psl->array[i] != x)
		{
			tmp[j] = psl->array[i];
			j++;
		}
		free(psl->array);
		psl->array = tmp;
		psl->size = j;
	}
}