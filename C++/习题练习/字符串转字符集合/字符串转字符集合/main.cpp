#define _CRT_SECURE_NO_WARNINGS 1

//����һ���ַ�����������ַ����������ַ�����

#include<iostream>
using  namespace std;

#include<vector>
#include<string>

bool check(char c, string str)
{
	bool exit = false;
	int len = str.size();
	for (int i = 0; i <= len - 1; i++)
	{
		if (c == str[i])
		{
			exit = true;
			return exit;
		}
	}
	return exit;
}

int main()
{
	string s;
	while (cin >> s)
	{
		string su;
		int len = s.length();
		bool exit;
		for (int i = 0; i <= len - 1; i++)
		{
			exit = check(s[i], su);
			if (exit == false)
			{
				su += s[i];
			}
		}
		cout << su << endl;
	}
	return 0;
}