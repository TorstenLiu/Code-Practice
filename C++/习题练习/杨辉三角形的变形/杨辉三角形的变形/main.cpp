#define _CRT_SECURE_NO_WARNINGS 1

/*��Ŀ������
            1
         1  1  1
      1  2  3  2  1
   1  3  6  7  6  3  1
1  4  10 16 19  16 10  4  1
���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����

���n�е�һ��ż�����ֵ�λ�á����û��ż���������-1����������3,�����2������4�����3��

����n(n <= 1000000000)
����һ��int����
������ص�intֵ
ʾ��1:
����
4
���
3*/
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n = 0;
	int flag = 1;
	cin >> n;
	vector<vector<int>> vv(n, vector<int>(2 * n - 1, 0));//2*n-1����еĿռ�
	for (int i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j <2*i+1; j++)//j��i���кţ���ϵ��2*i+1
		{
			if (i == 0 || j == 0)
			{
				vv[i][j] = 1;
			}
			else if (j == 1)//�ڶ���ֻ�����������
			{
				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
			}
			else
			{
				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1] + vv[i - 1][j -2];
			}
		}
	}
	for (int k = 0; k < vv[n-1].size(); k++)
	{
		if (vv[n-1][k] % 2 == 0)
		{
			cout << k + 1 << endl;
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		cout << -1 << endl;
	}
	system("pause");
	return 0;
}