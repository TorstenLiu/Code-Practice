#define _CRT_SECURE_NO_WARNINGS 1

//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲��������� ���ƹ�ʽa1=1��an=an-1+an-2
//쳲���������  1  1  2  3  5  8  13  21  34
#include<stdio.h>
#include<stdlib.h>

//�ݹ�  ����
int Fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
		return Fib(n - 1) + Fib(n - 2);//���������n�����Ӷ�Ϊn^2,���д��ѭ������дβ�ݹ顣
}
int main()
{
	int n =0;
	int result = 0;
	scanf("%d", &n);
	result = Fib(n);
	printf("%d", result);
	system("pause");
	return 0;
}

//�ǵݹ�  ѭ�����ٶȷǳ���  ��ȡ
int Fib(int n)
{
	int first = 1;
	int second = 1;
	int third = 1;
	int i = 0;
	if (n <= 2)
	{
		return 1;
	}
	for (i = 3; i <= n; i++)
	{
		third = second + first;
		first = second;
		second = third;
	}
	return third;
}
int main()
{
	int n = 0;
	int result = 0;
	scanf("%d", &n);
	result = Fib(n);
	printf("%d", result);
	system("pause");
	return 0;
}