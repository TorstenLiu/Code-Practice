#define _CRT_SECURE_NO_WARNINGS 1

/*���ӣ�https://www.nowcoder.com/questionTerminal/30c1674ad5694b3f8f0bc2de6f005490?toCommentId=145988
��Դ��ţ����

������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ,���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ��

����������int n��int m��ͬʱ����int j��int i�����������������뷵�ز������������֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i-j+1��

����������
1024��19��2��6
���أ�1100*/

#include<iostream>
using namespace std;

int GetBinInsert(int n, int m, int j, int i)
{
	m <<= j;
	return n | m;
}
int main()
{
	int m, n, j, i = 0;
	cin >> n >> m >> j >> i;
	cout << GetBinInsert(n, m, j, i) << endl;
	system("pause");
	return 0;
}