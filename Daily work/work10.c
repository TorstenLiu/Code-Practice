/* 1.����һ���������飬ʵ��һ��������
�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
����ż��λ������ĺ�벿�֡�
*/
#include<stdio.h>
#include<stdlib.h>

void Sort_odd_even(int *arr, int len)
{
	int *left = arr;
	int *right = arr + len - 1;
	int tmp = 0;
	while (left < right)
	{
		while (left < right&&*left % 2 == 1)
		{
			left++;
		}
		while (left < right&&*right % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			int tmp = 0;
			tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}
void print(int *arr, int len)
{
	int*p = arr;
	while (*p < arr + len - 1)
	{
		printf(" %d\n", *p);
		p++;
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Sort_odd_even(arr, len);
	print(arr, len);
	system("pause");
	return 0;
}

/* 2.���Ͼ���
��һ����ά����.
�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
�������������в���һ�������Ƿ���ڡ�
ʱ�临�Ӷ�С��O(N);

���飺
1 2 3
2 3 4
3 4 5


1 3 4
2 4 5
4 5 6

1 2 3
4 5 6
7 8 9*/
//ʱ�临�Ӷ�С��O(N) ��ָ���ܽ������������ 

//�ⷨһ
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
int Find_number(int(*arr)[ROW], int row, int col, int n)
{
	int i, j;
	for (i = 0, j = 0; j < col; j++)
	{
		if (arr[i][j] == n)
			return 1;
	}
	for (i = 1; i < row; i++)
	{
		j = row - 1;
		if (arr[i][j] == n)
			return 1;
	}
	return 0;

}
int main()
{
	int arr[][3] = { 1,2,3,3,4,5,4,5,6 };
	int result = 0;
	int num = 0;
	scanf("%d", &num);
	result = Find_number(arr, ROW, ROW, num);
	if (result)
	{
		printf("find it\n"��;
	}
	else
			printf("can't find\n");
	system("pause");
	return 0;
}

//�ⷨ2���Ϻã�
#include<stdio.h>
#include<stdlib.h>

void Find_number(int arr[3][3], int *px, int *py, int key)//*px��*py�����к��У��ҵ��󷵻��±��ֵ���������
{
	int x = 0;
	int y = *py - 1;//��λ�����Ͻǵ�����
	while ((x <= (*px - 1)) && (y >= 0))
	{
		if (arr[x][y] == key)
		{
			*px = x;
			*py = y;
			return;//��������
		}
		else if (arr[x][y] > key)
		{
			y--;
		}
		else //arr[x][y]<key
		{
			x++;
		}
	}
	*px = -1;
	*py = -1;
}
int main()
{
	int arr[][3] = { 1,2,3,4,5,6,7,8,9 };
	int num = 0;
	int x = 3;//����Ϊ3
	int y = 3;//����Ϊ3
	scanf("%d", &num);
	Find_number(arr, &x, &y, num);//x��y����Ӧ�ĵ�ַ
	if (x != -1 && y != -1)
	{
		printf("find it,the location is %d,%d", x, y);
	}
	else
		printf("can't find\n");
	system("pause");
	return 0;
}