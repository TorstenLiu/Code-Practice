#define _CRT_SECURE_NO_WARNINGS 1


//��Ŀ����
/*��һ����ά�����У�ÿ��һά����ĳ�����ͬ����
ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������*/
#include<iostream>
using namespace std;
#include<vector>

class Solution
{
public:
	bool Find(int target, vector<vector<int>> array)
	{
		//ע��һ��Ҫ���пգ�����array��size
		if (array.empty())
		{
			return false;
		}
		int len = array.size();
		//int lensize = array[0].size();
		for (size_t i = 0; i < len; i++)
		{
			if (array[i].empty())
			{
				continue;
			}
			if (target == array[i][0])
			{
				return true;
			}
			if (target > array[i][0])
			{
				if (target <= array[i][array[i].size() - 1])
				{
					for (size_t j = 0; j < array[i].size(); j++)
					{
						if (target == array[i][j])
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}
};
int main()
{
	vector<vector<int>> v{ {10,20,30},{11,22,33},{100},{200},{300},{120,220,330} };
	Solution s;
	if (s.Find(100, v))
	{
		cout << "find it" << endl;
	}
	else
	{
		cout << "can't find" << endl;
	}
	system("pause");
	return 0;
}