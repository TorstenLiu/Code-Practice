#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//1.�������͵Ķ���
void Test1()
{
	int a = 10;
	int& ra = a;//�����������ͣ����������ʵ��aһ������
	cout << &a << endl;
	cout << &ra << endl;
}
//2.��������
void Test2()
{
	int a = 10;
	//int &ra;�������ö���ʱ����Ҫ��ʼ��
	int& ra = a;
	int& rra = a;//һ�����������ж������
	cout << &ra << endl;
	cout << &rra << endl;
	//����һ������һ��ʵ�壬�Ͳ�������������ʵ�壬�������ra����������b�����Ƕ�ra��ֵ��a��ֵҲ�ᱻ�ı�
	int b = 20;
	ra = 20;
	cout << a << endl;
}
//3.������
void Test3()
{
	const int a = 10;//aΪ����
	//int& ra = a;����
	const int& ra = a;

	cout << ra << endl;
	double b = 12.34;
	const double& rb1 = b;
	const int& rb2 = b;
	//rb2���õ��Ǹ����Ϳռ䣬����ռ�ֻ������b���������֣��ҿռ�û�����ֺ͵�ַ�����г��ԣ�����Ҫ��const����
	cout << rb1 << endl;
	cout << rb2 << endl;

}
//4.���ó���
//��������
//��ͨ���βθı��ⲿʵ��ʱ���β���������ͨ�������á�����ı�ʱ���β�����Ϊconst��������
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
//������ֵ
int& Test4(int& a)
{
	a += 10;
	return a;
}
int main()
{
	Test1();
	cout << endl;
	Test2();
	cout << endl;
	Test3();
	cout << endl;
	int a=10;
	int&ra = a;
	cout<<Test4(ra)<<endl;
	system("pause");
	return 0;
}