//1.дһ���������ز����������� 1 �ĸ���.���磺 15 0000 1111 4 �� 1
#include<stdio.h>
#include<stdlib.h>

int count_one_bits1(unsigned int value)//�˷�������Ҫ��unsigned �Ѹ�������޷�����
{
	int count = 0;
	while (value)
	{
		if (value % 2 == 1)
		{
			count ++;
		}
		value=value >> 1;//value/=2
	}
	return count;
}
int count_one_bits2(int value)//����unsigned ҲOK
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((value >> i) & 1) == 1)
			count++;

	}
	return count;
}
int count_one_bits3(unsigned int value)//�������ֱ���޷�����
{
	int count = 0;
	while (value)
	{
		value = value & (value - 1);
		count++;
	}
	return count;
}
int main()
{
	int x = 0;
	int result = 0;
	scanf("%d", &x);
	result = count_one_bits3(x);
	printf("%d\n", result);
	system("pause");
	return 0;
}

/*2.��ȡһ�������������������е�ż��λ������λ��
�ֱ�������������С�*/
#include<stdio.h>
#include<stdlib.h>

void Function(int num)
{
	int i = 0;
	printf("ż��λΪ��");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
	printf("����λΪ��");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", (num >> 1) & 1);
	}
}
int main()
{
	int odd = 0;
	int even = 0;
	int num = 0;
	scanf("%d", &num);
	Function(num);
	system("pause");
	return 0;
}
/*3.���ʵ�֣�
����int��32λ������m��n�Ķ����Ʊ���У�
�ж��ٸ�λ(bit)��ͬ��
�������� :
1999 2299
������� : 7*/
#include<stdio.h>
#include<stdlib.h>

int Different_bits(int a, int b)
{
	int tmp = a ^ b;//��һ���Ľ������
	int count = 0;
	while (tmp)
	{
		tmp = tmp & (tmp - 1);
		count++;
	}
	return count;
}
int main()
{
	int a, b = 0;
	int result = 0;
	scanf("%d %d", &a, &b);
	result = Different_bits(a, b);
	printf("%d\n", result);
	system("pause");
	return 0;
}

