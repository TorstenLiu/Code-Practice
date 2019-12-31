#define _CRT_SECURE_NO_WARNINGS 1

#include"FileCompressHuffman.h"
#include<assert.h>
#include"HuffmanTree.h"

//���캯��
FileCompressHuff::FileCompressHuff()
{
	_fileInfo.resize(256);
	//��ʼ�����飬һ���±�����ַ�acsֵ������
	for (int i = 0; i < 256; i++)
	{
		_fileInfo[i]._ch = i;
		_fileInfo[i]._count = 0;
	}
}

void FileCompressHuff::CompressFile(const string& path)
{
	//1.ͳ��ԭ�ļ���ÿ���ַ����ֵĴ���
	   //���ļ�
	FILE* fin = fopen(path.c_str(),"r");
	if (nullptr == fin)
	{
		assert(false);
		return;
	}
	char * ReadBuff = new char[1024];
	int rdSize = 0;
	while (true)
	{
		rdSize = fread(ReadBuff, 1, 1024, fin);//��������ֵΪ�����˶��ٸ��ֽ�
		if (0 == rdSize)//��ȡ�ļ�����
		{
			break;
		}
		for (int i = 0; i < rdSize; i++)//��ʵ�ʶ����ֽ�������ͳ��
		{
			_fileInfo[ReadBuff[i]]._count++;
		}
	}

	//2.���ַ����ֵĴ���ΪȨֵ����һ�Ź�������
	HuffmanTree<CharInfo> t(_fileInfo);
	//3.��ȡÿ���ַ��ı���


	//4.���ջ�ȡ�����ַ��������¸�дԴ�ļ�

	delete[] ReadBuff;
	fclose(fin);
}
