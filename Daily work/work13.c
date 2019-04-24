/* 1.ʵ��һ�����������������ַ����е�k���ַ��� 
ABCD����һ���ַ��õ�BCDA 
ABCD���������ַ��õ�CDAB */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include<string.h>
//�����㷨
void left_move1(char *str, int k)
{
	if (k<0 || k>strlen(str))
	{
		printf("���Ϸ�\n");
		return;
	}
	while (k)
	{
		char *cur = str;
		char tmp = *cur;
		while (*(cur + 1))
		{
			*cur = *(cur + 1);
			cur++;
		}
		*cur=tmp;
		k--;
	}
}
void Reverse(char *left, char *right)
{
	assert(left != NULL && right != NULL);
	while (left < right)
	{
		char tmp = 0;
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void Left_handed(char *arr, int k, int len)
{
	if (k<0 || k>strlen(arr))
	{
		printf("���Ϸ�\n");
		return 0;
	}
	int i = 0;
	char *p = arr;
	while (i < k)
	{
		p = arr + i;
		i++;
	}
	Reverse(arr, p);
	Reverse(p + 1, arr + len - 1);
	Reverse(arr, arr + len - 1);
}
int main()
{
	int k = 0;
	char arr[] = "ABCDE";
	int len = sizeof(arr) / sizeof(arr[0]) - 1;
	scanf("%d", &k);
	Left_handed(arr, k, len);

	left_move1(arr, k);

	printf("%s", arr);
	system("pause");
	return 0;
}

/*�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ����� 
���磺����s1 =AABCD��s2 = BCDAA������1 
����s1=abcd��s2=ACBD������0. 

AABCD����һ���ַ��õ�ABCDA 
AABCD���������ַ��õ�BCDAA 

AABCD����һ���ַ��õ�DAABC*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10
//strcat:��str1��str2����str2ƴ�ӵ�str1����
//strncat��(str1,str2,n)��str2��ǰn��ƴ�ӵ�str1����
//�����ַ���strstr��str1��str2����str1���濴�ܷ��ҵ�str2
//����ʵ��
void  Merge_string(char *arr)
{
	arr = strncat(arr, arr, strlen(arr));
	printf("%s\n", arr);
}
int Judge_string(char *arr1, char *arr2)
{
	Merge_string(arr1);
	if (strstr(arr1, arr2) != NULL)
	{
		return 1;
	}
	else
		return 0;
}

//�㷨ʵ��
void Merge_string(char *arr)
{
	int i = 0;
	for (i = 0; i < N - 5; i++)
	{
		arr[i + 5] = arr[i];
	}
}
int Judge_string(char *arr1, char *arr2)
{
	Merge_string(arr1);
	char *p = arr1;
	char arr3[6];
	int i = 0;
	int j = 0;
	while (*p != *arr2)
	{
		p++;
	}
	for (i = 0; i < 5; i++)
	{
		arr3[i] = *p;
		p++;
	}
	arr3[i] = '\0';
	printf("%s", arr3);
	for (j = 0; j < i; j++)
		if (strcmp(arr3, arr2) == 0)
			return 1;
		else
			return 0;
}
int main()
{
	char arr1[N + 1] = "ABCDE";
	char arr2[N] = "CDEAB";
	int result = 0;
	result = Judge_string(arr1, arr2);
	if (result)
	{
		printf("yes\n");
	}
	else
	{
		printf("No\n");
	}
	system("pause");
	return 0;
}