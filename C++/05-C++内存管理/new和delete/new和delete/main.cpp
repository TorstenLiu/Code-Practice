#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// 1.new/delete������������
//������ͷŵ����ڴ棬��new��delete��������������ͷ������Ŀռ䣬��new[]��delete[]������
void Test1()
{
	int* p1 = new int;//��̬����1��int���͵Ŀռ�
	int* p2 = new int(10);//��̬����1��int���͵Ŀռ�,����ʼ��Ϊ10
	int* p3 = new int[10];//��̬����10��int���͵Ŀռ�(����Ϊint[10])
	int* p4 = new int[10]{ 1,2,3,4,5,6,7,8,9,0 };//��̬����10��int���͵Ŀռ䡣����ʼ��Ϊ{1~0}

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
}
// 2.���new��deleteû��ƥ��ʹ�ã��������?
//���ۣ������������������͵Ŀռ䣬��������κκ��
void Test2()
{
	int* p1 = new int;
	int* p2 = new int[10];
	int* p3 = new int[10];
	delete[] p1;
	delete p2;
	free(p3);

	//...
}

//3.new/delete�����Զ�������
//new����ù��캯�� delete�����������������malloc��free����
class Test
{
public:
	Test()
		:_data(10)
		,_p(new int)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
	int* _p;
};
void Test3()
{
	Test* p1 = new Test;//���뵥��Test���͵Ķ���
	delete p1;
	cout << endl;
	Test* p2 = new Test[10];//����10��Test���͵Ķ���
	delete[] p2;

	Test* p3 = (Test*)malloc(sizeof(Test)); //���뵥��Test���͵Ŀռ�
	free(p3);
	Test* p4 = (Test*)malloc(sizeof(Test) * 10);//����10��Test���͵Ŀռ�
	free(p4);
}

//4.���new��deleteû��ƥ��ʹ�ã��������?
//
void Test4()
{
	Test* p1 = new Test;
	free(p1);

	Test* p2 = new Test[10];
	delete p2;//����
}
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	system("pause");
	return 0;
}