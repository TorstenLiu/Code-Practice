#define _CRT_SECURE_NO_WARNINGS 1


/*ѹ����
1.ͳ��ÿ���ַ����ֵĴ��� ---FileCompressHuffman.h
2.����huffman��---HuffmanTree.h
3.��ȡ�ַ��ı���
4.��ÿ���ַ��ı������¸�дԴ�ļ�*/

#include"HuffmanTree.h"
#include"FileCompressHuffman.h"

int main()
{
	//TestHuffmanTree();
	FileCompressHuff fc;
	fc.CompressFile("test.txt");
	system("pause");
	return 0;
}