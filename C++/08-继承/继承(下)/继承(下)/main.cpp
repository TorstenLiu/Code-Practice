#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;


// ���һ���಻�ܱ��̳�
// C++98

//���������캯��˽�л������������������Ĺ��캯�������޷��̳�
class Base1
{
	//Ҫ�����ⶨ����󣬵�����Ϊ���๹�캯������Ȩ����private�����Զ���һ���ڲ���Ա�����ʻ���˽�еĹ��캯��
public:
	//Ҫ�����ⶨ�����ʹ�ô˷���ǰ����Ҫ��һ��Base1���͵Ķ��������ڸ÷���ǰ��һ��static
	static Base1 GetObject(int b)
	{
		return Base1(b);
	}
private:
	Base1(int b)
		:_b(b)
	{}
//protected:
public:
	int _b;
};
void Test1()
{
	//Ҫ�����ⶨ�����
	Base1 b(Base1::GetObject(10));
	cout << b._b << endl;
}
//c++11
// final�������һ���ࣺ��ʾ���಻�ܱ��̳�
class Base final
{
public:
	Base(int b)
		: _b(b)
	{}

protected:
	int _b;
};

/*5.�̳�����Ԫ*/
//��Ԫ��ϵ���ܼ̳У�Ҳ����˵������Ԫ���ܷ�������˽�кͱ�����Ա
class Base2
{
	friend void Test2();
public:
	Base2(int b)
		:_b(b)
	{}
	int GetB()
	{
		return _b;
	}
protected:
	int _b;
};
class Derived2 : public Base2
{
public:
	Derived2(int b, int d)
		: Base2(b)
		, _d(d)
	{}

protected:
	int _d;
};

//void Test2()//��������Ԫ�������ܷ�������˽�кͱ�����Ա
//{
//	Base2 b(10);
//	cout << b.GetB() << endl;
//	cout << b._b << endl;
//
//	Derived2 d(10, 20);
//	cout << d._d << endl;//����  ���ܷ���
//}



/*6.�̳��뾲̬��Ա*/
// ͳ��һ���ഴ���˶��ٸ�����
class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // �о���Ŀ
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;
}

//	���ۣ�
//	 1. �����о�̬��Ա�������Ա�����̳�
//	 2. �������̳���ϵ�У���̬��Ա����ֻ��һ��

/*8.���ӵ����μ̳м���������̳�*/

//���ؼ̳�
#if 0
class B1
{
public:
	int _b1;
};

class B2
{
public:
	int _b2;
};

// ע�⣺ÿ������ǰ��������̳�Ȩ�ޣ��������Ĭ�ϵļ̳�Ȩ��
class D : public B2, public B1
{
public:
	int _d;
};


void Test3()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
}
#endif


class B
{
public:
	int _b;
};

class C1 : public B
{
public:
	int _c1;
};

class C2 : public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

void Test4()
{
	cout << sizeof(D) << endl;//20

	D d;
	//d._b = 1;  // ���μ̳�ȱ�ݣ�����ڶ���������

    //�����ʽһ��ͨ�����������
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;
}

//�����ʽ���� ��������̳�
//class B
//{
//public:
//	int _b;
//};
//
//class C1 : virtual public B
//{
//public:
//	int _c1;
//};
//
//class C2 : virtual public B
//{
//public:
//	int _c2;
//};
//
//class D : public C1, public C2
//{
//public:
//	int _d;
//};
//
//void Test5()
//{
//	cout << sizeof(D) << endl;
//	D d;
//	
//}

int main()
{
	Test1();
	//Test2();
	TestPerson();
	//Test3();
	Test4();
	//Test5();

	system("pause");
	return 0;
}