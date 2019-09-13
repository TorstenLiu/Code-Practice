#define _CRT_SECURE_NO_WARNINGS 1

//����һ���������飬�����и���������һ��������(ע��������)�Ķ���������һ�������飬������������͵����ֵ��O(n)
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

//������⣬��ÿһ�������γ�Ϊÿһ����Ͷ�Ҫ��ӵ���ʼ�������Ӷ�ΪO(n^2)
int MaxSum1(int *arr, int len)
{
	int sum, max = INT_MIN;
	int i, j;
	for (i = 0; i < len; i++)
	{
		sum = 0;
		for (j = i; j < len; j++)
		{
			sum += arr[j];
			if (max < sum)
			{
				max = sum;
			}
		}
	}
	return max;
}
//�������Ĵ���ʵ����ֻ�õ�һ������Ϊ��Ϊÿһ����Ͷ�Ҫ��ӵ���ʼ����
//int MaxSum(int *arr, int len)
// {
//	int sum = 0;
//	int i = 0;
//	int k = 0;
//	int str[MAX];
//	for (i = 0; i < len; i++)
//	{
//		sum += arr[i];
//		str[i] = sum;
//	}
//	int Max = str[0];
//	for (k = 0; k < len; k++)
//	{
//		if (str[k] > Max)
//		{
//			Max = str[k];
//		}
//	}
//	return Max;
//}

//2�����̰���㷨��һ���ӵ�ĳ��Ԫ�س���sumΪ�������������ǰ�������Ԫ�أ�����һ��Ԫ�ش����¿�ʼ��͡�O(n)
int MaxSum2(int *arr, int len)
{
	int sum = 0;
	int max = INT_MIN;
	int i, j;
	for (i = 0; i < len; i++)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
		}
		if (sum > max)
		{
			max = sum;
		}
	}
	return max;
}
int main()
{
	int arr[] = { 1,-2,3,10,-4,7,2,-5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int result = MaxSum2(arr,len);
	printf("%d", result);
	system("pause");
	return 0;
}