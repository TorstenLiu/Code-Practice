#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


template<class T>

class vector
{
public:
	//����
	vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endofstorage(nullptr)
	{}

	vector(int n, const T& data)
		:_start(new T[n])
	{
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = data;
		}
		_finish = _start + n;
		_endofstorage = _finish;
	}
	//����
private:
	T* _start;//��ʼָ��
	T* _finish;//��ָֹ��  ��size
	T* _endofstorage;//��capacity
};
int main()
{
	system("pause");
	return 0;
}