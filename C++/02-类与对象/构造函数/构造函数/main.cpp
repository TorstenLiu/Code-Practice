#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Date
{
public:
	//ͨ��Set���з����������������ݣ������ÿ�δ�������ʱ�����ã��ͱȽ��鷳
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//Ĭ���޲ι��캯�����û�δ����ʱ�Զ�����
	Date()
	{
		cout << "nhave" << endl;
	}
	//�вι��캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "have" << endl;
	}
	//Ĭ��ȫȱʡ���캯������Ĭ���޲ι��캯��ì�ܣ�ֻ�ܴ���һ����һ�����ֱȽ϶�
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "hhave" << endl;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//Ĭ�Ϲ��캯��������
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int	_minute;
	int	_second;
};
void Test()
{
	Date d;
	Date d2(2019, 9, 16);
}
int main()
{
	//Date d;
	//d.SetDate(2019, 9, 16);
	//d.Print();

	Test();
	system("pause");
	return 0;
}