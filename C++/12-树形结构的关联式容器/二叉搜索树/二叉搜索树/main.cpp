#define _CRT_SECURE_NO_WARNINGS 1

#include"BSTree.h"

void TestBSTree()
{
	BSTree<int> tree;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (auto e : arr)
	{
		tree.Insert(e);
	}
	//1.������������Ƿ�����������
	tree.Inorder();
	cout << endl;

	//2.��ɾ��
	tree.Delete(3);
	tree.Inorder();
	cout << endl;

	//3.���������Ԫ��
	cout << tree.MostLeft()->_data << endl;
	cout << tree.MostRight()->_data << endl;
}
int main()
{
	TestBSTree();
	system("pause");
	return 0;
}