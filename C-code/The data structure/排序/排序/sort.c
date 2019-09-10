#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//��������
void delQsort(int *arr,int start,int end)
{
	int flag = 1;
	int i = start;
	int j = end;

	while (start < end)
	{
		while (arr[start] > arr[end])
		{
			swap(&arr[start], &arr[end]);
			flag = !flag;
		}
		flag ? end-- : start++;

	}
	delQsort(arr, start, i - 1);
	delQsort(arr, i, end);

}

void qsort(int *arr, int start, int end)
{
	if (start > end)
	{
		return;
	}
	int key = arr[start];
	int left = start;
	int right = end;
	while (left < right)
	{
		while (left < right&&arr[right] >= key)
		{
			right--;
		}
		arr[left] = arr[right];
		while (left < right&&arr[left] <= key)
		{
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = key;
	qsort(arr, start, left - 1);
	qsort(arr, left + 1, end);
}

//�鲢����nlogn
void delMergeSort(int *arr,int *tmp,int start,int end)
{
	int mid = 0;
	if (start >= end)//��Ҷ�ӽڵ�
	{
		return;
	}
	else
	{
		mid = (start + end) / 2;//����������
		delMergeSort(arr, tmp, start, mid);//��
		delMergeSort(arr, tmp, mid+1, end);//��
		//����Ϊ�������
	}
	int a = start;
	int b = mid + 1;
	int c = a;
	for (; a <= mid && b <= end; c++)//ab����������һ��Ԫ����ȫ������cʱ��ѭ������
	{
		if (arr[a] >= arr[b])
		{
			tmp[c] = arr[b];
			b++;
		}
		else
		{
			tmp[c] = arr[a];
			a++;
		}
	}
	//a������bʣ����c
	for (; b <= end; c++, b++)
	{
		tmp[c] = arr[b];
	}

	//b������aʣ�¿���c
	for (; a <= mid; c++, a++)
	{
		tmp[c] = arr[a];
	}
	int i = 0;
	for (i = 0; i <= c; i++)
	{
		arr[i] = tmp[i];
	}
	
}
//�鲢����nlogn
void MergeSort(int *arr, int n)//�����б��ʺϵݹ飬��Ϊ��Ҫ��ʱ�ռ�tmp����������൱�ڽӿ�
{
	int *tmp = (int *)malloc(sizeof(int));
	delMergeSort(arr, tmp, 0, n - 1);
	free(tmp);
}
void print(int *arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
}