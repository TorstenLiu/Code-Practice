#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string.h>
#include<string>

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
// 2.2.2. 1.��������ƫ�ػ�Ϊָ������
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
// 2.2.2.2.��������ƫ�ػ�Ϊ��������   Ϊʲô����Ĺ��캯��Ҫ����д��
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

//3.��ģ���ػ�Ӧ��֮������ȡ
//���⣺���ʵ��һ��ͨ�õĿ���������Ҫ��Ч�ʾ����ܸ�
//����һ��ʹ��memcpy
template<class T>
void Copy1(T* des, const T* sour, size_t size)
{
	memcpy(des, sour, sizeof(T)*size);
}
void Test4()
{
	string s1[3] = { "hello","world","!" };//������һ��string���͵�ָ�룬���������string���ͱ�����һ��Ϊhello��һ��Ϊworld��һ��Ϊ��
	string s2[3];
	Copy1(s2, s1, 3);

	/*cout << *s1 << endl;
	cout << *s2 << endl;*/
	//�����������Զ������Ͷ���Ϳ��ܻ������Ϊ�Զ������Ͷ����п��ܻ��漰�����(����string)��
	//��memcpy����ǳ����������������漰����Դ������ֻ���ø�ֵ��
}
//��������ʹ�ø�ֵ��ʽ����
template<class T>
void Copy2(T* des, const T* sour, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		des[i] = sour[i];
	}
}
void Test5()
{
	string s1[3] = { "change","world","!" };
	string s2[3];
	Copy2(s2, s1, 3);
	cout << s1 << endl;
	cout << s2 << endl;//ʹ�����������ָ���ַ�Ż᲻һ��
	cout << *s1 << endl;
	cout << *s2 << endl;//��ӡ*s1,����ӡ����Ԫ�صĵ�ַ

}

/*ѭ����ֵ�ķ�ʽ��Ȼ���ԣ����Ǵ����Ч�ʱȽϵͣ���C/C++�����������ƾ���Ч�ʸߡ����ܷ�����
��ʽ�����ƽ�������أ������������;���memcpy�������������Զ������;���ѭ����ֵ��ʽ�����أ�*/


//������ ����bool���������Զ�������������
template<class T>
void Copy3(T* des, const T* sour, size_t size, bool IsPODType)
{
	if (IsPODType)// plain old data��������
	{
		memcpy(des, sour, sizeof(T)*size);
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			des[i] = sour[i];
		}
	}
}
void Test6()
{
	/*const char* arr1 = "I like";
	char* arr2 = nullptr;*/  //���Ϊʲô�����ԣ�
	const char arr1[2] = { 'a','b' };
	char arr2[2];
	Copy3(arr2, arr1, 1, true);
	string s1[3] = { "practice","code","everday" };
	string s2[3];
	Copy3(s1, s2, 3, false);
	
}
/*ͨ��������һ���������Ϳɽ����ֿ������������ֽ����������ȱ���ǣ��û���Ҫ����������Ԫ�ص�����ȥ
���ݵ������������ǳ���Ŀ����Ծ����ӡ����ܷ��ú����Զ�ȥʶ���������������������ͻ����Զ�������
�أ�*/

//�����ģ�ʹ�ú��������������Զ�������
/*��Ϊ�������͵ĸ�����ȷ���ģ����Խ������������ͼ�����һ������ܹ������������������ȷ��������
���������ͼ����в������Ƿ���ڼ���ȷ�������������Ƿ�Ϊ��������*/

/*ͨ��typeid��ȷ�������������ʵ�����ͣ�Ȼ�������������ͼ�����ö�����Ƿ���ֹ����ȿ�ȷ��������Ԫ
�ص�����Ϊ�������ͻ����Զ������͡���ȱ���ǣ�ö����Ҫ���������ͱ���һ�飬ÿ�αȽ϶����ַ����ı�
�ϣ�Ч�ʱȽϵ͡�*/
bool IsPODType(const char* type)
{
	const char* arrtype[] = { "int","char","short","long","long long","float","double","long double" };
	int length = sizeof(arrtype) / sizeof(arrtype[0]);
	for (size_t i = 0; i < length; i++)
	{
		if (strcmp(type, arrtype[i]) == 0)
		{
			return true;
		}
	}
	return false;
}
template<class T>
void Copy4(T* des, const T* sour, size_t size)
{
	if (IsPODType(typeid(T).name()))
	{
		memcpy(des, sour, sizeof(T)*size);
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			des[i] = sour[i];
		}
	}
}
void Test7()
{
	/*const char arr1[2] = { 'a','b' };
	char arr2[2];
	Copy4(arr2, arr1, 2);*/
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int array2[10];
	Copy4(array2, array1, 10);
	cout << *array1 << endl;
	cout << *array2 << endl;
	char arr1[2] = { 'a','b' };
	char arr2[2];
	Copy4(arr2, arr1, 2);
	cout << arr1 << endl;
	cout << arr2 << endl;
	cout << *arr1 << endl;
	cout << *arr2 << endl;

	string s1[3] = { "practice","code","everday" };
	string s2[3];
	Copy4(s2, s1, 3);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << *s1 << endl;
	cout << *s2 << endl;
}

