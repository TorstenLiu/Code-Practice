#include<stdio.h>
#include<stdlib.h>

int main()
{
	int count = 0;
	int n = 0;
	int i, j = 0;
	int s, r = 0;
	int a[3000];
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	a[0] = 1;
	for (i = 2; i <= n; i++)
	{
		for (j = 0; j < 3000; j++)
		{
			s = a[j] * i + r;
			r = s / 10;
			a[j] = s % 10;
		}
	}
	for (j = 2999; j >= 0; j--)//�����ų���ֱ��������0������������������j��ֵ
	{
		if (a[j])
			break;
	}
	for (i =j; i >=0; i--)//�����ӡ
	{
		
		printf("%d", a[i]);
	}
	system("pause");
	return 0;
}









//#include <stdio.h>
//#include<stdlib.h>
//#include<math.h>
//void dgCal(int a[], int pos)
//{
//	int i, cy = 0;
//	for (i = 0; i <= pos; i++)
//	{
//		a[i] += cy;
//		if (a[i] <= 9)
//		{
//			cy = 0;
//		}
//		else if (a[i] > 9 && i < pos)
//		{
//			cy = a[i] / 10;
//			a[i] = a[i] % 10;
//		}
//		else if (a[i] > 9 && i >= pos)
//		{
//			while (a[i] > 9)
//			{
//				cy = a[i] / 10;
//				a[i] = a[i] % 10;
//				i++;
//				a[i] = cy;
//			}
//		}
//	}
//}
//int main()
//{
//	int num, i, j;
//	int pos;//����±�λ
//	int *a;
//	scanf("%d", &num);
//	double sum = 0;
//	for (i = 1; i <= num; i++)//�ж��ж���λλ��
//	{
//		sum += log10((double)i);
//	}
//	int digit = (int)sum + 1;//λ��
//	if (!(a = (int *)malloc(sizeof(int)*digit)))//����ռ�
//	{
//		printf("�����ڴ�ʧ��\n");
//		return 0;
//	}
//	for (i = 0; i <= digit; i++)
//	{
//		a[i] = 0;
//	}
//	a[0] = 1;
//	for (i = 2; i <= num; i++)
//	{
//		for (j = digit; j >= 0; j--)
//		{
//			if (a[j] != 0)
//			{
//				pos = j;
//				break;
//			}
//		}
//		for (j = 0; j <= pos; j++)
//		{
//			a[j] *= i;//������
//		}
//		dgCal(a, pos);
//	}
//	for (j = digit; j >= 0; j--)//
//	{
//		if (a[j] != 0)
//		{
//			pos = j;
//			break;
//		}
//	}
//	printf("%d�Ľ׳�λ����%d\n", num, pos + 1);
//	for (i = pos; i >= 0; i--)
//	{
//		printf("%d", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}









//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//	int n = 0;
//	int i, j;
//	int r = 0;
//	int s = 0;
//	int a[3000];
//	scanf("%d", &n);
//	memset(a, 0, sizeof(a));
//	a[0] = 1;
//	for (i = 2; i <= n; i++)
//	{
//		for (j = 0; j < 3000; j++)
//		{
//			s = a[j] * i + r;
//			r = s/ 10;
//			a[j] = s % 10;
//		}
//	}
//	//�����ӡ���
//	for (i = 3000 - 1; i >= 0; i--)
//	{
//		if (a[i])
//			break;
//	}
//	for (j = i; j >=0; j--)
//	{
//		printf("%d", a[j]);
//	}
//	system("pause");
//	return 0;
//}