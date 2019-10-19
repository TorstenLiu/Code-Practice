#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<assert.h>

namespace Vector
{
	//1.�ຯ����Աʵ��

	template<class T>

	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		//����

		//�޲ι���
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		//��n��dataֵ����
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
		//���乹�� [first,last)
		//���ʹ��iterator��������,������ֻ����vector���͵ĵ�������
		//��Ҫ���¶�������������������Ϊ���������ĵ�����
		template<class Iteractor>
		vector(Iteractor first, Iteractor last)
		{
			//�Ȼ�ȡ����Ԫ�ظ���
			size_t n = 0;
			auto it = first;
			while (it != last)
			{
				n++;
			}
			//���ٿռ�
			_start = new T[n];
			//��������Ԫ��
			for (size_t i = 0; i < n; i++)
			{
				_start[i] = *first;
				first++;
			}
			_finish = _start + n;
			_endofstorage = _finish;
		}

		//��������
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			//1.����v���ٿռ�
			reserve(v.capacity());
			//2.�õ�����ͬʱ�����¾�v������Ԫ��
			iterator it = begin();
			const_iterator cit = v.cbegin();
			while (cit != v.cend())
			{
				*it = *cit;
				it++;
				cit++;
			}
			//3.����finish��endofstorageָ��
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
		}

		//���������
		vector<T>& operator=(const vector<T> v)
		{
			swap(v);
			return *this;
		}

		//����
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		/*�ӿ�ʵ��*/

	//2�������� ��ͨ���ͺ�const����
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish;
		}

		//3.��������
		size_t size() const//��Ա�������ܱ���
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _endofstorage - _start;
		}
		bool empty()const
		{
			return _start == _finish;
		}


		// T():
		// ���T�����������ͣ�T()--->0
		// ���T�����Զ������ͣ�T()---> ���ø�����޲ι��캯��
		void resize(size_t newsize,const T& data = T())
		{
			size_t oldsize = size();
			//newsize����oldsize�Ƚϣ������������һ��
			if (newsize > oldsize)
			{
				size_t oldcapacity = capacity();
				//����oldcapacity�Ƚϣ�����������
				if (newsize > oldcapacity)
				{
					reserve(newsize);
				}
				//������ʣ��ռ�
				for (; oldsize < newsize; oldsize++)
				{
					*_finish = data;
					_finish++;
				}

			}
			//newsizeС��oldsize��ֱ����С,ֱ�Ӹ���finish��ok�������ڵ�����ҲҪ����finish
			_finish = _start + newsize;
		}
		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = capacity();
			if (newcapacity > oldcapacity)
			{
				//1.�����¿ռ�
				T* temp = new T[newcapacity];
				//2.����Ԫ��  �������õ��������ʣ��������¿ռ䣬��������ʧЧ
				size_t n = size();
				if (_start)
				{
					for (size_t i = 0; i < n; i++)
					{
						temp[i] = _start[i];
					}
					//3.�ͷžɿռ�
					delete[] _start;
				}
				//4.��������ָ��
				_start = temp;
				_finish = _start + n;
				_endofstorage = _start + newcapacity;
			}
		}

		//4.����
		//[]���� ��ͨ��const����
		T& operator[](size_t index)
		{
			assert(index < size());
			return _start[index];
		}
		const T& operator[](size_t index) const
		{
			assert(index < size());
			return _start[index];
		}
		//��Ԫ��
		T& front()
		{
			return *_start;
		}
		const T& front()const
		{
			return *_start;
		}
		//βԪ��
		T& back()
		{
			return *(_finish - 1);
		}
		const T& back()const
		{
			return *(_finish - 1);
		}

		//5.�޸Ĳ���

		void push_back(const T& data)
		{
			//����Ƿ�Ҫ����
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2 + 3);//+3����һ�β������ݵ�ʱ��capacityΪ0������2����Ϊ0��������Ч����
			}
			*_finish = data;
			_finish++;
		}
		void pop_back()
		{
			_finish--;
		}
		//Ҫ�����²���Ԫ�ص�λ�ã����Է���ֵ����Ϊ������
		iterator insert(iterator pos, const T& data)
		{
			//1.����Ƿ���Ҫ����
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2 + 3);
			}
			//2.��[pos,finish)֮���Ԫ�ض������һλ
			//�����ǰ������
			auto it = _finish;
			while (it > pos)
			{
				*it = *(it - 1);
				it--;
			}
			//3.������Ԫ�أ�����������λ��
			*pos = data;
			_finish = _start + size();
			return pos;
		}
		//Ҫ����ɾ��Ԫ�غ����posλ�õ�Ԫ��
		iterator erase(iterator pos)
		{
			assert(pos <= _finish);
			if (pos == end())
			{
				return pos;
			}
			//it���������Ԫ�ص�λ��
			auto it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			_finish--;
			return pos;
		}
		void clear()
		{
			_finish = _start;
		}

	private:
		T* _start;//��ʼָ��
		T* _finish;//��ָֹ��  ��size
		T* _endofstorage;//��capacity
	};
}

void Test1()
{
	Vector::vector<int> v1;
	Vector::vector<int> v2(4, 7);
	Vector::vector<int> v3(v2);

	auto it = v2.begin();
	while (it != v2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto e : v3)
	{
		cout << e << " ";
	}
}

void Test2()
{
	Vector::vector<int> v1(2, 7);
	cout << v1.size() << endl;
	v1.resize(1);
	cout << v1.size() << endl;
	v1.resize(10, 6);
	cout << v1.size() << endl;


	cout << v1.back() << endl;
	cout << v1.front() << endl;

	v1.push_back(1);
	v1.push_back(2);
	cout <<"v1 fornt"<< v1.back() << endl;
	v1.pop_back();
	cout << v1.back() << endl;

	v1.insert(v1.begin(), 100);
	cout << v1.front() << endl;

	v1.erase(v1.begin());
	cout << v1.front() << endl;

	v1.clear();
	for (auto e : v1)
	{
		cout << e << " ";
	}
}
int main()
{
	Test1();
	cout << endl;
	Test2();
	system("pause");
	return 0;
}