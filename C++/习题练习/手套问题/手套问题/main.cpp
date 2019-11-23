#define _CRT_SECURE_NO_WARNINGS 1

/*���ӣ�https://www.nowcoder.com/questionTerminal/365d5722fff640a0b6684391153e58d8?pos=2&orderByHotValue=0&done=0
��Դ��ţ����

�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��A��������Ҫ���ţ�������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡������������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�

������ɫ����n(1��n��13),ͬʱ������������Ϊn������left,right,�ֱ����ÿ����ɫ���������׵����������ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������

����������
4,[0,7,1,6],[1,5,0,6]
���أ�10(���ͣ�������������ȡ2ֻ����������ȡ8ֻ)*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int leftmin = INT_MAX;
		int rightmin = INT_MAX;
		int leftsum = 0;
		int rightsum = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			//// ��߻����ұ�û�е�ʱ����Ҫȫ������
			if (left[i] * right[i] == 0)
			{
				sum += left[i] + right[i];
			}
			// �ҵ���ߺ��ұ߷ֱ����ٵ���ɫ�������������ܺ�
			else
			{
				leftsum += left[i];
				rightsum += right[i];
				leftmin = min(left[i], leftmin);
				rightmin = min(right[i], rightmin);
			}
		}
		// �ҵ���ߺ��ұ��н�С��ֵ������һ��ֱ����һ��
		return sum + min(leftsum - leftmin + 1, rightsum - rightmin + 1) + 1;
	}
};
int main()
{
	Gloves g;
	int options = 0;
	cin >> options;
	vector<int> left(options);
	for (int i = 0; i < left.size(); i++)
	{
		cin >> left[i];
	}
	vector<int> right(options);
	for (int j = 0; j < right.size(); j++)
	{
		cin >> right[j];
	}
	cout << g.findMinimum(options, left, right);
	system("pause");
	return 0;
}