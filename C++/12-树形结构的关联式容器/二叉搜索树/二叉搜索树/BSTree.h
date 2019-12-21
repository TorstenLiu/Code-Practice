#pragma once

#include<iostream>
using namespace std;
/*�������������ԣ�
1.��������ڵ㣬����������������ڵ㶼�󣬱���������������ڵ㶼С
2.�����Ľڵ�һ������С�ģ����Ҳ�Ľڵ�һ��������
3.�����������һ����������*/

//�ڵ�ṹ��
template<class T>
struct BSTNode
{
	BSTNode(const T& data=T())
		:_pleft(nullptr)
		,_pright(nullptr)
		,_data(data)
	{}
	
	BSTNode<T>* _pleft;//����
	BSTNode<T>* _pright;//�Һ���
	T _data;//������
};

//������������
template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()//�ǵó�ʼ�����ڵ�
		:_proot(nullptr)
	{}
public:
	//1.����
	/*�����ڵ㲻Ϊ�գ�
	�����ǰ���ڵ�data==���ҵ�data true
	�����ǰ���ڵ�data>����data��������������
	�����ǰ���ڵ�data<����data��������������
	���򷵻�false*/
	Node* Find(const T& data)
	{
		Node* pcur = _proot;
		while (nullptr != pcur)
		{
			if (pcur->_data > data)
			{
				pcur = pcur->_pleft;
			}
			else if (pcur->_data < data)
			{
				pcur = pcur->_pright;
			}
			else
			{
				return pcur;
			}
		}
		return nullptr;
	}

	//2.����
	//��������1.���Ҵ�����ڵ�Ĳ���λ��  2.�����½ڵ�
	/* ����ǿ�������ֱ�Ӳ��룬����true
	  ����Ƿǿ��������Ҵ�����ڵ��ڶ������������е�λ�ã�
	  �ӵ�ǰ���ڵ�pur��ʼ���ң���pcur��Ϊ�յ�ʱ��
	  ����ǰ���ڵ�data>����data��������������
	  ����ǰ���ڵ�data<����data��������������
	  ����ǰ���ڵ�data==����data�����ݴ��ڣ�����
	  �������ѭ��ʱ��pcur��λ�þ����½ڵ�Ҫ�����λ��*/
	bool Insert(const T& data)
	{
	//1.���Ҳ���λ��
		//����
		if (nullptr == _proot)
		{
			_proot = new Node(data);
			return true;
		}

		//�ǿ���
		Node* pcur = _proot;
		Node* parent = nullptr;//ѭ������ʱ��pcur�ҵ���λ���ǿյģ�������Ҫһ��parent������ѭ��������¼������λ�õĸ��ڵ�
		while (pcur)
		{
			parent = pcur;//����parent
			if (pcur->_data > data)
			{
				pcur = pcur->_pleft;
			}
			else if (pcur->_data < data)
			{
				pcur = pcur->_pright;
			}
			else
			{
				return false;
			}
		}
		
	//2.�����½ڵ�
		pcur = new Node(data);
		if (parent->_data > data)
		{
			parent->_pleft = pcur;
		}
		else
		{
			parent->_pright = pcur;
		}
		return true;
	}

	//3.ɾ���ڵ�
	//��������1.����ɾ���ڵ�λ��  2.ɾ���ýڵ�
	bool Delete(const T& data)
	{
		//����
		if (nullptr == _proot)
		{
			return false;
		}

		//�ǿ���
		//1.����λ��
		Node* pcur = _proot;
		Node* parent = nullptr;
		while (pcur)
		{
			if (pcur->_data == data)
			{
				break;
			}
			else if (pcur->_data > data)
			{
				parent = pcur;
				pcur = pcur->_pleft;
			}
			else
			{
				parent = pcur;
				pcur = pcur->_pright;
			}
		}
		if (pcur == nullptr)
			return false;

		//2.ɾ���ڵ�
		//���������
		/*a.ɾ���ڵ��޺��ӽڵ���������
		  b.ɾ���ڵ����Һ���
		  c.ɾ���ڵ����Һ��Ӷ���
		*/
		//a.ɾ���ڵ��޺��ӽڵ���������
		Node* pdelNode = pcur;
		if (nullptr == pcur->_pleft)
		{
			//���ڵ�
			if (nullptr == parent)
			{
				_proot = parent->_pright;
			}
			//�Ǹ��ڵ�
			else
			{
				//ɾ���ڵ��Ǹ��ڵ����ڵ�
				if (pcur == parent->_pleft)
				{
					parent->_pleft = pcur->_pright;
				}
				//ɾ���ڵ��Ǹ��ڵ���ҽڵ�
				else
				{
					parent->_pright = pcur->_pright;
				}
			}
		}
		//b.ɾ���ڵ����Һ���,ֻ������
		else if (nullptr == pcur->_pright)
		{
			//���ڵ�
			if (nullptr == parent)
			{
				parent = parent->_pleft;
			}
			//�Ǹ��ڵ�
			else
			{
				//ɾ���ڵ��Ǹ��ڵ����ڵ�
				if (pcur == parent->_pleft)
				{
					parent->_pleft = pcur->_pleft;
				}
				//ɾ���ڵ��Ǹ��ڵ���ҽڵ�
				else
				{
					parent->_pright = pcur->_pleft;
				}
			}
		}
		//c.ɾ���ڵ����Һ��Ӷ���
		//��pCur������������һ������ڵ�-->һ���������������Ľڵ�(���Ҳ�ڵ�)
		//��������������С�������
		//������ڵ��е����ݸ�ֵ����ɾ���ڵ㣬Ȼ��ɾ������ڵ�
		else
		{
			Node* pdel = pcur->_pleft;
			parent = pcur;
			while (pdel->_pright)
			{
				parent = pdel;
				pdel = pdel->_pright;
			}
			pcur->_data = pdel->_data;

			//ɾ������ڵ�
			//����ڵ��Ǹ��ڵ����ڵ�
			if (parent->_pleft == pdel)
			{
				parent->_pleft = pdel->_pleft;
			}
			//����ڵ��Ǹ��ڵ���ҽڵ�
			else
			{
				parent->_pright = pdel->_pleft;
			}
			pdelNode = pdel;
		}
		delete pdelNode;
		return true;
	}

	//������Ԫ��
	Node* MostLeft()
	{
		if (nullptr == _proot)
		{
			return nullptr;
		}
		Node* pcur = _proot;
		while (pcur->_pleft)
		{
			pcur = pcur->_pleft;
		}
		return pcur;
	}
	//������Ԫ��
	Node* MostRight()
	{
		if (nullptr == _proot)
		{
			return nullptr;
		}
		Node* pcur = _proot;
		while (pcur->_pright)
		{
			pcur = pcur->_pright;
		}
		return pcur;
	}
	//�������
	void Inorder()//���ýӿڷ�װ����������
	{
		_Inorder(_proot);
	}
