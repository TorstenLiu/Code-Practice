#define _CRT_SECURE_NO_WARNINGS 1



//CSDN:https://blog.csdn.net/qq_42913794/article/details/102987333
#include<iostream>
using namespace std;


/*1.�̳еĸ���*/
//����person
class Person
{
public:
	void Set(const char* name, int age, int acount)
	{
		_name = name;
		_age = age;
		_acount = acount;
	}
	void Print() 
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
		cout << "acourt" << _acount << endl;
	}
public:
	const char* _name;
protected:
	int _age;
private:
	int _acount;
};
class Student :public Person
{};

void Test()
{

	Person p;
	p.Set("zss", 18, 123456);
	p.Print();
	cout << "p:" << sizeof(p) << endl;

	Student s;
	// ��֤�������еĳ�Ա�����ͷű�����̳У�����
	s.Set("pxy", 18, 123456);
	s.Print();
	cout << "s:" << sizeof(s) << endl;//ͨ����ӡһ��student����Ĵ�С������֤�������ཫ�����еĳ�Ա�����̳е�������

	cout << endl;
}

/*2,�̳еĶ���==��ʽ*/
// ����Ȩ�ޣ��޶��ó�Ա�����Ƿ����ֱ����������е���
//2.1 public�̳�
// ������public/protected�ĳ�Ա��������Ȩ�޲���  
// ������private�ĳ�Ա�������в��ɼ�(������---�ó�Ա����ȷʵ�Ѿ��̳е�������)

