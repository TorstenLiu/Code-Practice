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
	//�����������ϰ벿��+���м�Ĳ���
	for (i = 1; i < =line; i++)
	{

		for (j = 1; j < line-i; j++)
		{
			printf(" ");
		}
		for (k = 1; k <2*i-1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	/*for (i = 1; j < line + i; j++)
	{
		putchar(j < line - i ? ' ': '*');
	}*/

	//�°벿��
	for (i = line-1; i >0; i--)
	{
		for (j = 1; j < line - i; j++)
		{
			printf(" ");
		}
		for (k = 1; k < 2 * i - 1; k++)
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
//�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ������������������ķ˹׳����ķ˹��������Armstrong number������ָһNλ�����������֮N�η��͵��ڸ����� 
//����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
/*153 = 1 ^ 3 + 5 ^ 3 + 3 ^ 3��
370 = 3 ^ 3 + 7 ^ 3 + 0 ^ 3��
371 = 3 ^ 3 + 7 ^ 3 + 1 ^ 3��
407 = 4 ^ 3 + 0 ^ 3 + 7 ^ 3��*/

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
	for (i = 0; i < 99999; i++)//��0~9999֮���
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

		//�жϼ�λ����
		int modflag = 1;
		if (i%modflag == 0)
		{
			count++;
			modflag *= 10;
		}
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

//3.��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮��.���磺2+22+222+2222+22222 

//��ʽ��an=an-1*10+a
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