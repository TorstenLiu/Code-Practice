#define _CRT_SECURE_NO_WARNINGS 1

/*��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ������� �Ӷ���������ÿ���µ���������Ϊ���٣�

���������� ����int�ͱ�ʾmonth
��������� �����������int��

ʾ��

���� 9
��� 34  */

/*˼·����n���µ�������������������ɣ�һ�������ϸ��µ�����f(n-1)��
��һ��������3���´�����ӣ�����һֻ����f(n2)�����Ե�n�������������� f(n) = f(n -1) +f(n -2)��
�������ڱ��࿼��쳲���������*/

#include<iostream>
using namespace std;


int GetNum(int month)
{
	if (month == 1 || month == 2)
	{
		return 1;
	}
	else
	{
		return GetNum(month - 1) + GetNum(month - 2);
	}
}
int main()
{
	int month = 0;
	cin >> month;
	cout << GetNum(month) << endl;
	system("pause");
	return 0;
}