//����
class Base1
{
public:
	void Set(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void Print()
	{
		cout << "_pub:" << _pub << endl;
		cout << "_pro:" << _pro << endl;
		cout << "_pri:" << _pri << endl;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
//������
class Derived1 :public Base1
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pubD = pubD;
		_proD - proD;
		_priD = priD;

		_pub = 10;//public ����
		_pro = 20;//protected ����
		//_pri = 30;  private �����������в��ܷ��ʻ�����˽�еĳ�Ա����

	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

void Test1()
{
	Derived1 d;
	d.SetDerived(100, 100, 100);

	d._pub = 10;//public��Ա�������������
	//d._pro = 20;  protected ���� �����еı�����Ա�����ڳ��˻����������� �������
	cout << d._pubD << endl;
	
	cout << d._pub << endl;
	cout << "d:" << sizeof(d) << endl;
	cout << endl;
}

//2.2 protected�̳�
// ������public�ĳ�Ա�������з���Ȩ���Ѿ����protected
// ������protected�ĳ�Ա�������з���Ȩ�޲���
// ������private�ĳ�Ա�������в��ɼ�(������---�ó�Ա����ȷʵ�Ѿ��̳е�������)

//����
class Base2
{
public:
	void Set(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void Print()
	{
		cout << "_pub:" << _pub << endl;
		cout << "_pro:" << _pro << endl;
		cout << "_pri:" << _pri << endl;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
//������
class Derived2 :private Base2
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pubD = pubD;
		_proD - proD;
		_priD = priD;

		_pub = 10;//public->protected 
		_pro = 20;//protected ���� ֻ�������������
		//_pri = 30;  private �����������в��ܷ��ʻ�����˽�еĳ�Ա����

	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

void Test2()
{
	Derived2 d;
	d.SetDerived(10, 10, 10);
	//d._pub = 100;  public�Ѿ����protected  
	//cout << d._pub << endl;
	cout << endl;
}

//3.private�̳�
// ������public�ĳ�Ա�������з���Ȩ���Ѿ����private
// ������protected�ĳ�Ա�������з���Ȩ���Ѿ����private
// ������private�ĳ�Ա�������в��ɼ�(������---�ó�Ա����ȷʵ�Ѿ��̳е�������)

//����
class Base3
{
public:
	void Set(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void Print()
	{
		cout << "_pub:" << _pub << endl;
		cout << "_pro:" << _pro << endl;
		cout << "_pri:" << _pri << endl;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
//������
class Derived3 :private Base3
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pubD = pubD;
		_proD - proD;
		_priD = priD;

		_pub = 10;//public->private 
		_pro = 20;//protected->private
		//_pri = 30;  private �����������в��ܷ��ʻ�����˽�еĳ�Ա����

	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

void Test3()
{
	Derived3 d;
	//d._pub = 100;
	//cout << d._pub << endl;
}

/*3.stuct��class��Ĭ�ϼ̳з�ʽ*/
//class--Ĭ��private
//struct--Ĭ��public
class Base4
{
public:
	void Set(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void Print()
	{
		cout << "pub:" << _pub << endl;
		cout << "pro:" << _pro << endl;
		cout << "pri:" << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
struct Derived4 :Base4
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pubD = pubD;
		_proD = proD;
		_priD = priD;

		//�����pub��pro���ܷ��ʣ�����֤����public�̳л�����protected�̳з�ʽ�����ͨ��������������ж�������
		_pub = 10;
		_pro = 10;
		//_pri = 10;private���ܷ���
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

void Test4()
{
	Derived4 d;
	d._pub = 1000;//�����pub������������ʣ�֤����public�̳�
	//d._pro = 100;��������protected�������������
	cout << d._pub << endl;
}

/*4.��������������ֵת��   ǰ�᣺public�̳�*/ 
//4.1 ��������� ���Ը�ֵ�� ����Ķ��� + �����ָ�� + ��������á�
//4.2 ��������ܸ�ֵ��������
//4.3 �����ָ�����ͨ��ǿ������ת����ֵ���������ָ��

class A
{
public:
	void Set(int a)
	{
		_a = a;
	}
public:
	int _a;
};
class B :public A
{
public:
	void Set(int a, int b)
	{
		_a = a;
		_b = b;
	}
protected:
	int _b;
};
void Test5()
{
	A a;
	a.Set(10);
	B b;
	b.Set(20, 30);
	//1.�����������������ֵ
	a = b;
	cout << "a._a:" << a._a << endl;

	//2.������ָ�븳ֵ
	A* ap = &b;
	cout << ap->_a<< endl;

	//3.���������ø�ֵ
	A& aa = b;
	cout << aa._a << endl;

	//B* bp = &a;  ����
	//4.��������ܸ�ֵ��������
	//b = a;

	//5.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��,��ע�⣺�������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
	B* bp = (B*)&a;
	cout << bp->_a << endl;
}

/*5.�̳��е�������*/
//1. �ڼ̳���ϵ�л���������඼�ж���������������ͬ�������Ͳ�������
//2.ͬ�����أ�������ͻ����о�����ͬ���Ƶĳ�Ա����Ա�����ͳ�Ա������
//3.���ʹ�����������ֱ�ӷ���ͬ����Ա��������������ȷ����Լ��ĳ�Ա���൱�ڻ����ͬ����Ա����
//ע�⣺��Ա����ͬ��---->���Ա���������Ƿ���ͬ�޹�
//      ��Ա����ͬ��---->�뺯��ԭ���Ƿ���ͬ�޹�
//��Ҫ ͨ����������ʻ����Ա�ķ�����   ʹ��ʱ����ͬ��ǰ��+��������ƺ��������޶���


//ͬ������
//����
class Q
{
public:
	void Set(char q)
	{
		_q = q;
	}
//protected:
public:
	char _q;
};
//������
class W :public Q
{
public:
	void Set(int q, int w) 
	{
		_q = q;
	}
//protected:
public:
	int _q;
};

void Test6()
{
	cout <<"sizeof(W)"<< sizeof(W) << endl;
	W w;
	w._q = 'a';//ͬ�����أ�ֱ�ӷ����������Ԫ��
	w.Q::_q = 'b';//����ʻ���Ԫ�أ����������ռ伴��
	cout << w._q << endl;
	cout << w.Q::_q << endl;
}

/*6.4.�������Ĭ�ϳ�Ա����*/

//1. ������Ĺ��캯������û���Ĺ��캯����ʼ���������һ���ֳ�Ա��

//1.1�������Ĺ��캯�����޲λ���ȫȱʡ��Ĭ�Ϲ��캯�������������ʼ���б��λ�õ��û򲻵��ö����ԣ�����û�û�е��ã����������Ĭ�ϵ���
//1.2�������û��Ĭ�ϵĹ��캯��(�����Զ����˹��캯��)��������������๹�캯���ĳ�ʼ���б�׶���ʾ���ø���ʽ���캯��
//��Ϊ��ʽ���캯���󣬱��������Ҳ���Ĭ�Ϲ��캯����

//��֤1.1
class Base7
{
public:
	////�޲�
	//Base7()
	//	:_b(10)
	//	
	//{
	//	cout << "�޲�Base7()" << endl;
	//}

	//ȫȱʡ
	Base7(int b=100)
		:_b(b)
	{
		cout << "ȫȱʡBase7(int b=100)" << endl;
	}
//protected:
public:
	int _b;
};

class Derived7 : public Base7
{
public:
	Derived7()
		:_d(10)
	{
		cout << "�޲�Derived7()" << endl;
	}	
//protected:
public:
	int _d;
};

void Test7()
{
	Base7 b;//��һ�ι���
	Derived7 d;//��һ�λ��๹�죬��һ��������
	cout << b._b << endl;
	cout << d._d << endl;
	cout << d._b << endl;
	cout << endl;
}
//��֤1.2
class Base8
{
public:
	Base8(int b)
		:_b(b)
	{
		cout << "�Զ���Base8()" << endl;
	}
//protected:
public:
	int _b;
};

class Derived8 : public Base8
{
public:
	Derived8()
		:Base8(100)
		,_d(10)
	{
		cout << "�޲�Derived8()" << endl;
	}
//protected:
public:
	int _d;
};

void Test8()
{
	Base8 b(1000);
	Derived8 d;
	cout << b._b << endl;
	cout << d._d << endl;
	cout << endl;
}

//2.������Ŀ������캯������û���Ŀ���������ɻ���Ŀ�����ʼ����

//2.1�������û����ʾ���幹�캯������������Ҳ���Բ��ö��壬�������඼���Բ���Ĭ�Ϲ��캯����ǰ�᣺���漰��Դ����
//2.2���������ʽ�����˹��캯������������ͱ����������ʼ���б���ʽ���û���Ĺ��캯��


//3.��ֵ��������أ�
//3.1�������û����ʾ����������Ҳ���Բ��ṩ��������������Ҫ���������������ٸ����������
//3.2���������ʽ�����˸�ֵ��������أ�һ��������ҲҪ�ṩ������Ҫ�����е��û��������

//��֤2.1
class Base9
{
public:
	Base9(int b)
		:_b(b)
	{}
	//protected:
public:
	int _b;
};
class Derived9 :public Base9
{
public:
	Derived9(int d)
		:Base9(100)
		,_d(d)
	{}

public:
	int _d;
};

void Test9()
{
	Derived9 d1(1000);
	Derived9 d2(d1);
	cout << d1._d << endl;//1000
	cout << d1._b << endl;//100
	cout << d2._d << endl;//1000
	cout << d2._b << endl;//100
	cout << endl;
}

//��֤2.2  3.2
class Base10
{
public:
	Base10(int b)
		: _b(b)
	{}

	Base10(const Base10& b)
		: _b(b._b)
	{}

	Base10& operator=(const Base10& b)
	{
		if (this != &b)
		{
			_b = b._b;
		}

		return *this;
	}
public:
	int _b;
};

class Derived10 : public Base10
{
public:
	Derived10(int b, int d)
		: Base10(b)
		, _d(d)
	{}

	Derived10(const Derived10& d)
		: Base10(d)
		, _d(d._d)
	{}

	Derived10& operator=(const Derived10& d)
	{
		if (this != &d)
		{

			//*this = d;
			// �����ಿ�ֳ�Ա��ֵ
			Base10::operator=(d);
			// �������������ӳ�Ա��ֵ
			_d = d._d;
		}
		return *this;
	}
public:
	int _d;
};

void Test10()
{
	Derived10 d1(1, 2);
	Derived10 d2(d1);

	Derived10 d3(3, 4);
	d2 = d3;
	cout << d1._b << endl;
	cout << d1._d << endl;
	cout << d2._b << endl;
	cout << d2._d << endl;
	cout << d3._b << endl;
	cout << d3._d << endl;
}

//3.������ͻ��๹�캯�������������ĵ��ô���
class Base11
{
public:
	Base11(int b)
		:_b(b)
	{
		cout << "Base10::Base10(int)" << endl;
	}
	~Base11()
	{
		cout << "Base10::~Base10()" << endl;
	}
public:
	int _b;
};
class Derived11 :public Base11
{
public:
	Derived11(int b, int d)
		: Base11(b)
		, _d(d)
	{
		cout << "Derived::Derived(int,int)" << endl;
	}

	~Derived11()
	{
		cout << "Derived::~Derived()" << endl;
		// call Base::~Base();
	}
public:
	int _d;
};

void Test11()
{
	Derived11 d(10, 20);
}
// 1. ���н�����ӡ���
	   /*
	   �������ִ�д����ȵ����๹��--->�����๹��--->����������--->��������
		  Base::Base(int)
		  Derived::Derived(int,int)
		  Derived::~Derived()
		  Base::~Base()
	   */
	   // 2. ����������ĵ��ô���
	   /*
			 �������
			   �����๹�캯��()
				  : ���๹�캯������
			   {}

			   ��������
			   ��������������()
			   {
				  // �ͷ���������Դ

				  // �������������������������һ����Ч�������һ��������
				  call ������������;
			   }
	   */
int main()
{
	Test();
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	Test11();

	system("pause");
	return 0;
}