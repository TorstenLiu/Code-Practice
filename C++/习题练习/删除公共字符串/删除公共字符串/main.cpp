#define _CRT_SECURE_NO_WARNINGS 1

/*���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou����
��ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��*/

#include<iostream>
using namespace std;
#include<string>

int main()
{
	string s1;//ԭ�ַ���
	string s2;//ɾ�����ַ���
	getline(cin, s1);
	getline(cin, s2);
	int count[1000] = { 0 };
	for (int i = 0; i < s2.size(); i++)
	{
		count[s2[i]]++;
	}
	string result;
	for (int j = 0; j < s1.size(); j++)
	{
		if (count[s1[j]] == 0)
		{
			result += s1[j];
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}