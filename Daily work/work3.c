//1.������������ͬ�������ֵ����

#include<stdio.h>
#include<stdlib.h>

/*ѧ��д����
void show(int arr[],int len) ����������������׵�ַ����������� int *arrҲ���ԡ�*/

int main()
{
	int a[5] = { 0 };
	int b[5] = { 0 };
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	for (j = 0; j < 5; j++)
	{
		scanf("%d", &b[j]);
	}
	for (i = 0; i < 5; i++)
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
	for (i = 0; i < 5; i++)
		printf("%d", a[i]);//*��arr��ָ��ļӷ�
	printf("\n");
	for (j = 0; j < 5; j++)
		printf("%d", b[j]);
	system("pause");
	return 0;
}

//2.����һ�����������ֵ.����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ��

/*����1����һ����־tΪ1��-1*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int flag = 1;
	double sum = 0.0;
	for (i = 1; i <= 100; i++)
	{
		sum = sum + flag * 1.0 / i;// t ��iΪ������Ϊ����?��flag����Ϊint��double��i����Ϊdouble
		flag *= -1;
	}
	printf("%.8lf\n", sum);//����8λС��
	system("pause");
	return 0;
}


/*����������Ϊ������ż����*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	float i = 0;
	float j = 0;
	double sum1 = 0;
	double sum2 = 0;
	for (i = 1; i <= 99; i += 2)
	{
		sum1 += 1 / i;
	}
	for (j = 2; j <= 100; j += 2)
	{
		sum2 += 1 / j;
	}
	printf("%lf\n", sum1 - sum2);
	system("pause");
	return 0;
}

//3.����1~100�������У�9���ֵĴ���
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i / 10 == 9)//����if�ǲ��й�ϵ ����ִ�У� ��������������Ķ��������ͻ
			count++;
		if (i % 10 == 9)
			count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}