#define _CRT_SECURE_NO_WARNINGS 1

/*���ӣ�https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
��Դ��ţ����

ţţ��������������Ϊһ��������һ��������������,��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A,
��������һ�������ǰ�����A��Ϊ���ɶ�����������,ţţ��֪�������ٿ��԰���������Ϊ��������������.
��������ʾ,ţţ���԰�����A����Ϊ[1,2,3]��[2,2,1]��������������,������Ҫ����Ϊ2������������,�������2*/
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int len = 0;
	cin >> len;
	vector<int> v(len);
	for (int i = 0; i < len; i++)
	{
		cin >> v[i];
	}
	int i = 0;
	int count = 0;
	if (len == 1)
	{
		count = 1;
	}

	while (i < len)
	{
		if (v[i + 1] > v[i])
		{
			while (i < len - 1 && v[i + 1] >= v[i])
			{
				i++;
			}
			count++;
			i++;
		}
		else if (v[i + 1] < v[i])
		{
			while (i < len - 1 && v[i + 1] <= v[i])
			{
				i++;
			}
			count++;
			i++;
		}
		else
		{
			i++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}