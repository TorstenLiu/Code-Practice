#define _CRT_SECURE_NO_WARNINGS 1
/*���ӣ�https://www.nowcoder.com/questionTerminal/70e00e490b454006976c1fdf47f155d9
��Դ��ţ����

��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1���������������a��b�������һ���㷨�����a��b�������������ȵı�š�

��������int a,b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��Ҳ����Ϊ�������ȡ�

����������
2��3
���أ�1*/
#include<iostream>
using namespace std;
#include<string>
#include<vector>

class LCA {
public:
	int getLCA(int a, int b) {
		int A = a;
		int B = b;
		vector<int> va;
		vector<int> vb;
		
		if (a == b)
		{
			return a / 2;
		}
		else if (2 * a + 1 == b)
		{
			return a;
		}
		else if (2 * b + 1 == a)
		{
			return b;
		}
		else
		{
			for (int i = 0; A; i++)
			{
				va.resize(i+1);
				A /= 2;
				va[i] = A;
			}
			for (int j = 0; B; j++)
			{
				vb.resize(j+1);
				B /= 2;
				vb[j] = B;
			}
		}
		for (int k = 0; k < va.size(); k++)
		{
			for (int t = 0; t < vb.size(); t++)
			{
				if (va[k] == vb[t])
				{
					return va[k];
				}
			}
		}
		
	}
};
int main()
{
	LCA l;
	cout << l.getLCA(9, 7) << endl;
	system("pause");
	return 0;
}