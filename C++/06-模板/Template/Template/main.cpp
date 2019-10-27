#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//1.ģ���ʽ
template<class T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

template<class T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

//2.����ģ��ĳ�ʼ��
// 2.1��ʽʵ�������ñ���������ʵ������ģ�������ʵ������
void Test1()
{
	Add(1, 2);//int, int--T==>int ����intAdd����--->Add<int>
	Add(1.0, 2.0);//double, double--> T==>double ����double Add����--->Add<double>
	Add('1', '2');//char char-->T==char ����char Add����--->Add<char>
	//Add(1.0, 2);�����޷�����ʵ������

	//��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
	Add((int)1.0, 2);
}
//2.2 ��ʽʵ�������ں��������<>��ָ��ģ�������ʵ������
void Test2()
{
	Add<int>(1.0, 2);
}
int main()
{
	int a = 10, b = 20;
	swap(a, b);
	cout << a << b << endl;

	Add(a, b);

	Test1();

	Test2();
	system("pause");
	return 0;
}