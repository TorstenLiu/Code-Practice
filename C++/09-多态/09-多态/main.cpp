#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#include<string>

/*1.��̬�ĸ���*/
//ȥ���ĳ����Ϊ������ͬ�Ķ���ȥ���ʱ���������ͬ����̬
//ͨ���̳�ͬһ�����࣬��������صĲ�ͬ�������࣬�������ͬ���ĳ�Ա�����ڲ�ͬ���������л��в�ͬ��ʵ�֣�Ҳ����˵��һ���ӿڡ����ַ�����

/*2.��̬������*/

//���ֲ�ͬ�������Ʊ��һ����Ʊ��������Ӧ��ͬ��Ⱥ�Ĳ�ͬӦ�Է�ʽ

//��ͨ��
class Person
{
public:
	Person(const string& name, const string& gender, int age)
		:_name(name)
		,_gender(gender)
		,_age(age)
	{}
	virtual void BuyTicket()//virtual�ļ���
	{
		cout << "ȫ��Ʊ" << endl;
	}
protected:
	string _name;
	string _gender;
	int _age;
};

//ѧ��
class Student :public Person
{
public:
	Student(const string& name, const string& gender, int age, int number)
		:Person(name,gender,age)
		,_number(number)
	{}
	virtual void BuyTicket()//virtual�ļ���,�����಻+virtual�ؼ���ʱ��Ҳ���Թ�����д�ɹ�����д�����淶
	{
		cout << "���Ʊ" << endl;
	}
private:
	int _number;//ѧ��
};

//����
class Soilder :public Person
{
public:
	Soilder(const string& name,const string& gender,int age,const string& hornor)
		:Person(name, gender, age)
		,_hornor(hornor)
	{}
	virtual void BuyTicket()//virtual�ļ���
	{
		cout << "���Ʊ" << endl;
	}
private:
	string _hornor;
};

void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}

//�������һ��������������ͬ��Ⱥʱʹ�õĲ�ͬ��������̫���ӣ����������˶�̬
/*
void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}

void TestBuyTicket(Student& p)
{
	p.BuyTicket();
}

void TestBuyTicket(Soilder& p)
{
	p.BuyTicket();
}
*/
void Test1()
{
	Person p("����", "��", 36);
	Student st("�����", "Ů", 17, 001);
	Soilder so("ս��", "��", 30, "һ�ȹ�");

	/*p.BuyTicket();
	st.BuyTicket();
	so.BuyTicket();   ֱ�ӵ�������ʵ�֣���û�����壬������һ���ӿڵĸ���*/

	TestBuyTicket(p);
	TestBuyTicket(st);
	TestBuyTicket(so);
}

#if 0
/*3.������д����������*/

//1.Э�䣺�������麯�����ػ��������(ָ��)�����������麯�����������������(ָ��)  ע�⣬ֻҪ�Ƿ��ػ��������صĻ������;Ϳ���
class A
{};
class B :public A
{};

class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2(int)//�����б�
	{
		cout << "Base::TestFunc2()" << endl;
	}

	void TestFunc3()//��virtual
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}

	virtual Base* TestFunc5()
	{
		cout << "Base::TestFunc5()" << endl;
		return this;
	}

	//���ص���A ���� ����
	virtual A& TestFunc6(A& a)
	{
		cout << "Base::TestFunc6()" << endl;
		return a;
	}
};

class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	virtual Derived* TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
		return this;
	}

	virtual B& TestFunc6(A& a)
	{
		cout << "Derived::TestFunc6()" << endl;
		return *(new B);
	}
};

void TestVirtualFunc(Base* pb)
{
	pb->TestFunc1();
	pb->TestFunc2(10);//�����б���ͬ
	pb->TestFunc3();//��virtual
	pb->TestFunc4();
	pb->TestFunc5();

	A a;
	pb->TestFunc6(a);
}

void Test2()
{
	Base b;
	Derived d;

	TestVirtualFunc(&b);
	TestVirtualFunc(&d);
}

#endif


//4..����������д:����������������Ϊ�麯������ʱ��������������ֻҪ���壬�����Ƿ��virtual�ؼ��֣�
//����������������������д
class Base
{
public:
	Base(int b)
		:_b(b)
	{
		cout << "Base::Base()" << endl;
	}
	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}
protected:
	int _b;
};
class Derived : public Base
{
public:
	Derived(int b)
		: Base(b)
		, _p(new int[10])
	{
		cout << "Derived::Derived(int)" << endl;
	}

	~Derived()
	{
		delete[] _p;
		cout << "Derived::~Derived()" << endl;
	}

protected:
	int* _p;
};
//ֻ��������Derived������������д��Base�����������������delete�����������������
//���ܹ��ɶ�̬�����ܱ�֤pb1��pb2ָ��Ķ�����ȷ�ĵ�������������
void TestDestroy()
{
	Base* pb1 = new Base(10);
	Base* pb2 = new Derived(10);

	delete pb1;
	delete pb2;

}

/*5. C++11 override �� final*/
//1. final�������麯������ʾ���麯�������ٱ��̳�
class Base1
{
public:
	virtual void TestBase1()
	{
		cout << "TestBase1()" << endl;
	}

	int _b;
};
class Derived2 :public Base1
{
public:
	virtual void TestBase1()
	{
		cout << "Base1::TestBase1()" << endl;
	}

};

int main()
{
	Test1();
	//Test2();
	TestDestroy();

	system("pause");
	return 0;
}