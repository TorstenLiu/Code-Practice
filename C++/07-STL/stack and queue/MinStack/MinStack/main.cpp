#define _CRT_SECURE_NO_WARNINGS 1


//��Сջ��֧�� push��pop��top �����������ڳ���ʱ��0(1)�ڼ�������СԪ�ص�ջ��
#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

//1.����ջ--���ŷ���
class MinStack1
{
public:
	void push(const int x)
	{
		//����ջ
		s1.push(x);
		//��Сֵջ

		//ջ��||��ջԪ��<=��Сջ��Ԫ��
		if (s2.empty() || x <= s2.top())
		{
			s2.push(x);
		}

	}
	int top()
	{
		return s1.top();
	}
	int GetMin()
	{
		count++;
		return s2.top();
	}
	void pop()
	{
		/*����Ҫ������ջ���ں��������Ȼǰ��if�������Ҳ�������ջջ��*/
		//��Сֵջ

		//����Сֵջ��==����ջջ��ʱ����ջ
		if (s2.top() == s1.top())
		{
			s2.pop();
		}
		//����ջ
		s1.pop();
	}
private:
	stack<int> s1;//����ջ
	stack<int> s2;//��Сֵջ
	int count;//����GetMin()���������˼��Σ���ʱ�临�Ӷ��Ƿ�ΪO(1)
};


//2.һ����ѹ����Ԫ�أ�һ�������β���ֵ��һ������ǰջ����Сֵ
class MinStack2
{
public:
	void push(const int& x)
	{
		if (s.empty() || x <= s.top())
		{
			s.push(x);
			s.push(x);
		}
		else
		{
			int temp = s.top();
			s.push(x);
			s.push(temp);
		}
	}
	int top()
	{
		int ret = 0;
		int temp = s.top();
		s.pop();
		ret = s.top();
		s.push(temp);
		return ret;
	}
	int GetMin()
	{
		count++;
		return s.top();
	}
	void pop()
	{
		s.pop();
		s.pop();
	}
private:
	stack<int> s;
	int count;
};
int main()
{
	MinStack1 s;
	s.push(100);
	s.push(6);
	s.push(4);
	s.push(9);
	s.push(3);
	s.push(5);

	s.pop();
	s.pop();
	cout << s.GetMin() << endl;
	system("pause");
	return 0;
}