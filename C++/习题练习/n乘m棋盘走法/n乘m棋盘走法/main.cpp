#define _CRT_SECURE_NO_WARNINGS 1

/*���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ�������
���Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ�
�ܹ��ж������߷���Ҫ�����߻�ͷ·��
����ֻ�����Һ������ߣ���������������ߡ�*/
#include<iostream>
using namespace std;

int GetFun(int n, int m)
{
	if (n == 0 || m == 0)
	{
		return 0;
	}
	if (n == 1 && m >= 1)
	{
		return m + 1;
	}
	if (m == 1 && n >= 1)
	{
		return n + 1;
	}
	if (m > 1 && n > 1)
	{
		return GetFun(n - 1, m) + GetFun(n, m - 1);
	}
}
int main()
{
	int n = 0;
	int m = 0;
	while (cin >> n >> m)
	{
		cout << GetFun(n, m) << endl;
	}
	system("pause");
	return 0;
}

