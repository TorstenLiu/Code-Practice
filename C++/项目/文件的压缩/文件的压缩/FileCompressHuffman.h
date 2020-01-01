#pragma once

#include<string>
#include<vector>
using namespace std;
#include"HuffmanTree.h"

//�ַ��ṹ��
struct CharInfo
{
	char _ch;//�����ַ�
	size_t _count;//�ַ����ֵĴ���
	string _strCode;//�ַ��ı���

	CharInfo(size_t count = 0)
		:_count(count)
	{}

	CharInfo operator+(const CharInfo& value)
	{
		return CharInfo(_count + value._count);
	}

	bool operator>(const CharInfo& value)const//ע�����const����������thisָ���ָ��--�����������
	{
		return _count > value._count;
	}

	bool operator==(const CharInfo& value)
	{
		return _count == value._count;
	}
};

//�ļ�ѹ����
class FileCompressHuff
{
public:
	FileCompressHuff();
	//ѹ��
	void CompressFile(const string& path);

	//��ѹ��
	void UnCompressFile(const string& path);

public:
	vector<CharInfo> GetfileInfo()
	{
		return _fileInfo;
	}
		
//��ȡ�ַ��Ĺ���������
private:
	void GetHuffmanCode(HuffmanTreeNode<CharInfo>* pRoot);

private:
	vector<CharInfo> _fileInfo;//ͳ���ַ����ִ��������飬��������������Ҫ��Žṹ�壬������Ҫ����vector����
};
