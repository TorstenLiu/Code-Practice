#define _CRT_SECURE_NO_WARNINGS 1

/*���ӣ�https://www.nowcoder.com/questionTerminal/9d1559511b3849deaa71b576fa7009dc
��Դ��ţ����

�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ��������ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B���������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
���磺
A = ��aba����B = ��b����������4�ְ�B����A�İ취��
* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ��� 
* �ڵ�һ����ĸ��a��֮��: "abba" �ǻ��� 
* ����ĸ��b��֮��: "abba" �ǻ��� 
* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ��� 
�������������Ĵ�Ϊ2  */

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
bool IsPri(string& s)
{
	string temp = s;
	reverse(s.begin(), s.end());
	if (temp == s)
	{
		return true;
	}
	return false;
}
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int count = 0;
	for (int i = 0; i < s1.size()+1; i++)
	{
		string tmp = s1;
		string s3 = tmp.insert(i, s2);
		if (IsPri(s3))
		{
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}