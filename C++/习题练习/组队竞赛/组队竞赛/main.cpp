#define _CRT_SECURE_NO_WARNINGS 1
/*���ӣ�https://www.nowcoder.com/questionTerminal/248ccf8b479c49a98790db17251e39bb
��Դ��ţ����

ţţ�ٰ���һ�α�̱���,�μӱ�������3*n��ѡ��,ÿ��ѡ�ֶ���һ��ˮƽֵa_i.����Ҫ����Щѡ�ֽ������,һ�����n������,��ÿ������3��.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
����:
һ������������Ա��ˮƽֵ�ֱ���3,3,3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���3,2,3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���1,5,2.��ô�����ˮƽֵ��2
Ϊ���ñ������п���,ţţ�밲�Ŷ���ʹ���ж����ˮƽֵ�ܺ����
��������ʾ:
���ţţ��6����Ա���ֵ���������
�������Ϊ:
team1:{1,2,5}, team2:{5,5,8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
���������Ϊ:
team1:{2,5,8}, team2:{1,5,5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.
û�б��ܺ�Ϊ10����ķ���,�������10.*/
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

long GetMax(int group, vector<int> v)
{
	long max = 0;
	sort(v.begin(), v.end());

	for (int i = group; i <= 3 * group - 2; i += 2)
	{
		max += v[i];
	}
	return max;
}
int main()
{
	int group = 0;
	cin >> group;
	vector<int> v(3 * group);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	cout << GetMax(group, v) << endl;
	system("pause");
	return 0;
}