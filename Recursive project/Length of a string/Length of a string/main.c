#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//�ݹ�
int Strlen(const char *str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + Strlen(str+1);
}
int main()
{
	char *arr = "abcd";
	int result = 0;
	result = Strlen(arr);
	printf("%d", result);
	system("pause");
	return 0;
}
//�ǵݹ�
int Strlen(char *str)
{
	int count = 0;
	assert(str != NULL);//����  ����ָ���Ҫ��  ��һ���겻�Ǻ��� ֻ��Debug�����¹���
	while (*str != '\0')//��Ϊ�ַ�����\0��β
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char *arr = "abcd";
	int result = 0;
	result = Strlen(arr);
	printf("%d", result);
	system("pause");
	return 0;
}