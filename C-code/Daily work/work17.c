//1.���������ַ������ӵ�һ���ַ�����ɾ���ڶ����ַ��������е��ַ��� ����They are students. �� aeiou��
//ɾ�����һ���ַ������Thy r stdnts

#include<stdio.h>
#include<stdlib.h>
#include<string>

//����
void DelWords1(char *arr1, char *arr2,int len1,int len2)
{
	int i, j, k = 0;
	for (j = 0; j < len2; j++)
	{
		for (i = 0; i < len1; i++)
		{
			if (arr1[i] == arr2[j])
			{
				for (k = i; k <= len1; k++)
				{
					arr1[k] = arr1[k + 1];
				}
			}
		}
	}
}
//ָ��
void DelWords2(char *arr1, char *arr2)
{
	char *p = arr1;
	char *q = arr2;
	char *str = arr1;
	while (q != '\0')
	{
		while (p != '\0')
		{
			if (*p == *q)
			{
				str = p;
				while (str != '\0')
				{
					*str = *(str + 1);
					str++;
				}
			}
			p++;
		}
		q++;
	}
}
int main()
{
	char arr1[] = "They are students.";
	char arr2[] = "aeiou";
	DelWords(arr1, arr2, strlen(arr1), strlen(arr2));
	printf("%s", arr1);
	system("pause");
	return 0;
}