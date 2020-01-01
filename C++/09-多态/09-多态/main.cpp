#define _CRT_SECURE_NO_WARNINGS 1


//https://blog.csdn.net/qq_42913794/article/details/103040839  ---��̬�ܽ�(��)
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


/*3.������д����������*/

//1.Э�䣺�������麯�����ػ��������(ָ��)�����������麯�����������������(ָ��)  
//ע�⣬ֻҪ�Ƿ��ػ��������صĻ������;Ϳ���
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




//4..����������д:����������������Ϊ�麯������ʱ��������������ֻҪ���壬�����Ƿ��virtual�ؼ��֣�
//����������������������д
class Base1
{
public:
	Base1(int b)
		:_b(b)
	{
		cout << "Base1::Base1()" << endl;
	}
	virtual ~Base1()
	{
		cout << "Base1::~Base1()" << endl;
	}
protected:
	int _b;
};
class Derived1 : public Base1
{
public:
	Derived1(int b)
		: Base1(b)
		, _p(new int[10])
	{
		cout << "Derived1::Derived1(int)" << endl;
	}

	~Derived1()
	{
		delete[] _p;
		cout << "Derived1::~Derived1()" << endl;
	}

protected:
	int* _p;
};
//ֻ��������Derived������������д��Base�����������������delete�����������������
//���ܹ��ɶ�̬�����ܱ�֤pb1��pb2ָ��Ķ�����ȷ�ĵ�������������
void TestDestroy()
{
	Base1* pb1 = new Base1(10);
	Base1* pb2 = new Derived1(10);

	delete pb1;
	delete pb2;

}

/*5. C++11 override �� final*/
//1. final�������麯������ʾ���麯�������ٱ��̳�
//ע�⣬C++98�ﲻ��ʹ��
#if 0
class Base2
{
public:
	virtual void TestBase1()final
	{
		cout << "Base2::TestBase1()" << endl;
	}

	int _b;
};
class Derived2 :public Base2
{
public:
	virtual void TestBase1()
	{
		cout << "Derived2::TestBase1()" << endl;
	}

};
#endif

//2. override: �����������麯��
//�����麯���Ƿ���д�˻���ĳ���麯�������û����д���뱨��
class Base2
{
public:
	virtual void TestBase1()
	{
		cout << "Base2::TestBase1()" << endl;
	}

	int _b;
};
class Derived2 :public Base2
{
public:
	virtual void TestBase1()override
	{}
};
void TestOverVirtualFun(Base2* pb)
{
	pb->TestBase1();
}
void Test3()
{
	Base2 b;
	b.TestBase1();
	Derived2 d;
	d.TestBase1();
	TestOverVirtualFun(&b);
	TestOverVirtualFun(&d);
}

