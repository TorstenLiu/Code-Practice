#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//1.String�����ĳ�������
void Test1()
{
	string s1;//����յ�string����󣬼����ַ���
	string s2("hello");//��C-String������string�����
	string s3(10, '*');//��10��*�ַ�������string�����
	string s4(s2);//��������
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

//2.string��������������
void Test2()
{
	string s("change world");
	//2.1���ַ�����Ч�ַ����ȺͿռ��ܴ�С
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	//2.2����ַ����Ƿ�Ϊ�մ�
	if (s.empty())
	{
		cout << "NULL" << endl;
	}
	else
	{
		cout << s << endl;//string�����֧��ֱ����cin��cout������������
	}

	//2.3�����Ч�ַ���,���ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	if (s.empty())
	{
		cout << "NULL" << endl;
	}
	else
	{
		cout << s << endl;//��ʱ�ַ���Ϊ��
	}

	//2.4����Ч�ַ��ĸ����ó�n��������ַ����ص�������Ŀռ����ַ�c���
	string s1("be successful");
	cout << s1 << endl;
	cout << s1.size() << endl;//13
	cout << s1.capacity() << endl;//15

	s1.resize(10, '!');
	cout << s1 << endl;//be success
	cout << s1.size() << endl;//10
	cout << s1.capacity() << endl;//15

	s1.resize(20,'*');//����Լ��������ַ���ȱʡֵΪ��\0��
	cout << s1 << endl;//be success*********����ԭ���Ļ����ϱ�
	cout << s1.size() << endl;//20
	cout << s1.capacity() << endl;//31

	s1.resize(6);
	cout << s1 << endl;//be suc
	cout << s1.size() << endl;//6
	cout << s1.capacity() << endl;//31

	//�ܽ᣺ 1. ����ǽ�string���е���ЧԪ����С��ֻ�ı���ЧԪ�ظ���������ı�ײ�ռ��С
//       2. ����ǽ�string���е���ЧԪ�����࣬������Ҫ����

	//2.5void reserve(size_t newcapacity): ����
	string s2(20, '*');
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//31

	s2.reserve(20);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//31

	s2.reserve(40);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//47

	s2.reserve(24);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//47

	s2.reserve(10);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//47

	//�ܽ᣺ 
//newcapacity > oldcapacity(string��ɿռ��С)���ռ�����--->�����ı�(����������С >= newCapacity)
// newcapacity < oldcapacity(string��ɿռ��С)���ռ���С���ú���ֱ�ӷ��� ����newcapacity < 15
//ֻ�ı�������С������ı���ЧԪ�ظ���
}
int main()
{
	Test1();
	Test2();
	system("pause");
	return 0;
}