#define _CRT_SECURE_NO_WARNINGS 1
/*���ӣ�https://www.nowcoder.com/questionTerminal/4b1658fd8ffb4217bc3b7e85a38cfaf2
��Դ��ţ����

��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
    
����: һ��byte�͵�����
    
���: ��
     
����: ��Ӧ�Ķ�����������1�����������*/
#include<iostream>
using namespace std;
#include<string>

int main()
{
	int num = 0;
	while (cin >> num)
	{
		int count = 0;
		int maxcount = 0;
		while (num)
		{
			if (num & 1)
			{
				while (num & 1)
				{
					count++;
					num >>= 1;
				}
				if (count > maxcount)
				{
					maxcount = count;
				}
			}
			num >>= 1;
			count = 0;
		}
		cout << maxcount << endl;
	}
	system("pause");
	return 0;
}