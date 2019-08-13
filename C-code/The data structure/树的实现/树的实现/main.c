#define _CRT_SECURE_NO_WARNINGS 1

#include"BTree.h"

int main()
{
	BTNode* mytree = BinaryTreeCreate("ABD##E#H##CF##G##");//ǰ��+#ȷ��һ��Ψһ�Ķ�����

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

	printf("\n");
	printf("ǰ��ǵݹ�\n");
	BinaryTreePrevOrderNonR(mytree);
	printf("\n");
	printf("����ǵݹ�\n");
	BinaryTreeInOrderNonR(mytree);
	printf("\n");
	printf("����ǵݹ�\n");
	BinaryTreePostOrderNonR(mytree);

	printf("\n");
	printf("�ж��Ƿ�����ȫ������:\n");
	int result= BinaryTreeComplete(mytree);
	printf("%d", result);
	system("pause");

	return 0;
}