#define _CRT_SECURE_NO_WARNINGS 1

#include"student.h"

//�������ֶ��巽ʽ��
//��ʽ1���������඼�������ж��壬����Ա���������ж�����ܻᱻ������������
class Student1
{
public:
	void SetStudentInfo(const char * name, const char * gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;

};

//��ʽ2����������.hͷ�ļ����Ķ������.cpp�ļ���
int main()
{
	Student1 s1;
	Student2 s2;
	s1.SetStudentInfo("Peter", "nan", 10);
	s2.SetStudentInfo("Summer", "nan", 4);
	s1.PrintStudentInfo();
	s2.showInfo();
	system("pause");
	return 0;
}