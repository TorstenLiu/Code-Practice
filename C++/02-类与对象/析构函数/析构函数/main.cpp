#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

class Seqlist
{
public:
	//���캯��
	Seqlist(int capacity = 10)
	{
		_pdata = (int *)malloc(capacity * sizeof(int));
		assert(_pdata);
		_size = 0;
		_capacity = capacity;
	}
	//��������
	~Seqlist()
	{
		cout << "~Seqlist" << endl;
		if (_pdata)
		{
			free(_pdata);
			_pdata = NULL;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	int * _pdata;
	size_t _size;
	size_t _capacity;
};


class String
{
public:
	String(const char * str = "jack")
	{
		_str = (char *)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << " ~String()" << endl;
		free(_str);
	}
private:
	char * _str;
};
class Person
{
private:
	String _name;
	int _age;
};
int main()
{
	Seqlist s;//�ڽ���cmd����ʱ�Ż������������

	Person p;//������p�е�_name��_age
	system("pause");
	return 0;
}

//�����������壺
//�빹�캯�������෴���ڶ�������ʱ����������������ɶ������Դ����������������ɶԶ�������٣��������ɱ�������ɵġ�

//��������������
//1.������ǰ��~
//2.�޲������޷���ֵ
//3.һ����ֻ��һ��������������û����ʾ������ϵͳ�Զ�������������
//4.ֻ���ڶ����������ڽ���ʱ������ϵͳ�Զ�������������
//5.����������������