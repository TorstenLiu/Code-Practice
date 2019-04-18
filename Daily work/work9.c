/*1.��д������
unsigned int reverse_bit(unsigned int value);
��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��

�磺
��32λ������25���ֵ�������и�λ��
00000000000000000000000000011001
��ת�󣺣�2550136832��
10011000000000000000000000000000
���������أ�
2550136832*/
#include<stdio.h>
#include<stdlib.h>

unsigned int reverse_bit(unsigned int value)
{
	unsigned int sum = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
		{
			sum += ((value>>i)&1)*pow(2,31-i);//1*2^31 + 0*2^30 + 0*2^29 +...+ 0*2^0
		}
	return sum;
}
int main()
{
	unsigned int n = 0;
	unsigned int result = 0;
	scanf("%d", &n);
	result = reverse_bit(n);
	printf("%u\n", result);
	system("pause");
	return 0;
}
/*2.��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��*/
//����һ ��ͼ�ɽ��
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d", &a, &b);
	c = b + (a - b) / 2;
	printf("%d", c);
	system("pause");
	return 0;
}
//��򷨣�����ԭʼ��a+b��/2����a+b��=��a&b��*2+a^b,(a+b)/2=(a&b)+(a^b)>>1 

//���ַ�������������CSDN

/*3.���ʵ�֣� 
һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
���ҳ�������֡���ʹ��λ���㣩 
*/
#include<stdio.h>
#include<stdlib.h>
int Find_Number(int *arr, int len)
{
	int temp = 0;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		temp = temp ^ arr[i];
	}
	return temp;

}
int main()
{
	int arr[] = { 1,2,3,4,3,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int result = 0;
	result = Find_Number(arr,len);
	printf("%d\n", result);
	system("pause");
	return 0;
}

/*��һ���ַ����������Ϊ:"student a am i", 
���㽫��������ݸ�Ϊ"i am a student". 
Ҫ�� 
����ʹ�ÿ⺯���� 
ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ��� 

student a am i 
i ma a tneduts 
i am a student*/
//�Ƚ������ַ������ã��ٽ�������������

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>

void Reverse_Swap(char *start,char *end)
{
	assert(start!=NULL);
	assert(end != NULL);
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}
void Reverse_Array(char *arr, int len)
{
	char *p = arr;
	while (*p)
	{
		char *start= p;
		while ((*p != ' ')&&(*p != '\0'))
		{
			p++;
		}
		Reverse_Swap(start,p-1);
		if (*p == ' ')
		{
			p++;
		}
	}
}
int main()
{
	char arr[] = "student a am I";
	int len =sizeof(arr)/sizeof(arr[0])-1;
	char *left = arr;
	char *right =arr+len - 1;
	Reverse_Swap(left, right);
	printf("%s\n", arr);
	Reverse_Array(arr,len);
	printf("%s\n", arr);
	system("pause");
	return 0;
}