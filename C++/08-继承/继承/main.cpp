#define _CRT_SECURE_NO_WARNINGS 1

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

/*4.��������������ֵת��*/
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

	//4.��������ܸ�ֵ��������
	//B* bp = &a;  ����
	//b = a;

	//5.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��,��ע�⣺�������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
	B* bp = (B*)&a;
	cout << bp->_a << endl;
}

/*5.�̳��е�������*/
//1. �ڼ̳���ϵ�л���������඼�ж���������������ͬ�������Ͳ�������
//2. ����͸�������ͬ����Ա�������Ա�����θ����ͬ����Ա��ֱ�ӷ��ʣ�������������أ�Ҳ���ض��塣���������Ա�����У�����ʹ�� ����::�����Ա ��ʾ���ʣ�
//3. ��Ҫע���������ǳ�Ա���������أ�ֻ��Ҫ��������ͬ�͹������ء�
//4. ע����ʵ�����ڼ̳���ϵ������ò�Ҫ����ͬ���ĳ�Ա��

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

int main()
{
	Test();
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	system("pause");
	return 0;
}