#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

//this������
//�ṹ��
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
	void InitStudent(Student *ps)
	{
		strcpy(ps->_name, 0);
		strcpy(ps->_gender, 0);
		ps->_age = 0;
	}
	void SetStudentInfo(Student * ps, const char * name, const char * gender, int age)
	{
		strcpy(ps->_name, name);
		strcpy(ps->_gender, gender);
		ps->_age = age;
	}
	void PrintStudent(Student *ps)
	{
		cout << ps->_name << " " << ps->_gender << " " << ps->_age << endl;
	}
};

//class
class Date
{
public:
	void Show()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

//thisΪ�յĲ���
class A
{
public:
	void Print()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	Student s;
	Student t;
	Student *s1=&s;
	Student *t1=&t;
	s1->SetStudentInfo(s1 ,"Tom", " nan", 12);
	t1->SetStudentInfo(t1, "Spring", "nv", 18);
	s1->PrintStudent(s1);
	t1->PrintStudent(t1);
	Date d1, d2;
	d1.SetDate(2019, 9, 14);
	d2.SetDate(2019, 9, 15);

	d1.Show();
	d2.Show();

	A *p = NULL;//pָ���Ϊһ���ն���
	p->Show();
	p->Print();//�����㣬��Ϊthis�õ��ĵ�ַΪ��
	p->Show();
	system("pause");
	return 0;
}
//���⣺s1����Dateʱ���ú������֪��Ӧ������s1���󣬶���������s2�����أ�
//c++��ÿ����Ա����������һ�����ص�ָ������������ָ��ָ���������(ע���ǵ�ǰ���øú����Ķ���)��
//���Ըó�Ա�����Ĳ�����ͨ��ָ�������ʡ������ָ���������this


//thisָ������ԣ�
//1.thisָ������ͣ��������*const����һ��ָ������Լ��ĳ���ָ�룬���ܸ�this��ֵ
//2.ֻ���ڳ�Ա�ڲ�ʹ��
//3.������ú���ʱ������ĵ�ַ��Ϊʵ�δ��ݸ�this
//4.this���ʣ���һ���������βΣ��ɱ�����ͨ��ecx�Ĵ������ݣ�����Ҫ�Լ�����
//5.�޸����Ա������ �������Ա��������ͬʱ��this->a=a
//6.��̬������û��thisָ�룬static��const����ͬʱ���γ�Ա����

//thisָ���̽�֣�

//����2����������this����ecx�Ĵ������ݣ����粻����������ô��ô�жϷ�����this��ʲô���ݣ�
//��д�����Ķ��壬�鿴����ʱ�ĺ���Լ����_this call

//����3��thisָ���ں�ʱ�������ģ�
//����һ���¶����ʱ�򣬾����ĸ��׶δ�̽����

//����4��thisָ���������
//thisָ�����������ͬ�����λ�ÿ����в�ͬ��������ջ���Ĵ���������ȫ�ֱ������Ҿ���Ӧ��ȡ����this��ʲô�������д��ݡ�

//����5��thisָ�����Ϊ����
//���ԣ�����thisΪ�����Ƿ����ʳ�Ա��������������ˣ�this�õ���Ϊ�յ�ַ������ͻ����