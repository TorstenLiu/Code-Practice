#define _CRT_SECURE_NO_WARNINGS 1

#include"BTree.h"

int main()
{
	BTNode* mytree = BinaryTreeCreate("ABD##E#H##CF##G##");

	printf("ǰ��\n");
	BinaryTreePrevOrder(mytree);
	printf("\n");
	printf("����\n");
	BinaryTreeInOrder(mytree);
	printf("\n");
	printf("����\n");
	BinaryTreePostOrder(mytree);

	printf("\n");
	printf("����\n");
	BinaryTreeLevelOrder(mytree);
	system("pause");
	return 0;
}