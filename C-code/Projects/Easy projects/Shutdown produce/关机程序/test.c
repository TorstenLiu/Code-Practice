#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char input[20] = { 0 };
	system("shutdown -s 60");
	while (1)
	{
		printf("��ĵ��Խ�����60s�ػ�������������ֹͣ�ػ�");
		scanf("%s", input);
		if (strcmp(input, "������") == 0)
		{
			system("shutdown -a");
			break;
		}
	}
	return 0;
}