//����5�����ŷ�����������ȡ

//������ֱ���������������Զ������͡�

//����
struct Truetype
{
	static bool Get()
	{
		return true;
	}
};
//�Զ���
struct Falsetype
{
	static bool Get()
	{
		return false;
	}
};
//ģ����     ���԰�����������ʵ��������ģ��
template<class T>
struct typetrails
{
	typedef Falsetype IsPODType;
};
//����ģ�����ʵ����
template<>
struct typetrails<char>
{
	typedef Truetype IsPODType;
};
template<>
struct typetrails<int>
{
	typedef Truetype IsPODType;
};
template<>
struct typetrails<short>
{
	typedef Truetype IsPODType;
};
template<>
struct typetrails<long>
{
	typedef Truetype IsPODType;
};
//ͨ����TypeTraits��ģ����д��д��ʽ���е�Copy����ģ�壬��ȷ�������������ʵ�����͡�

/*
TΪint��TypeTraits<int>�Ѿ��ػ�������������ʱ�ͻ�ʹ���Ѿ��ػ�����TypeTraits<int>, �����е�
IsPODType�պ�Ϊ��TrueType����TrueType��Get��������true����������ʹ��memcpy��ʽ����
TΪstring��TypeTraits<string>û���ػ�������������ʱʹ��TypeTraits��ģ��, ����ģ���е�IsPODType
�պ�Ϊ��FalseType����FalseType��Get��������true���Զ�������ʹ�ø�ֵ��ʽ����
*/
template<class T>
void Copy5(T* des, const T* sour, size_t size)
{
	if (typetrails<T>::IsPODType::Get())
		//����__IsPODType.Get() ʱ�����������TypeTraits<class T> T ��ʵ�����͵��� 	
//__FalseType	 �� Truetype �� Get()����  �õ���ͬ boolֵ			
	{
		memcpy(des, sour, sizeof(T)*size);
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			des[i] = sour[i];
		}
	}
}
void Test8()
{
	int a1[] = { 1,2,3,4,5,6,7,8,9,0 };
	int a2[10];
	Copy5(a2, a1, 10);
	cout << *a1 << endl;
	cout << *a2 << endl;
	string s1[] = { "1111", "2222", "3333", "4444" };
	string s2[4];
	Copy5(s2, s1, 4);
	cout << *s1 << endl;
	cout << *s2 << endl;
}

//4.ģ��������
// ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д�����ļ�
struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // �˿�
};

//#include <fstream>
//
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* configfile = "bitserver.config")
//		:_configfile(configfile)
//	{}
//
//	void WriteBin(const ServerInfo& info)
//	{
//		// ����ע��ʹ�ö����Ʒ�ʽ��д
//		ofstream ofs(_configfile, ifstream::out | ifstream::binary);
//		ofs.write((const char*)&info, sizeof(ServerInfo));
//		ofs.close();
//	}
//
//	void ReadBin(ServerInfo& info)
//	{
//		// ����ע��ʹ�ö����Ʒ�ʽ�򿪶�
//		ifstream ifs(_configfile, ifstream::in | ifstream::binary);
//		ifs.read((char*)&info, sizeof(ServerInfo));
//		ifs.close();
//	}
//
//	void WriteText(const ServerInfo& info)
//	{
//		// ����ᷢ��IO��д���α�C�������׾ͼ򵥶��ˣ�
//		// C ���Ե��Ȱ�����itoa��д
//		ofstream ofs(_configfile);
//		ofs << info._ip << endl;
//		ofs << info._port << endl;
//		ofs.close();
//	}
//
//	void ReadText(ServerInfo& info)
//	{
//		// ����ᷢ��IO�������α�C�������׾ͼ򵥶��ˣ�
//		// C ���Ե��ȶ��ַ�������atoi
//		ifstream ifs(_configfile);
//		ifs >> info._ip;
//		ifs >> info._port;
//		ifs.close();
//	}
//
//private:
//	string _configfile; // �����ļ�
//};

void Test9()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// �����ƶ�д
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	// �ı���д
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}
int main()
{
	Test1();
	Test2();
	Test3();
	//Test4();
	Test5();
	Test6();
	Test7();
	Test8();

	system("pause");
	return 0;
}