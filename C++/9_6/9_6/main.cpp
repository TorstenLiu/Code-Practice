#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//��������:ͬһ������ͬ���������β��б��������������ͣ�˳�򣩲�ͬ
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
//2.������������ֵ���Ͳ�ͬ������������
/*void Test(int a)
{

}
int Test(int a)
{
	return a;
}*/
//3.ͬ�����޲κ�����ȫȱʡ������Ҫͬʱ����
/*void Test()
{

}
void Test(int a = 10)
{

}
*/
//4.ȱʡ�������������� Ҳ���ܹ�������
/*void Test(int a)
{
}
void Test(int a = 10)
{

}*/



int main()
{
	cout << Add(10, 20) << endl;
	cout << Add(10.0, 20.0) << endl;
	cout << Add(10L, 20L) << endl;
	//1.Add(10,20.0);������ʽ����ת����ת����int��int����double��double����֪�������ĸ�����
	system("pause");
	return 0;
}

//һЩ��Ŀ��
/*
1.C����Ϊʲô��֧�ֺ������أ�   
     ��������У�C��ֱ����ÿһ��������ǰ��_���ᵼ�³�ͻ
2.C++�к������صײ�����������ģ�  
     C++�����뺯�������ͣ����κ�������ɺ������ֺͺ���������ɣ�Ҳ����˵��������ͬ�������
	 ֻҪ�����б�ͬ�������ʱ���εĽ��Ҳ��ͬ�����Ա�֤�����ڵײ��ȫ��Ψһ��
3.C++���ܷ�һ����������C�����д��
     һ����Դ�ļ���ʽ�ĳ�.c    �����ں���ǰ��+extern "C"
*/