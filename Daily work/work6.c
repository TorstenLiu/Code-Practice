//1.�ж��Ƿ�Ϊ���꣨��������
#include<stdio.h>
#include<stdlib.h>

char Leap_year(int x)
{
	if ((x % 400 == 0) || (x % 100 != 0 && x % 4 == 0))
	{
		return 'T';
	}
	return 'F';
}

int main()
{
	int year = 0;
	char result = 0;
	scanf("%d", &year);
	result = Leap_year(year);
	printf("%c\n", result);
	system("pause");

	return 0;
}

//2.�ж�һ�����ǲ�������
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Is_Prime(int n)
{
	int i = 0;
	for (i = 2; i <= sqrt((double)n); i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	if (Is_Prime(num) == 1)
	{
		printf("is prime\n");
	}
	printf("Not prime\n");
	system("pause");
	return 0;
}


//3.ʹ��ʵ���������Ľ���
#include<stdio.h>
#include<stdlib.h>

void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	Swap(&a, &b);
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}


//4.�Լ����һЩ������ʹ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��ʼ������
void init(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr[i] = i;
	}
}
//������飬��Ϊ0
void empty(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}
void swap(int *arr, int left, int right)
{
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}
//������Ԫ������
void reverse(int arr[], int size)
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		swap(arr, left, right);
		left++;
		right--;
	}
}
void print(int arr[], int size)//arr[]=*arr
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d", arr[i]);//[]�Դ������� arr[i]==*(arr+i),��ͨ�������±��ӡ��ȥ��*����ʲô���ͣ���+1���ƶ������ֽ�
	}
	printf("\n");
}
int main()
{
	int arr[3];
	int size = sizeof(arr) / sizeof(arr[0]);
	init(arr, size);
	print(arr, size);
	/*empty(arr,size);
	print(arr, size);*/
	reverse(arr, size);
	print(arr, size);
	system("pause");
	return 0;
}

//some thought-provoking questions:
/*
1.��������ʲôʱ��ȷ����С�ģ�  �����ʱ��
2.��������ʲôʱ�򿪱��ڴ�ģ�  ���е�ʱ��
3.�����￪���ڴ棿   ջ
4.��󿪱ٶ����ڴ棿  1M����2M
*/