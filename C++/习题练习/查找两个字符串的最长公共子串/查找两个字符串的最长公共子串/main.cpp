#define _CRT_SECURE_NO_WARNINGS 1


/*  ���ӣ�https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
��Դ��ţ����

���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���

��������:
���������ַ���

�������:
�����ظ����ֵ��ַ�
ʾ��1
����
abcdefghijklmnop
abcsafjklmnopqrstuvw
���
jklmnop    */
#include<iostream>
using namespace std;
#include<string>


string GetStr(string & s1, string & s2)
{
	string res;
	string temp;
	if (s1.size() > s2.size())//�Զ̵�Ϊ��׼
	{
		swap(s1, s2);
	}
	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = i; j < s1.size(); j++)
		{
			temp = s1.substr(i, j - i + 1);
			if ((int)s2.find(temp) < 0)
			{
				break;
			}
			else if (temp.size() > res.size())
			{
				res = temp;
			}
		}
	}
	return res;
}
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	cout << GetStr(s1, s2) << endl;
	system("pause");
	return 0;
}