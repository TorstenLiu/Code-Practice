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

//��ȡ�ַ��Ĺ���������
void FileCompressHuff::GetHuffmanCode(HuffmanTreeNode<CharInfo>* pRoot)
{
	if (nullptr == pRoot)
	{
		return;
	}
	GetHuffmanCode(pRoot->_pLeft);
	GetHuffmanCode(pRoot->_pRight);

	//����Ҷ�ӽڵ㴦--���ҽڵ�Ϊ��
	if (nullptr == pRoot->_pLeft&&pRoot->_pRight)
	{
		/*�����ߣ��������һ������codeΪ0��Ϊ����Ϊ1������Ϊ���ҵ���һ���ڵ㣬�ڽڵ�ṹ�����pParentָ��*/

		//�ӵ�ǰҶ�ӽڵ�λ�ÿ�ʼ
		HuffmanTreeNode<CharInfo>* pCur = pRoot;
		HuffmanTreeNode<CharInfo>* pParent = pRoot->_pParent;
		string& strCode= pCur->_data._strCode;
		vector<CharInfo> fileInfo = FileCompressHuff::GetfileInfo();
		//vector<CharInfo> fileInfo;
		while (pParent)
		{
			if (pCur == pParent->_pLeft)//��ǰ�ڵ�Ϊ��һ������
			{
				strCode += '0';
			}
			else//��ǰ�ڵ�Ϊ��һ������
			{
				strCode += '1';
			}

			//����pCur��pParent��ֵ
			pCur = pParent;
			pParent = pCur->_pParent;
		}
		reverse(strCode.begin(), strCode.end());
		fileInfo[pRoot->_data._ch]._strCode = strCode;//�±��ӦԪ�ص� _strCode
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
		//��ȡ�ļ�
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
	HuffmanTree<CharInfo> t(_fileInfo, CharInfo(0));//���ڵ��е�Ȩֵ�ǽṹ��CharInfo���͵�  CharInfo(0)--���ѳ��ִ���Ϊ0���ַ���������
	//3.��ȡÿ���ַ��ı���
	

	//4.���ջ�ȡ�����ַ��������¸�дԴ�ļ�

	delete[] ReadBuff;
	fclose(fin);
}