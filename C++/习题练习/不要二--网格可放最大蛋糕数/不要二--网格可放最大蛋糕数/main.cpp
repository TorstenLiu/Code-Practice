#define _CRT_SECURE_NO_WARNINGS 1

/*���ӣ�https://www.nowcoder.com/questionTerminal/1183548cd48446b38da501e58d5944eb
��Դ��ţ����

����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
����������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������*/
#include<iostream>
using namespace std;

int a[1000][1000];

int main()
{
	int row, col,res = 0;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] == 0)
			{
				res++;
				if ((i + 2) < row)
				{
					a[i + 2][j] = -1;
				}
				if ((j + 2) < col)
				{
					a[i][j + 2] = -1;
				}
			}
		}
	}
	cout << res << endl;
	system("pause");
	return 0;
}