#pragma once

#include<iostream>
using namespace std;

//�ڵ���
template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data=T())//TΪ��������--0   TΪ�Զ�������--��������ṩ�޲ι��캯��
		:_pleft(nullptr)
		,_pright(nullptr)
		,_pparent(nullptr)
		��_data(data)
		,_bf(0)
	{}

	AVLTreeNode<T>* _pleft;
	AVLTreeNode<T>* _pright;
	AVLTreeNode<T>* _pparent;
	T _data;
	int _bf;//ƽ������
};

//ƽ���������
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_proot(nullptr)
	{}
	bool Insert(const T& data)
	{
	//����
		if (nullptr == _proot)
		{
			_proot = new Node(data);
		}
	//�ǿ��� ���ն�����������ʽ����
		 //1.����
		Node* pcur = _proot;
		Node* parent = nullptr;
		while (pcur)
		{
			parent = pcur;
			if (data < pcur->_data)
			{
				pcur = pcur->_pleft;
			}
			else if (data > pcur->_data)
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
		if (data < parent->_data)
		{
			parent->_pleft = pcur;
		}
		else
		{
			parent->_pright = pcur;
		}
		pcur->_pparent = parent;
		//3.����parent��ƽ������
		//����ǰ�����������
		/*1.Ҷ�ӽڵ�---pcur���Բ���parent���������Ҳ�--ƽ�����ӣ�����1  ���ϲ�����Ӱ��
		2.ֻ������---ocurֻ�ܲ���parent���Ҳ�-----ƽ�����ӣ�0
		3.ֻ���Һ���---pcurֻ�ܲ���parent�����----ƽ�����ӣ�0     2.��3���ϲ�û��Ӱ��*/


		while ()
		{
			// ��Ϊparent���ӣ�ƽ������--
			if (pcur == parent->_pleft)
			{
				parent->_bf--;
			}
			//��Ϊparent�Һ��ӣ�ƽ������++
			else
			{
				parent->_bf++;
			}


			if (0 == parent->_bf)
			{
				return;
			}
			else if (-1 == parent->_bf || 1 == parent->_bf)//���ϸ���
			{
				pcur = parent;
				parent = pcur->_pparent;
			}
			else
			{
				//���ڵ��ƽ������Ϊ2��-2:AVL���������⵽�ƻ������Ѿ���ƽ��
				//�������parentΪ���Ķ�����������ת����

			}
		}
	}
private:
	Node* _proot;
};