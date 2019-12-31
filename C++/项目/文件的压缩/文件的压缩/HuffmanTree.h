#pragma once

/*����huffman����
1.��ÿ��ȨֵΪ�ڵ㴴��N�ö�����ɭ��
2.���������ɭ���г�����������
   a.�Ӷ�����ɭ����ȡ�� ���ڵ�Ȩֵ��С �����Ŷ�������1.����--Ч�ʵͣ�2.���ȼ�����--���öѵķ�ʽ���д���
   b.�Ը����ö�������Ϊ ĳ���ڵ��������������һ���µĶ��������Ҹýڵ�ȨֵΪ���ҽڵ��Ȩֵ֮��
   c.���´����Ķ��������뵽ɭ����
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//�ڵ�ṹ��
template<class T>
struct HuffmanTreeNode
{
	HuffmanTreeNode(const const T& data=T())
		:_data(data)
		,_pLeft(nullptr)
		,_pRight(nullptr)
	{}
	HuffmanTreeNode<T>* _pLeft;
	HuffmanTreeNode<T>* _pRight;
	HuffmanTreeNode<T>* _pParent;
	T _data;//�ڵ�Ȩֵ
};

//���ȼ�����Ĭ���Ǵ��,����������Ҫ����С���ѣ�������Ҫ�¶���һ���ȽϷ�ʽ����С��
template<class T>
class Less
{
	typedef HuffmanTreeNode<T> Node;
public:
	bool operator()(const Node* pLeft, const Node* pRight)
	{
		return pLeft->_data > pRight->_data;
	}
};
//����������
template<class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> Node;
public:
	//���ֹ��췽��������
	HuffmanTree()
		:_pRoot(nullptr)
	{}

	HuffmanTree(const vector<T>& vdata)
	{
		CreateHuffmanTree(vdata);
	}


	~HuffmanTree()
	{
		_DestroyTree(_pRoot);
	}
	//������������
	void CreateHuffmanTree(const vector<T>& vdata)
	{
		//1.����ɭ��:��ÿ���ڵ���뵽���ȼ������У����ѵķ�ʽ���Ѿ��Զ�����,�Žڵ�ĵ�ַ
		//priority_queue<Node*> q;
		priority_queue<Node*, vector<Node*>, Less<T>> q;
		for (auto e : vdata)
		{
			q.push(new Node(e));
		}

		//2.��ɭ���������Ż򳬹�������
		while (q.size() > 1)
		{
			//ȡ���Ž�С����
			Node* pLeft = q.top();
			q.pop();
			Node* pRight = q.top();
			q.pop();
			//�õ��½ڵ�
			Node* pParent = new Node(pLeft->_data + pRight->_data);
			pParent->_pLeft = pLeft;
			pParent->_pRight = pRight;
			//������������ɭ��
			q.push(pParent);
		}
		//ѭ���˳�ʱ����ʱ��ʣ�������ǹ�������
		_pRoot = q.top();
	}

	//���ٹ�������
private:
	void _DestroyTree(Node*& pRoot)
	{
		if(pRoot)
		{
			_DestroyTree(pRoot->_pLeft);
			_DestroyTree(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	Node* _pRoot;
};

void TestHuffmanTree()
{
	vector<int> v{ 3,1,7,5 };
	HuffmanTree<int> t;
	t.CreateHuffmanTree(v);
	// �����д��
	/*HuffmanTree<int> t(v);*/
}
