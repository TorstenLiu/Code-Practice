#define _CRT_SECURE_NO_WARNINGS 1

//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
#include<stdio.h>
#include<stdlib.h>

void Print1(int num)
{
	if (num > 9)
	{
		Print1(num / 10);
	}
	printf("%d  ", num % 10);
}
//�����ǽ���ת�����⣺mΪ����
void Print(int num,int m)
{
	if (num > 9)
	{
		Print(num / m,m);
	}
	putchar("0123456789ABCDEF"[num % m]);//����ܴ�ӡ16����
}
int main()
{
	int num = 0;
	int m = 0;
	scanf("%d %d", &num, &m);
	Print(num,m);
	system("pause");
	return 0;
}