#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//��Ԫ����������
class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year, int month, int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}

	//��һ��<<������������  ��ʱ�Ȱѷ���ֵ����void
	//void operator<<(ostream& _cout)//����������<<������������Ҳ���������Ϊ��һ������ʱthisָ�룬����ֻ��дd<<cout
	//{
	//	_cout << _year << "-" << _month << "-" << _day << endl;
	//}
	//�ڶ��Σ������ٴ�һ������ ����d��������ΪֻҪ�������������ǳ�Ա��������һ���ᴫ��һ�����ز����ڵ���λ��
	//�����ٴ�һ������d��ʹ������������Ĳ���̫��
	/*void operator<<(ostream& _cout, const Date & d)
	{

	}*/

	//���ĴΣ�����ostream�ķ���ֵ
	ostream&  operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day << endl;
		return _cout;
	}
	
	//����Σ���Ԫ������
private:
	int _year;
	int _month;
	int _day;
};
//�����Σ�����������س�ȫ�ֺ���
//���������޷����ʶ���d�ĳ�Աvoid operator<<(ostream &_cout, const Date& _d)

/*{
	cout << d._year << "-" << d._month << "-" << d._day << endl;
}*/

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

int main()
{
	Date d1(1900, 1, 1);
	Date d2(1900, 1, 2);

	//cout << d << endl;//��������ֱ�Ӵ�ӡһ������ֻ�����ز�����<<

	//d2<<d1 << cout;//������Ϊ����������޷���ֵ�����Բ���������ӡ

	cout << d1 << d2 << endl;
	system("pause");
	return 0;
}