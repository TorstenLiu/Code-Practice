//1.��ӡ100~200֮�������
/*i/2:һ����������Լ�������Ǹ�ֵС�ڵ���i/2
sqrt(i):һ����������Լ��������С���Ǹ�С��sqrt(i)
ż��һ����������������ֻ��������i+=2*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int i = 0;
	for (i = 101; i <= 200; i++)
	{
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}
//������

int is_prime(int i)//�Գ���
{
	int j = 0;
	for (j = 2; j < sqrt(i); j++)//��׼дһ����������һ��temp=sqrt(i)���ϰ汾��ÿһ�ζ��ظ��������ֵ���������Զž���������ͬӰ���Ч�����⡣
	{
		if (i%j == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i) == 1)
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}
//2.�ж�1000~2000֮�������,�ж��⣺����һ�������Ľ��
/*���꣺1.�ܱ�400������2.�ܱ�4���������ܱ�100��������������һ������*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int year = 0;

	for (year = 1000; year <= 2000; year++)
	{
		if (((year % 4 == 0 && year % 100 != 0)) || (year % 400 == 0))
		{
			printf("%d\n", year);
		}
	}
	system("pause");
	return 0;
}
//������
int is_leapyear(int i)
{
	return (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0));
	/*if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
		return 1;
	else
		return 0;*/
}
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (is_leapyear(year) == 1)
		{
			printf("%d\n", year);
		}
	}
	system("pause");
	return 0;
}

//3.��ӡ�˷��ھ���(��ӡ��
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j, q = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			q = i * j;
			printf("%d*%d=%-2d   ", i, j, q);//-�������
		}
		printf("\n");//putchar('\n');
	}
	system("pause");
	return 0;
}