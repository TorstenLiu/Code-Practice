#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//1.��ͨ�����ռ�
namespace N1
{
	int a = 10;
	int Add(int left, int right)
	{
		return left + right;
	}
}
//2.�����ռ�Ƕ��
namespace N2
{
	int a = 100;
	int b = 200;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace N3
	{
		int c;
		int d;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}
using namespace N2;//ʹ�������ռ�

//ȫȱʡ����
void Test1(int a = 10, int b = 20, int c = 30)
{
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
}
//��ȱʡ����
void Test2(int a, int b = 10, int c = 20)
{
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
}
int main()
{
	printf("%d\n",N1::a);
	printf("%d\n", a);

	int a = 0;
	double b = 0;
	char c;
	cin >> a;
	cin >> b >> c;
	cout << a << b << c << endl;

	cout << "helloworld!" << endl;

	Test1();
	Test2(10);
	system("pause");
	return 0;
}