#define _CRT_SECURE_NO_WARNINGS 1

/*��Ŀ����
С�׾���������������Ϸ.��һ��,������һ�������������Ϸ,���Ľ�ɫ�ĳ�ʼ����ֵΪ a.
�ڽ�������һ��ʱ����,��������������n������,ÿ������ķ�����Ϊb1,b2,b3...bn. 
��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,��ô���������ɴ�ܹ���,�� ��ʹ���Լ�������ֵ����bi;
���bi����c,����Ҳ�ܴ�ܹ���,����������ֵֻ������bi ��c�����Լ��.��ô��������,��һϵ�еĶ�����,
С�׵���������ֵΪ����?

��������:
����ÿ������,��һ������������n(1��n<100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ.
�ڶ���n������,b1,b2...bn(1��bi��n)��ʾÿ������ķ�����
�������:
����ÿ������,���һ��.ÿ�н�����һ������,��ʾС�׵���������ֵ
ʾ��1
����
3 50 50 105 200 5 20 30 20 15 40 100
���
110
205*/

#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

int GetNum(int a, int n)
{
	if (a > n)
	{
		swap(a, n);
	}
	int max = 0;
	for (int i = 1; i <= a; i++)
	{
		if (n%i == 0 && a%i == 0)
		{
			if (i > max)
			{
				max = i;
			}
		}
	}
	return max;
}
int main()
{
	int n, a = 0;
	cin >> n >> a;
	vector<int> v(n);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	for (int j = 0; j < v.size(); j++)
	{
		if (v[j] <= a)
		{
			a += v[j];
		}
		else
		{
			a += GetNum(a, v[j]);
		}

	}
	cout << a << endl;
	system("pause");
	return 0;
}