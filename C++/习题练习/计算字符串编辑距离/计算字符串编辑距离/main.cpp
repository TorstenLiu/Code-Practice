#define _CRT_SECURE_NO_WARNINGS 1

/*���ӣ�https://www.nowcoder.com/questionTerminal/3959837097c7413a961a135d7104c314
��Դ��ţ����
Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭����������
��ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ���
�༭������㷨�������ɶ����ѧ��Levenshtein����ģ����ֽ�Levenshtein Distance��
Ex��

�ַ���A:abcdefg

�ַ���B: abcdef

ͨ�����ӻ���ɾ���ַ���g���ķ�ʽ�ﵽĿ�ġ������ַ�������Ҫһ�β������������������Ҫ�Ĵ�������Ϊ�����ַ����ľ��롣

Ҫ��

�������������ַ�����д��һ���㷨�������ǵı༭���롣

��������:
���������ַ���
������� :
�õ������� */
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//int main()
//{
//	string s1;
//	string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	int count = 0;
//	if (strcmp(s1.c_str(), s2.c_str()) == 0)
//	{
//		return 0;
//	}
//	if (s1.size() == s2.size())//ֻ���滻
//	{
//		int i = 0;
//		while (i < s1.size())
//		{
//			if (s1[i] != s2[i])
//			{
//				s1[i] = s2[i];
//				count++;
//			}
//			i++;
//		}
//	}
//	else//�滻���߲�ɾ
//	{
//		int len1 = s1.size();
//		int len2 = s2.size();
//		//�滻
//		if (len1 > len2)//��С��Ϊ׼
//		{
//			swap(s1, s2);
//		}
//		for (int i = 0; i < s1.size(); i++)
//		{
//			if (s1[i] != s2[i])
//			{
//				s2[i] = s1[i];
//				count++;
//			}
//		}
//		count += abs(len1 - len2);//�ټ��϶���Ĳ���
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}

int GetDis(string s1, string s2) 
{
	int len1 = (int)s1.size(), len2 = (int)s2.size();
	vector<vector<int>>dp(len1 + 1, vector<int>(len2 + 1, 0));
	dp[0][0] = 0;
	for (int i = 1; i <= len2; ++i) 
		dp[0][i] = i;
	for (int i = 1; i <= len1; ++i) 
		dp[i][0] = i;
	for (int i = 1; i <= len1; ++i) 
	{
		for (int j = 1; j <= len2; ++j) 
		{
			int first = dp[i - 1][j] + 1, second = dp[i][j - 1] + 1, third = dp[i - 1][j - 1];
			if (s1[i - 1] != s2[j - 1]) third += 1;
			dp[i][j] = min(min(first, second), third);
		}
	}
	return dp[len1][len2];
}
int main() 
{
	string a, b;
	while (cin >> a >> b)
		cout << GetDis(a, b) << endl;
	return 0;
}