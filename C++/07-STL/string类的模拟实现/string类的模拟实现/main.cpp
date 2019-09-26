#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class String
{
	friend ostream& operator<<(ostream& _cout, const String& s);
public:
	//���캯��
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		//����ռ�
		_str = new char[strlen(str) + 1];
		//���str���ַ�
		strcpy(_str, str);
	}
	//��������
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
ostream& operator<<(ostream& _cout, const String& s)
{
	_cout << s._str;
	return _cout;
}

void Test()
{
	String s1("HongKong belongs to China!");
	cout << s1 << endl;
}
int main()
{
	Test();

	system("pause");
	return 0;
}