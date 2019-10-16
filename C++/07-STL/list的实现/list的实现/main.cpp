#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

namespace List
{
	//List�Ľڵ���  
	template<class T>
	struct ListNode
	{
		ListNode(const T& data = T())
			:_prev(nullptr)
			,_next(nullptr)
			,_data(data)
		{}

		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _data;
	};

	//list�ĵ������� ���ڵ����͵�ָ�����·�װ
	template<class T>
	class list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> self;
	public:
		//����
		list_iterator(Node* pcur)
			:_pcur(pcur)
		{}
		//��������һЩӦ��
		T& operator*()
		{
			return _pcur->_data;
		}
		T* operator->()
		{
			return &(_pcur->_data);
		}
	private:
		Node* _pcur;
	};
	//list��  ��ͷ���˫��ѭ������
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		//list�Ĺ���
		//�޲�
		list()
		{
			CreateHead();
		}
		//n��ֵ����
		list(int n, const T& data)
		{
			CreateHead();
			for (size_t i = 0; i < n; i++)
			{
				push_back(data);
			}
		}
		//���乹�죬��Ҫһ��������ģ��
		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first < last)
			{
				push_back(*first);
				first++;
			}
		}
		//��������
		list(const list<T>& l)
		{
			CreateHead();
			Node* cur = l._phead->_next;
			while (cur != l._phead)
			{
				push_back(cur->_data);
				cur = cur->_next;
			}
		}

		//��ֵ���������
		list<T>& operator=(const list<T>& l)
		{
			if (this != &l)
			{
				clear();
				Node* cur = l._phead->_next;
				while (cur != l._phead)
				{
					push_back(cur->_data);
					cur = cur->_next;
				}
			}
		}

		//����
		~list()
		{
			clear();
			delete _phead;
		}

	public:
		//����������

		//��������
		size_t size()const
		{
			size_t count = 0;
			Node* cur = _phead->_next;
			while (cur != _phead)
			{
				count++;
				cur = cur->_next;
			}
			return count;
		}
		size_t empty()const
		{
			return _phead->_next = _phead;
		}
		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)
			{
				for (size_t i = oldsize; i < newsize; i++)
				{
					push_back(data);
				}
			}
			else
			{
				for (size_t i = newsize; i < oldsize; i++)
				{
					pop_back();
				}
			}
			
		}
		//Ԫ�ط���
		T& front()
		{
			return _phead->_next->_data;
		}
		const T& front()const
		{
			return _phead->_next->_data;
		}
		T& back()
		{
			return _phead->_prev->_data;
		}
		const T& back()const
		{
			return _phead->_prev->_data;
		}
		//�޸Ĳ���
		void push_back(const T& data)
		{
			insert(end(), data);
		}
		void pop_back()
		{
			end()--;
			erase(end());
		}
		void push_front(const T& data)
		{
			insert(begin(), data);
		}
		void pop_front()
		{
			erase(begin());
		}
		//insert
		//erase
		void clear()
		{
			//ͷɾ
			Node* cur = _phead->_next;
			while (cur != _phead)
			{
				_phead->_next = cur->_next;
				delete cur;
				cur = _phead->_next;
			}
			//��ͷ����Լ�ָ�Լ�������һ����list
			_phead->_next = _phead;
			_phead->_prev = _phead;
		}

		void swap(list<T>& l)
		{
			swap(_phead, l._phead);
		}

	private:
		void CreateHead()
		{
			_phead = new Node;
			_phead->_prev = _phead;
			_phead->_next = _phead;
		}
	private:
		Node* _phead;
	};
}

void Test1()
{
	List::list<int> l1(2, 10);
}
int main()
{
	Test1();
	system("pause");
	return 0;
}