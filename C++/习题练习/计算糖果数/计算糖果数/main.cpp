#define _CRT_SECURE_NO_WARNINGS 1

/*���ӣ�https://www.nowcoder.com/questionTerminal/02d8d42b197646a5bbd0a98785bb3a34
��Դ��ţ����

A,B,C�������Ǻ�����,ÿ�������ﶼ��һЩ�ǹ�,���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�,��������֪�����µ���Ϣ��
A - B, B - C, A + B, B + C. ���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�,��A,B,C�����ﱣ֤���ֻ��һ������A,B,C������������������*/
#include<iostream>
using namespace std;
#include<algorithm>


int main()
{
	int num1, num2, num3, num4 = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	cin >> num1 >> num2 >> num3 >> num4;
	a = num1 + num3;//2A
	b = num2 + num4;//2B
	c = num4 - num2;//2C
	if (a - b == 2 * num1)
	{
		if (b - c == 2 * num2)
		{
			if (a + b == 2 * num3)
			{
				if (b + c == 2 * num4)
				{
					if ((a % 2 == 0) && (b % 2 == 0) && (c % 2 == 0))
					{
						cout << a / 2 << " " << b / 2 << " " << c / 2 << " " << endl;
					}
					else
					{
						cout << "No" << endl;
					}
				}
			}
		}
	}
	else
	{
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}