private:
	void _Inorder(Node* proot)
	{
		if (proot)
		{
			_Inorder(proot->_pleft);
			cout << proot->_data << " ";
			_Inorder(proot->_pright);
		}
	}
private:
	Node* _proot;//���ڵ�
};


//����������Ӧ��
//kģ�ͣ����ĳ�������Ƿ�ƴд��ȷ�����ڵ��ֵ������ȷ���ʣ��õ��������в��ң��ҵ�����ȷ���Ҳ��������
//k-vģ�ͣ��ļ��а����˶��ip��ַ ��֪��ÿ��ip��ַ���ֵĴ���  <ip������>
template<class K, class V>
struct BSTNode
{
	BSTNode(const K& key, const V& value)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _key(key)
		, _value(value)
	{}

	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	K _key;
	V _value;
};

template<class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;

public:
	BSTree()
		: _pRoot(nullptr)
	{}

	// 
	Node* Find(const K& key)
	{
		Node* pCur = _pRoot;
		while (pCur)
		{
			if (key == pCur->_key)
				return pCur;
			else if (key < pCur->_key)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}

		return nullptr;
	}

	bool Insert(const K& key, const V& value)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(key, value);
			return true;
		}

		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (key < pCur->_key)
				pCur = pCur->_pLeft;
			else if (key > pCur->_key)
				pCur = pCur->_pRight;
			else
				return true;
		}

		pCur = new Node(key, value);
		if (key < pParent->_key)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;

		return true;
	}
private:
	Node* _pRoot;
};


//����������ȱ�ݣ�����ʱ�临�Ӷ�O(N),
//����ڹ�������������ڼ䣬��������������߽ӽ��������˻�Ϊ��֧��
//��������������˻�Ϊ��֧�����������ʧȥƽ��