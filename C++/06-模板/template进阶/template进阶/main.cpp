#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string.h>

//1.������ģ�����
namespace Template
{
	template<class T,size_t N>
	class array
	{
	public:
		array()
		{
			for (size_t i = 0; i < N; ++i)
				_array[i] = 0;
			_size = 0;
		}
		T& operator[](size_t index)
		{
			return _array[index];
		}
		const T& operator[](size_t index)const
		{
			return _array[index];
		}
		void push_back(const T& data)
		{
			/*++_size;
			_array[_size] = data;*/
			_array[_size++] = data;
		}
		size_t size()const
		{
			return _size;
		}
		bool empty()const
		{
			return 0 == _size;
		}

	private:
		T _array[N];
		size_t _size;
	};
}

void Test1()
{
	int a = 10;
	int b = 20;

	//Template::array<int, a+b> arr; ����������ģ����������ڱ�����ȷ������������Ϊ����ֻ��Ϊ������

	Template::array<int, 30> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);

	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//2.ģ����ػ�   
//2.1 ����ģ���ػ�
//����Ҫ��һ�������ĺ���ģ��
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}
template<>//template�����<>
bool IsEqual<char*>(char*& left, char*& right)//������������Ҫ�����ػ������ͣ��Ҳ����б���ģ�������ͬ
{
	if (strcmp(left, right) > 0)
	{
		return true;
	}
	return false;
}

class Date
{
public:
	Date(int year,int month,int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day << endl;
		return _cout;
	}
	bool operator>(const Date& d)
	{
		return _day > d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test2()
{
	//������
	int a = 10;
	int b = 20;
	cout <<"����"<< IsEqual(a, b) << endl;
	//cout << IsEqual(10,20) << endl; ����

	//���ַ���
	const char* p1 = "hello";
	const char* p2 = "worldddd";
	cout <<"�ַ���"<< IsEqual(p1, p2) << endl;

	//�ȶ���
	/*Date d1(2019, 10, 27);
	Date d2(2019, 10, 28);
	cout <<"����"<< IsEqual(d1, d2) << endl;*/  //����
}

//2.2 ��ģ���ػ�
//2.2.1.ȫ�ػ�:�ǽ�ģ�������������еĲ�����ȷ������
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Date<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Date<int,char>" << endl;
	}
private:
	int _d1;
	char _d2;
};
//2.2.2.ƫ�ػ� :�����ػ�--->��ģ������б��в��ֲ������ͻ�
template <class T1>
class Data<T1,double>
{
public:
	Data()
	{
		cout << "Data<T1,int>" << endl;
	}
private:
	T1 _d1;
	double _d2;
};
//2.2.2 ƫ�ػ�����������һ��������
//  1.��������ƫ�ػ�Ϊָ������
template <class T1, class T2>
class Data<T1*,T2*>
{
public:
	Data()
	{
		cout << "Data<T1*,T2*>" << endl;
	}
private:
	T1* _d1;
	T2* _d2;
};
// 2.��������ƫ�ػ�Ϊ��������
template<class T1, class T2>
class Data<T1&,T2&>
{
public:
	Data(const T1& d1,const T2& d2)
		:_d1(d1)
		,_d2(d2)
	{
		cout << "Data<T1&,T2&>" << endl;

	}
private:
	const T1& _d1;
	const T2& _d2;
};
void Test3()
{
	//ȫ�ػ�
	Data<int, int>d1;
	Data<int, char>d2;

	//ƫ�ػ�
	Data<double, double>d3;

	Data<int*, int*>d4;
	Data<int&, int&>d5(1,2);
}

int main()
{
	Test1();
	Test2();
	Test3();

	system("pause");
	return 0;
}