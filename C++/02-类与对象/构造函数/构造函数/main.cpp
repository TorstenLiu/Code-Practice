#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class Date
//{
//public:
//	//ͨ��Set���з����������������ݣ������ÿ�δ�������ʱ�����ã��ͱȽ��鷳
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//Ĭ���޲ι��캯�����û�δ����ʱ�Զ�����
//	Date()
//	{
//		cout << "nhave" << endl;
//	}
//	//�вι��캯��
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "have" << endl;
//	}
//	//Ĭ��ȫȱʡ���캯������Ĭ���޲ι��캯��ì�ܣ�ֻ�ܴ���һ����һ�����ֱȽ϶�
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "hhave" << endl;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////Ĭ�Ϲ��캯��������
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int	_minute;
//	int	_second;
//};
//void Test()
//{
//	Date d;
//	Date d2(2019, 9, 16);
//}
//int main()
//{
//	//Date d;
//	//d.SetDate(2019, 9, 16);
//	//d.Print();
//
//	Test();
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	/*Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	Date(int year, int month, int day)//���캯����ʼ���б���ʼ����ֻ��һ��
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}//���캯�����ڸ�ֵ�����Զ��
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//�������³�Ա�������б��ʼ��
//class A
//{
//public:
//	A(int a)
//		: _a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj(a)
//		,_ref(ref)
//		,_n(10)
//	{}
//	void Print2()
//	{
//		cout << _aobj._a << " " << _ref << " " << _n << endl;
//	}
//private:
//	A _aobj;//�����ͳ�Ա
//	int& _ref;//����
//	const int _n;//const��Ա����
//	//�������ֶ������ڳ�ʼ���б���г�ʼ��
//};

class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};

class Date
{
public:
	Date(int day)
	{}
private:
	int _day;
	Time _t;//�Զ������͵ĳ�Ա����һ����ʹ�ó�ʼ���б���г�ʼ��
};

int main()
{
	/*Date d1(1900, 1, 1);
	d1.Print();*/

	//B b(10, 20);
	//b.Print2();

	Date d(1);
	system("pause");
	return 0;
}