#define _CRT_SECURE_NO_WARNINGS 1

/*дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19*/
//���ƹ�ʽ��an=n%10+a(n/10)
#include<stdio.h>
#include<stdlib.h>

int DigitSum(int n)
{
	if (n==0)
		return 0;
	else
		return DigitSum(n / 10) + n % 10;//%��ֵ���ڷ��ص�ʱ���������
}
int main()
{
	int n = 0;
	int result = 0;
	scanf("%d", &n);
	result=DigitSum(n);
	printf("%d\n", result);
	system("pause");
	return 0;
}									