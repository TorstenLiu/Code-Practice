#pragma once

#include<string>
using namespace std;

//�ַ��ṹ��
struct CharInfo
{
	char _ch;//�����ַ�
	size_t _count;//�ַ����ֵĴ���
	string _strCode;//�ַ��ı���
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

private:
	vector<CharInfo> _fileInfo;//ͳ���ַ����ִ���������
};