/*6.������*/
//���麯���ĺ���д�� = 0 �����������Ϊ���麯����
//�������麯��������������ࣨҲ�нӿ��ࣩ�������಻�ܶ�����󣬵����Զ���ָ��(����)
//������̳к�Ҳ����ʵ����������ֻ����д���麯�������������ʵ����������
//���麯���淶�������������д�����ⴿ�麯�������ֽӿڼ̳�
class Place
{
	virtual void Describe() = 0;
};
`
class BeiJing :public Place
{
public:
	void Describe()
	{
		cout << "TianAnMen" << endl;
	}
};

class ShangHai :public Place
{
public:
	void Describe()
	{
		cout << "DongFangMIingZhu" << endl;
	}
};

void Test4()
{
	BeiJing bei;
	bei.Describe();
	BeiJing* pbei = new BeiJing;
	pbei->Describe();

	/*Place* ppbei = new BeiJing;
	ppbei->Describe();  ����*/

	ShangHai sh;
	sh.Describe();
	ShangHai* psh = new ShangHai;
	psh->Describe();

	/*Place* ppsh = new ShangHai;
	ppsh->Describe(); ����*/
}

/*7.��̬��ԭ��*/

/*7.1������������麯����Ĺ�������*/

//1.�������麯������Ĵ�С�Ƕ���
class Base3
{
public:
	virtual void Test1()
	{
		cout << "Base3::Test1()" << endl;
	}
	virtual void Test2()
	{
		cout << "Base3::Test2()" << endl;
	}
	int _b;
};
void Test5()
{
	cout << sizeof(Base3) << endl;//8
}
//���ۣ�//���һ�����а������麯�������С����ĸ��ֽ�
//�����û����ʽ���幹�캯���������������������һ��Ĭ�ϵĹ��캯�������ã������ָ����ڶ����ǰ�ĸ��ֽ���
//�������ʽ�����˹��캯��������������û��ṩ�Ĺ��캯�����и�д�������ָ�����ǰ4���ֽ���


class Base4
{
public:
	virtual void Test1()
	{
		cout << "Base4::Test1()" << endl;
	}
	virtual void Test2()
	{
		cout << "Base4::Test2()" << endl;
	}
	virtual void Test3()
	{
		cout << "Base4::Test3()" << endl;
	}
	int _b;
};
//���ۣ�������������̣����麯�������������е����������������ӵ������
//֤�������Ӳ鿴�麯�����ok

class Derived4 :public Base4
{
public:
	virtual void Test5()
	{
		cout << "Derived::Test5()" << endl;
	}

	virtual void Test1()
	{
		cout << "Derived::Test1()" << endl;
	}

	virtual void Test3()
	{
		cout << "Derived::Test3()" << endl;
	}

	virtual void Test4()
	{
		cout << "Derived::Test4()" << endl;
	}

	int _d;
};
//������������̣�
//1.����������е����ݿ���һ�ݷŵ����������
//2.�����������д�˻���ĳ���麯�������������Լ����麯����ַ�滻��ͬƫ������ַ�Ļ����麯����ڵ�ַ
//3.��������������ӵ��麯�����������ǵ���������һһ��ӵ����ĺ���

//֤��������ͨ�����Ӵ��ڲ���ֱ�ӿ��������������ӵ��麯�� 
//���������ͨ����¼�麯����ĵ�ַ�����ڴ洰���в鿴��
/*����һ��ռ�����4�ֽڿռ䣬ͨ���Աȣ�����ǰ���������������麯����ַ��ƥ�䣬
��ô�����ھ���Ҫ��֤��������ַ�ǲ��������������ӵ��麯���ġ�*/
//��֤����һ������һ�������������ӵ��麯��������ת������࣬��callָ��ĺ�����ַ�Ƿ����Ǻ������麯����ַƥ�䡣
//��֤���������ø��麯��
  //���ò��裺1.�Ӷ���ǰ4���ֽ��л�ȡ����ַvfptr
            //2.��vfptrָ��Ŀռ��л�ȡ��������ڵ�ַ
            //3.���Ե��øú���

#include<string>
typedef void(*PVFT)();//����һ������ָ��

void PrintTable(Base4& b,const string& information)
{
	cout << information << endl;
	PVFT* pVFT = (PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();//ͨ������ָ����øú���
		pVFT++;
	}
	cout << endl;
}

void Test6()
{
	Base4 b1;
	Base4 b2; //ͨ�����ڴ��м��b1��b2ǰ4���ֽ����ݣ���������ǰ4���ֽ���ȫ��ͬ������ͬһ���಻ͬ�����ڵײ㹲��һ�����
	b1._b = 1;
	Derived4 d;
	d._d = 1;

	//��֤��һ��
	d.Test5();
	d.Test4();

	//��֤������
	PrintTable(b1, "Base4 :VFT table");
	PrintTable(d, "Derived4 :VFT table");
}

/*7.2�麯���ĵ���ԭ��*/
class Base5
{
public:
	virtual void Test1()
	{
		cout << "Base5::Test1()" << endl;
	}
	virtual void Test2()
	{
		cout << "Base5::Test2()" << endl;
	}
	virtual void Test3()
	{
		cout << "Base5::Test3()" << endl;
	}
	void Test4()
	{
		cout << "Base5::Test4()" << endl;
	}
	int _b;
};

class Derived5 :public Base4
{
public:
	virtual void Test1()
	{
		cout << "Derived5::Test1()" << endl;
	}
	virtual void Test2()
	{
		cout << "Derived5::Test2()" << endl;
	}
	virtual void Test3()
	{
		cout << "Derived5::Test3()" << endl;
	}
	int _d;
};

// �麯���ĵ��ã�ͨ�������ָ��������õ����麯��
void TestVritual(Base5* pb)
{
	pb->Test1();
	pb->Test2();
	pb->Test3();
	pb->Test4();
}
void Test7()
{
	Base5 b;
	Derived5 d;
	TestVritual(&b);
	TestVritual((Base5*)&d);
}


/*7.3��̳����麯����Ĺ�������*/
//1.�뵥�̳������������Ĺ���������ͬ
//2.���������������ӵĺ����������������������ӵ���һ��������

//��֤
#if 0
class B1
{
public:
	virtual void TestFunc1()
	{
		cout << "B1::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "B1::TestFunc2()" << endl;
	}
	int _b1;
};

// 8
class B2
{
public:
	virtual void TestFunc3()
	{
		cout << "B2::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "B2::TestFunc4()" << endl;
	}
	int _b2;
};

// 20   24
class D : public B1, public B2
{
public:
	virtual void TestFunc1()
	{
		cout << "D::TestFunc1()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "D::TestFunc4()" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "D::TestFunc5()" << endl;
	}

	int _d;
};


typedef void(*PVFT)();

void PrintVFT1(B1& b, const string& str)
{
	cout << "D��дB1��������" << endl;
	PVFT* pVFT = (PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

void PrintVFT2(B2& b, const string& str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

void Test8()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;

	PrintVFT1(d, "D��дB1��������");
	PrintVFT2(d, "D��дB2��������");
}
#endif

int main()
{
	cout << "Test1()" << endl;
	Test1();
	cout << endl;
	cout << "Test2()" << endl;
	Test2();
	cout << endl;
	cout << "TestDestroy()" << endl;
	TestDestroy();
	cout << endl;
	cout << "Test3()" << endl;
	Test3();
	cout << endl;
	cout << "Test4()" << endl;
	Test4();
	cout << endl;
	cout << "Test5()" << endl;
	Test5();
	cout << endl;
	cout << "Test6()" << endl;
	Test6();
	cout << endl;
	cout << "Test7()" << endl;
	Test7();
	cout << endl;

	system("pause");
	return 0;
}