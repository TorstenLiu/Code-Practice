/*1.5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ�������� 
Aѡ��˵��B�ڶ����ҵ�����
Bѡ��˵���ҵڶ���E���ģ�
Cѡ��˵���ҵ�һ��D�ڶ���
Dѡ��˵��C����ҵ�����
Eѡ��˵���ҵ��ģ�A��һ��
����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b, c, d, e = 0;
	for (a = 1; a <= 5; a++)
		for (b = 1; b <= 5; b++)
			if (a != b)
				for (c = 1; c <= 5; c++)
					if ((c != a) + (c != b) == 2)
						for (d = 1; d <= 5; d++)
							if ((d != c) + (d != b) + (d != a) == 3)
								for (e = 1; e <= 5; e++)
									if ((e != d) + (e != c) + (e != b) + (e != a) == 4)
										if ((b == 2) + (a == 3) == 1)
											if ((b == 2) + (e == 4) == 1)
												if ((c == 1) + (d == 2) == 1)
													if ((c == 5) + (d == 3) == 1)
														if ((e == 4) + (a == 1) == 1)
															printf("A,B,C,D,E����������Ϊ��%d %d %d %d %d\n", a, b, c, d, e);
	system("pause");
	return 0;
}

/*�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
A˵�������ҡ�
B˵����C��
C˵����D��
D˵��C�ں�˵
��֪3����˵���滰��1����˵���Ǽٻ���
�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x = 0;
	for (x = 'a'; x <= 'd'; x++)
		if ((x != 'a') + (x == 'c') + (x == 'd') + (x != 'd') == 3)
			printf("%c is the thief", x);
	system("pause");
	return 0;
}


//3.��ӡ�������
#include<stdio.h>
#include<stdlib.h>
#define max 100
int main()
{
	int i, j = 0;
	int n = 0;
	int a[max][max];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		a[i][0] = a[i][i] = 1;
		for (j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

