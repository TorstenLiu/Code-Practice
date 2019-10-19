#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

/* һ.�����ǳ����*/

//1.ǳ������string��
class String1
{
	friend ostream& operator<<(ostream& _cout, const String1& s);
public:
	//���캯��
	String1(const char* str = "")
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

	//�������Զ����ɵĿ������캯�������������
	String1(const String1& s)
		: _str(s._str)
	{}
	String1& operator=(const String1& s)
	{
		_str = s._str;
		return *this;
	}


	//��������
	~String1()
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
ostream& operator<<(ostream& _cout, const String1& s)
{
	_cout << s._str;
	return _cout;
}

void Test1()
{
	String1 s1("HongKong belongs to China!");
	//String1 s2(s1);//����������Ĭ�Ͽ������캯����ǳ������������������
	cout << s1 << endl;
	//cout << s2 << endl;//����3

}

//2.���--��ͳ��string��
class String2
{
	friend ostream& operator<<(ostream& _cout, const String2& s);
public:
	//���캯��
	String2(const char* s = "")
	{
		if (s == nullptr)
		{
			s = "";
		}
		_str = new char[strlen(s) + 1];
		strcpy(_str, s);
	}

	//�Զ��忽������
	String2(const String2& s)
		:_str(new char[strlen(s._str) + 1])// ����ռ�
	{
		strcpy(_str, s._str);// ���str�е��ַ�
	}

	//�Զ������������  s1=s2
	String2& operator=(const String2& s)
	{
		if (this != &s)//����дs
		{
			char *pstr = new char[strlen(s._str) + 1];
			strcpy(pstr, s._str);
			delete[] _str;
			_str = pstr;
		}
		return *this;
	}

	~String2()
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
ostream& operator<<(ostream& _cout, const String2& s)
{
	_cout << s._str;
	return _cout;
}
void Test2()
{
	String2 s1("I love my country!");
	String2 s2(s1);
	cout << s1 << endl;
	cout << s2 << endl;
}

//3.���--�ִ���string��
class String3
{
	friend ostream& operator<<(ostream& _cout, String3 s);
public:
	String3(const char* s = "")
	{
		if (nullptr == s)
		{
			s = "";
		}
		_str = new char[strlen(s) + 1];
		strcpy(_str, s);
	}

	//��������
	String3(const String3& s)
		:_str(nullptr)//Ϊ�˲���strtemp�����ֵ�����޷��ͷţ���һ����ֵ
	{
		String3 strtemp(s._str);//���ù��캯�������������ʱ����
		swap(_str, strtemp._str);
	}

	//��ֵ���������--���ַ�ʽ��һ�������ã�һ��������

	//String3& operator=(const String3& s)
	//{
	//	if (this != &s)
	//	{
	//		String3 stemp(s);//��������
	//		swap(_str, stemp._str);
	//	}
	//	return *this;
	//}
	String3& operator=(String3 s)//s�Ƕ����һ����ʱ����
	{
		swap(_str, s._str);//���_strָ����� ����������ݿռ䣬��ԭ������Ļ�����ԭ�������ָ��ָ��
		return *this;
	}

	~String3()
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
ostream& operator<<(ostream& _cout, String3 s)
{
	_cout << s._str;
	return _cout;
}
void Test3()
{
	String3 s1("I am an Chinese!");
	String3 s2(s1);
	String3 s3;
	s3 = s2;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}

//4.дʱ����



/*string���ģ��ʵ��*/

int main()
{
	Test1();
	Test2();
	Test3();

	system("pause");
	return 0;
}