#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


//1.���캯��
void Test1()
{
	//�޲ι���
	vector<int> first;
	//���첢��ʼ��n��ֵ
	vector<int> second(4, 100);
	//��������
	vector<int> third(second);
	//��������ʼ������
	vector<int> fourth(second.begin(), second.end());
}
int main()
{
	Test1();
	system("pause");
	return 0;
}