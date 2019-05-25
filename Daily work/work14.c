//1.ʵ��strncpy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

char *My_strncpy(char *dest, const char *sour, int num)
{
	assert(dest != NULL);
	assert(sour != NULL);
	char *ret = dest;
	while (num)
	{
		*dest = *sour;
		dest++;
		sour++;
		num--;
	}
	return ret;

}
int main()
{
	char arr1[20] = "hello";
	char arr2[] = "world!";
	char *ret = My_strncpy(arr1, arr2, strlen(arr2) + 1);
	printf("arr1��������Ϊ��%s\n", ret);
	system("pause");
	return 0;
}

//2.ʵ��strncat
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char *My_strncat(char *dest, const char *sour, int num)
{
	assert(dest != NULL);
	assert(sour != NULL);
	char *str = dest;
	while (*dest)
	{
		dest++;
	}
	while (num)
	{
		*dest = *sour;
		dest++;
		sour++;
		num--;
	}
	return str;

}
int main()
{
	char arr1[20] = "hello";
	char arr2[] = "world!";
	char *ret = My_strncat(arr1, arr2, sizeof(arr2));
	printf("ƴ�Ӻ���ַ���Ϊ��%s\n", ret);
	system("pause");
	return 0;
}

//3.ʵ��strncmp
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int My_strncmp(const char *dest, const char *sour, int num)
{
	assert(dest != NULL);
	assert(sour != NULL);
	while (*dest == *sour&&dest&&sour)
	{
		dest++;
		sour++;
	}
	return (*dest) - (*sour);
}
int main()
{
	char arr1[] = "hello";
	char arr2[] = "helle";
	int result = My_strncmp(arr1, arr2, sizeof(arr2));
	if (result == 0)
	{
		printf("arr1��arr2��ͬ\n");
	}
	else if (result > 0)
	{
		printf("arr1>arr2\n");
	}
	else
	{
		printf("arr1<arr2");
	}
	system("pause");
	return 0;
}