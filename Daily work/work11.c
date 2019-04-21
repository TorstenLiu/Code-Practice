/*1.ʵ��һ�����������������ַ����е�k���ַ��� 
ABCD����һ���ַ��õ�BCDA 
ABCD���������ַ��õ�CDAB */
#include<stdio.h>
#include<stdlib.h>

void Reverse(char *left, char *right)
{
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
	printf("%s", arr);
	system("pause");
	return 0;
}

/*2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ����� 
���磺����s1 =AABCD��s2 = BCDAA������1 
����s1=abcd��s2=ACBD������0. 

AABCD����һ���ַ��õ�ABCDA 
AABCD���������ַ��õ�BCDAA 

AABCD����һ���ַ��õ�DAABC
*/
