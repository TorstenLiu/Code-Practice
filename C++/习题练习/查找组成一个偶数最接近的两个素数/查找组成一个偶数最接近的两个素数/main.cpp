#define _CRT_SECURE_NO_WARNINGS 1

/*���ӣ�https://www.nowcoder.com/questionTerminal/f8538f9ae3f1484fb137789dec6eedb9
��Դ��ţ����

����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��ż��������������ֵ��С��������

��������:
����һ��ż��



�������:
�����������

ʾ��1
����
20
���
7
13*/

#include<iostream>
using namespace std;
#include<vector>

bool IsPrime(int num)
{
	if (num == 1)
	{
		return false;
	}
	else
	{
		for (int i = 2; i < num; i++)
		{
			if (num%i == 0)
			{
				return false;
			}
		}
	}
	return true;
}
void Get(int num, int *min, int *max)
{
	vector<int> v(num / 2);
	int distance = num;
	int j = 0;
	int Max = 0;
	int Min = 0;
	for (int i = 1; i <= num; i++)
	{
		if (IsPrime(i))
		{
			v[j] = i;
			j++;
		}
	}
	for (int k = 0; k < v.size(); k++)
	{
		for (int t = 1; t < v.size(); t++)
		{
			if (v[k] + v[t] == num)
			{
				*min = v[k];
				*max = v[t];
				if (distance > abs(*max - *min))
				{
					Max = *max;
					Min = *min;
					distance = abs(*max - *min);
				}
			}
		}
	}
	*max = Max;
	*min = Min;
}
int main()
{
	int num = 0;
	cin >> num;//ע����ţ����������ʱҪ��whileѭ������
	int min = 0;
	int max = 0;
	Get(num, &min, &max);
	cout << min << endl;
	cout << max << endl;
	system("pause");
	return 0;
}