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
