//1.���ͱ�����ֵ���������м�ֵ�����м�ֵ��һ�����Ż���
#include<stdio.h>

int main()
{
	int a = 2;
	int b = 3;
	//1.low�������м�ֵ
	/*int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;*/
	//2.��һ���Ż�
	/*a = a + b;
	b = a - b;
	a = a - b;*/
	//3.�����Ż� ���
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a=%d  b=%d\n", a, b);
	system("pause");
	return 0;
}
//2.�������������Լ��
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	int b = 0;
	int k = 0;
	scanf("%d%d", &a, &b);
	//շת�����
	while (a%b != 0)//a,b��ֵ��С���һ��
	{
		k = a % b;
		a = b;
		b = k;
	}
	//������
	for (i = 1; i < small(a, b); i++)
	{
		if (a%i == 0 && b%i == 0)
		{
			max = i;
		}
	}
	//��С��������a*b/max
	printf("���Լ��Ϊ%d\n", b);
	system("pause");
	return 0;
}

//3.���������Ӵ�С�������ʱ���ú�������
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 20;
	int b = 40;
	int c = 10;
	if (a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (a < c)
	{
		int tmp = a;
		a = c;
		c = tmp;
	}
	if (b < c)
	{
		int tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d\n", a, b, c);
	system("pause");
	return 0;
}

//4.��10�������������ֵ
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[10] = { 0 };
	int max = a[0];//�����һ���������
	int i = 0;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (i = 1; i < 10; i++)
	{
		if (a[i] >= max)
			max = a[i];
	}
	printf("%d\n", max);
	system("pause");
	return 0;
}