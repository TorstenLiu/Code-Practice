#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;
#include<algorithm>

/*��Ŀ����
�����һ���㷨������������������ļӷ���

�ӿ�˵����

 /*
 �����һ���㷨������������������ļӷ���
 ���������
 String addend������
 String augend��������
 ����ֵ���ӷ����
��������:
���������ַ�������

������� :
�����Ӻ�Ľ����string��

ʾ��1
����

99999999999999999999999999999999999999999999999999
1
���

100000000000000000000000000000000000000000000000000*/

int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	int len1 = s1.size();
	int len2 = s2.size();
	string res;
	int s = 0;
	int c = 0;
	int i = len1 - 1;
	int j = len2 - 1;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
		{
			s += s1[i] - '0';
		}
		if (j >= 0)
		{
			s += s2[j] - '0';
		}
		s += c;//��ǰ������λ���õ���ֵ
		res += s % 10+'0';
		c = s / 10;//��λ
		s = 0;
		i--;
		j--;
	}
	if (c ==1)
	{
		res += '1';
	}
	reverse(res.begin(),res.end());
	cout << res << endl;

	system("pause");
	return 0;
}