#define _CRT_SECURE_NO_WARNINGS 1

/*���ӣ�https://www.nowcoder.com/questionTerminal/668603dc307e4ef4bb07bcd0615ea677?orderByHotValue=0&done=0&pos=40&onlyReference=false
��Դ��ţ����

�������������������
xcopy /s c:\ d:\��

�����������£� 
����1��������xcopy 
����2���ַ���/s
����3���ַ���c:\
����4: �ַ���d:\

���дһ��������������ʵ�ֽ������и�����������������

�������� 
1.�����ָ���Ϊ�ո� 
2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy /s ��C:\program files�� ��d:\��ʱ��������Ȼ��4������3������Ӧ�����ַ���C:\program files��������C:\program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
3.���������� 
4.������������֤��������ֲ�����Ҫ������� 

��������:
����һ���ַ����������пո�

�������:
��������������ֽ��Ĳ�����ÿ����������ռһ��

ʾ��1
����
xcopy /s c:\\ d:\\
���
4
xcopy
/s
c:\\
d:\\*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
	vector<string> mystr;
	string s;

	while (cin >> s) 
	{
		mystr.push_back(s);
	}
	string each;
	string eve;
	cout << mystr.size() << endl;
	for (int i = 0; i < mystr.size(); i++) 
	{
		each = mystr[i];
		int len = each.size();
		if (each[0] == '\"')
		{
			eve = each.substr(1, len - 2);
		}
		else if (each[len - 1] == '\"') 
		{
			eve = eve + ' ' + each.substr(0, len - 2);
			cout << eve << endl;
			eve.clear();
		}
		else
			cout << each << endl;
	}
	return 0;

}