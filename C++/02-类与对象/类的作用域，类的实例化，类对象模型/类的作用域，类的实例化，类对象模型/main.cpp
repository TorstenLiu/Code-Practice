#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//1.����������������г�Ա�����������������У������ⶨ���Ա��Ҫʹ��::����������ó�Ա�����ĸ�����
//����һ��Ϊʲô������һ��������¶�����һ��������֤����
//��Ϊ��Ҫʹ��::�����������

//����2��Ϊʲô�����п�����ʹ�ñ������壿
//1.������ͨ��this���ʳ�Ա��������壬Ҳ����ͨ��thisָ���ҵ���Ӧ�ı���
//2.������������Ĺ���
class Student
{
public:
	void PrintStudentInfo();
private:
	char _name[20];
	char _gender[3];
	int _age;
};
void Student::PrintStudentInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}
//2.���ʵ���������������ʹ������Ĺ���
//����һ����û�з���ʵ�ʵ��ڴ�ռ䣬��ʵ���������Ķ����ռ��ʵ�ʵ�����ռ䣬�洢��Ա����
//�����ϴ��붨��һ��Student�࣬������Student s������һ������s������ʵ����


//3.�����ģ��
//������Ĵ�С�����Ǹ����г�Ա����֮�ͣ��ڴ����
//ʵ����
class A2
{
public:
	void f1();
private:
	int _a;
};
class A3
{
public:
	void f2();
};
class A4
{

};
int main()
{
	Student s;
	s.PrintStudentInfo();
	cout << sizeof(A2) << endl;//4
	cout << sizeof(A3) << endl;//1
	cout << sizeof(A4) << endl;//1  ע�����Ĵ�С���Ƚ����⣬��vs���������������棬�������һ���ֽ���Ψһ��ʶ�����

	system("pause");
	return 0;
}
