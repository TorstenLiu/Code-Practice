#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char* Transfor(char *str)
{
	char *pstr = str;
	char *end = NULL;
	char *newend = NULL;
	int count = 0;
	while (*str != '\0')
	{
		//����ո���Ŀ
		if (*str == ' ')
		{
			count++;
		}
		str++;
	}
	end = str;
	newend = str + 2 * count;//ת������ַ�������=ԭ���ַ�������+2*�ո���Ŀ
	//�Ӻ���ǰ����
	while (end != newend)//������ָ��ָ��ͬһ���ַʱ��ֹͣ
	{
		if (*end == ' ')
		{
			*newend = '0';
			newend--;
			*newend = '2';
			newend--;
			*newend = '%';
			newend--;
			end--;
		}
		else
		{
			*newend = *end;
			newend--;
			end--;
		}
	}
	return pstr;
}
int main()
{
	char str1[10] = "abc sb";
	//scanf("%s", str1);
	char *str2 = Transfor(str1);
	printf("%s", str2);
	system("pause");
	return 0;
}