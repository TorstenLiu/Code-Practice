#define _CRT_SECURE_NO_WARNINGS 1

/*��Ŀ����

�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ������
��Ҫ���λʵ���ַ���ͨ������㷨��
Ҫ��
ʵ������2��ͨ�����
* ��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ��
����ƥ��1���ַ�

���룺

ͨ������ʽ��
һ���ַ�����
�����

����ƥ��Ľ������ȷ���true���������false
��������:

������һ������ͨ������ַ�����������һ����Ҫƥ����ַ���
�������:

����ƥ��Ľ������ȷ���true���������false
ʾ��1

����
te?t*.*
txt12.xls
���
false    */
#include<iostream>
using namespace std;
#include<string>

bool fun(const char* s1, const char* s2)
{
	if (*s1 == *s2&&*s1 == '\0')
	{
		return true;
	}
	else if (*s1 == '\0' || *s2 == '\0')
	{
		return false;
	}

	//?  ���ƥ��һ���ַ�
	if (*s1 == '?')
	{
		return fun(s1 + 1, s2 + 1);
	}
	//*��ƥ��0��1�����߶��
	else if (*s1 == '*')
	{
		return fun(s1, s2 + 1) || fun(s1 + 1, s2 + 1) || fun(s1 + 1, s2 + 1);
	}
	//ƥ�����ˣ�ֱ��ƥ����һ��
	else if (*s1 == *s2)
	{
		return fun(s1 + 1, s2 + 1);
	}
	return false;
}
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	cout << fun(s1.c_str(), s2.c_str()) << endl;
	system("pause");
	return 0;
}