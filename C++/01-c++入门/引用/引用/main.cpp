#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<time.h>
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
//������ֵ:���ǲ��ܷ���ջ�ϵĿռ�
int& Test4(int& a)
{
	a += 10;
	return a;
}

//5.��ֵ����ַ�������õ�Ч�ʱȽ�
struct A
{
	int a[1000];
};
void Test5(A a)
{}
void Test6(A& a)
{}
void Test7(A* a)
{}
void Test8()
{
	A a = { 1,23,10 };
	//��ֵ��
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		Test5(a);
	}
	size_t end1 = clock();
	//�����ã�
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		Test6(a);
	}
	size_t end2 = clock();
	//��ַ��
	size_t begin3 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		Test7(&a);
	}
	size_t end3 = clock();
	cout << "Test5:" << end1 - begin1 << endl;
	cout << "Test6:" << end2 - begin2 << endl;
	cout << "Test7:" << end3 - begin3 << endl;


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
	cout<<Test4(a)<<endl;
	for (int i = 0; i < 10; i++)
	{
		Test8();
	}
	//6.���ú�ָ�����ͬ�벻ͬ��
	//��ͬ��
	int &ra = a;
	ra = 20;
	int *pa = &a;
	*pa = 20;
	cout << a << endl;//���ú�ָ�붼���Ըı�a��ֵ
	//��ͬ��
	//һ����sizeof�к��岻ͬ��ָ���С��32λƽ̨��ʼ��Ϊ4���ֽڡ�������ͬ����̲�
	char c = 'c';
	char *pc = &c;
	char& rc = c;
	cout << sizeof(pc) << endl;
	cout << sizeof(rc) << endl;
	system("pause");
	return 0;
}