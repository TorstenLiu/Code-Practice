#define _CRT_SECURE_NO_WARNINGS 1

/*���ӣ�https://www.nowcoder.com/questionTerminal/a5190a7c3ec045ce9273beebdfe029ee
��Դ��ţ����

һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
���磺��������������ĺ�����{1, 1, 2, 3}��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��,���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�
��������:
��һ������һ��������n(n �� 1000)
�ڶ���Ϊn����������xi(xi �� 1000)

�������:
������Բ��������˵Ĵ�����
ʾ��1
����
3
1 1 1
���
2*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void GetCount(int sum, int mul, vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		mul *= v[i];
	}
}
int GetFun(int num, vector<int>& v)
{
	int count = 0;
	auto it = v.begin();
	while (it != v.end())
	{
		int sum = 0;
		int mul = 1;
		it = v.erase(it);
		GetCount(sum, mul, v);
		it++;
	}
	return count;
}
int main()
{
	int num = 0;
	cin >> num;
	vector<int> v(num);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	cout << GetFun(num, v);
	system("pause");
	return 0;
}