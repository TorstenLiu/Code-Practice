//1.��ӡһ������
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*����һ��ѭ����
���鲽��˼·��CSDN����*/
int main()
{
	int line = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	scanf("%d", &line);
	//�ϰ벿��+���м�Ĳ���
	for (i = 0; i < line; i++)
	{

		for (j = 0; j < line-1-i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <2*i+1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	//�°벿��
	for (i = 0; i < line; i++)
	{
		for (j = 0; j <=i; j++)
		{
			printf(" ");
		}
		for (k = 0; k < 2 * (line - i - 1)-1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

/*���������ַ��ƶ���
�Ƚ����壬���Ǻ���*/
int main()
{
	char arr1[] = "      *      ";
	char arr2[] = "*************";
	char arr3[] = "             ";
	int left = 0;
	int right = strlen(arr1) - 1;
	int i = 0;
	while (i <= 6)
	{
		int mid = left + (right - left) / 2;
		arr3[mid - i] = arr2[mid - i];
		arr3[mid + i] = arr2[mid + i];
		i++;
		printf("%s\n", arr3);

	}
	while (left < right)
	{
		arr2[right] = arr1[right];
		arr2[left] = arr1[left];
		left++;
		right--;
		printf("%s\n", arr2);
	}
	system("pause");
	return 0;
}

//2.��0~999֮���ˮ����

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int i = 0;
	int a, b, c = 0;
	for (i = 100; i <= 999; i++)
	{
		a = i / 100;
		b = i / 10 % 10;
		c = i % 10;
		if(i==a*a*a+b*b*b+c*c*c)
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}
//�һ��  ����λ��?���粻����λ����Ҫ������������ж�λ�����ټ��η�
int main()
{
	//�жϼ�λ��

	int i = 0;
	for (i = 1; i < 99999; i++)
	{
		int sum = 0;//sum���ܷ������棬ÿһ�μ�����Ҫ��0
		int tmp = i;//tmpҲ��
		int count = 0;//countҲ��
		while (tmp != 0)//123 12 1 0
		{
			count++;
			tmp /= 10;
		}
		tmp = i;
		//���λ��������
		while (tmp != 0)
		{
			sum += pow((double)(tmp % 10), count);
			tmp = tmp / 10;
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}

//3.��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮��

#include<stdio.h>
#include<stdlib.h>

//�Ż�ѭ��
int main()
{
	int n = 0;
	int i = 0;
	int a = 0;
	int sum = 0;
	int tmp = 0;
	scanf("%d%d", &a, &n);
	for (i = 0; i < n; i++)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	printf("%d", sum);
	system("pause");
	return 0;
}