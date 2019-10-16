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
		//1.���� ע�����ΪNode*
		list_iterator(Node* pcur)
			:_pcur(pcur)
		{}
		//2.����ָ��Ĳ���
		T& operator*()
		{
			return _pcur->_data;
		}
		T* operator->()
		{
			return &(_pcur->_data);
		}
		//3.�ƶ�
		
		//ǰ��++
		self& operator++()
		{
			_pcur = _pcur->_next;
			return *this;
		}
		//����++
		self& operator++(int)
		{
			self temp(*this);
			_pcur = _pcur->_next;
			return temp;
		}
		//ǰ��--
		self& operator--()
		{
			_pcur = _pcur->_prev;
			return *this;
		}
		//����--
		self& operator--(int)
		{
			self temp(*this);
			_pcur = _pcur->_prev;
			return temp;
		}
		//4.�Ƚ�
		bool operator!=(const self& it)
		{
			return _pcur != it._pcur;
		}
		bool operator == (const self& it)
		{
			return _pcur == it._pcur;
		}

	//private:
		Node* _pcur;
	};
	//list��  ��ͷ���˫��ѭ������
	template<class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef list_iterator<T> iterator;
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
			return *this;
		}

		//����
		~list()
		{
			clear();
			delete _phead;
		}

	public:
		//����������
		//����
		iterator begin()
		{
			return iterator(_phead->_next);
		}
		iterator end()
		{
			return iterator(_phead);
		}
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
			return _phead->_next == _phead;
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
			//--end();
			erase(--end());
		}
		void push_front(const T& data)
		{
			insert(begin(), data);
		}
		void pop_front()
		{
			erase(begin());
		}

		//��posλ��ǰ�����һ��data
		iterator insert(iterator pos, const T& data)
		{
			//�Ƚ�data���һ���ڵ�
			Node* pNewNode = new Node(data);
			//��һ��ָ��ָ��pos
			Node* pcur = pos._pcur;
			//�ֱ�ı����ڵ�ָ��ָ��
			pNewNode->_prev = pcur->_prev;
			pNewNode->_next = pcur;
			pNewNode->_prev->_next = pNewNode;
			pcur->_prev = pNewNode;
			//���ص���������(ָ������)  �½ڵ��λ��
			return iterator(pNewNode);
		}
		iterator erase(iterator pos)
		{
			//��һ��ָ��=�õ�������ָ�룬����һ��ָ��ָ����ڵ�
			Node* pcur = pos._pcur;
			//���ж��Ƿ�Ϊͷ��㣬����ֱ�ӷ��ؿ�
			if (pcur == _phead)
			{
				return end();
			}
			//�����ǣ��ҵ���ɾ�ڵ����һ���ڵ�
			Node* npcur = pcur->_next;
			//�ı�ָ�򣬲�ɾ��pos�Ľڵ�

			/*npcur->_prev = pcur->_prev;
			pcur->_prev->_next = npcur;*/

			pcur->_prev->_next = pcur->_next;
			pcur->_next->_prev = pcur->_prev;
			delete pcur;
			//����ɾ���ڵ���һ���ԭ��λ�õĽڵ�
			return iterator(npcur);
		}
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

template <class T>
void Print(List::list<T> l)
{
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

//1.���캯������
#include<vector>
void Test1()
{
	List::list<int> l1(2, 10);
	List::list<int> l2(l1);
	Print(l1);
	Print(l2);

	vector<int> v{ 1,2,3,4,5,6,7 };
	List::list<int> l3(v.begin(), v.end());
	List::list<int> l4 = l3;
	Print(l3);
	Print(l4);
}

//��������������
void Test2()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	List::list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

//3.��������
void Test3()
{
	List::list<int> l(4, 7);
	cout << "old size:" << l.size() << endl;

	l.resize(10, 100);
	cout << "new size:" << l.size() << endl;

	cout << "if empty?" << l.empty() << endl;
}

//4.Ԫ�ط���,���޸Ĳ���
void Test4()
{
	vector<int> v{ 1,2,3,4,5,6,7 };
	List::list<int> l(v.begin(), v.end());
	cout <<"front:"<< l.front() << endl;
	cout << "back:" << l.back() << endl;

	l.push_back(100);
	cout << "back:" << l.back() << endl;
	l.push_front(100);
	cout << "front:" << l.front() << endl;
	Print(l);

	l.pop_back();
	cout << "back:" << l.back() << endl;

	l.pop_front();
	cout << "front:" << l.front() << endl;
	Print(l);

	List::list<int>::iterator pos = find(l.begin(), l.end(), 5);
	l.insert(pos, 100);
	Print(l);

	l.clear();
	if (l.empty());
	cout << "clear over" << endl;
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