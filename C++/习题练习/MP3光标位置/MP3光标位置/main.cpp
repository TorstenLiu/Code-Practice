#define _CRT_SECURE_NO_WARNINGS 1

/*��Ŀ������ https://blog.csdn.net/lyl194458/article/details/91545168*/
#include <iostream>
using namespace std;
#include<string>

int main()
{
	int number;//��������
	while (cin >> number)
	{
		string s;//�����ַ���
		cin >> s;
		int top = 0;//���浱ǰ�б�������
		int button = 0;//���浱ǰ�б�ײ�����
		int now = 1;//���浱ǰ���ָ�������

		//�������С��=4
		if (number <= 4)
		{
			//��ʼ������������now����ָ���һλ
			top = 1;
			button = number;
			int i = 0;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == 'U')
				{
					if (now == 1)
					{
						now = button;
					}
					else
					{
						now--;
					}
				}
				else if (s[i] == 'D')
				{
					if (now == button)
					{
						now = 1;
					}
					else
					{
						now++;
					}
				}
			}
		}
		else//����������4   ʵ���Ͼ��ǹ��now��1�͹��now��topλ��Ҫ���������
		{
			top = 1;
			now = 1;
			button = 4;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == 'U')
				{
					if (now == 1)
					{
						now = number;
						button = number;
						top = number - 3;
					}
					else if (now == top)
					{
						now--;
						top--;
						button--;
					}
					else
					{
						now--;
					}
				}
				else if (s[i] == 'D')
				{
					if (now == number)
					{
						now = 1;
						top = 1;
						button = now + 3;
					}
					else if (now == button)
					{
						now++;
						top++;
						button++;
					}
					else
					{
						now++;
					}
				}
			}
		}
		//����б�
		for (int i = top; i < button; i++)
		{
			cout << i << " ";
		}
		cout << button << endl;
		cout << now << endl;
	}
	return 0;
}
