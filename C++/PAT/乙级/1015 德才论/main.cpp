宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：

输入第一行给出 3 个正整数，分别为：N（≤10^5），即考生总数；L（≥60），为录取最低分数线，即德分和才分均不低于 L 的考生才有资格被考虑录取；H（<100），
为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，
但排在第一类考生之后；德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。

随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，其中准考证号为 8 位整数，德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

输出格式：

输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：

14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60


输出样例：

12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
  
  
  
#include<iostream>
using namespace std;
#include<vector>
#include <fstream> 
#include<algorithm>

typedef struct Student
{
	int number;
	int deScore;
	int caiScore;
}st;

bool compare(st s1, st s2)
{
	//总分相同,德分降序排列
	if (s1.caiScore + s1.deScore == s2.caiScore + s2.deScore)
	{
		//德分相同
		if (s1.deScore == s2.deScore)
		{
			return s1.number < s2.number;
		}
		else
		{
			return s1.deScore > s2.deScore;
		}
	}
	else
	{
		return s1.caiScore + s1.deScore > s2.caiScore + s2.deScore;
	}

}

int main()
{
	int N = 0, L = 0, H = 0;
	cin >> N >> L >> H;
	vector<st> v(N);
	ifstream in("data.txt", ios::in);
	if (!in.is_open())
	{
		cout << "open error!" << endl;
		exit(0);
	}
	int i = 0;
	while(!in.eof() && i < N)
	{
		in >> v[i].number >> v[i].deScore >> v[i].caiScore;
		i++;
	}

	int  M = 0;//达到最低分数线的考生人数
	vector<st> v1;//德才全尽
	vector<st> v2;//德胜才
	vector<st> v3;//才德兼亡但德胜才 
	vector<st> v4;//其他达到最低线 L
	for (int i = 0; i < N; i++)
	{
		if ((v[i].caiScore >= L) && (v[i].deScore >= L))
		{
			M++;
			if ((v[i].caiScore >= H) && (v[i].deScore >= H))//德才全尽
			{
				v1.push_back(v[i]);
			}
			else if ((v[i].caiScore < H) && (v[i].deScore >= H))//德胜才
			{
				v2.push_back(v[i]);
			}
			else if ((v[i].caiScore < H) && (v[i].deScore < H)&&(v[i].deScore>v[i].caiScore))//才德兼亡但德胜才 
			{
				v3.push_back(v[i]);
			}
			else //其他达到最低线 L
			{
				v4.push_back(v[i]);
			}
		}
	}
	cout << M << endl;
	sort(v1.begin(), v1.end(), compare);
	sort(v2.begin(), v2.end(), compare);
	sort(v3.begin(), v3.end(), compare);
	sort(v4.begin(), v4.end(), compare);
	for (int i = 0; i < v1.size(); i++)
	{
		//cout << "v1";
		cout << v1[i].number << " " << v1[i].deScore << " " << v1[i].caiScore << endl;
	}
	for (int i = 0; i < v2.size(); i++)
	{
		//cout << "v2";
		cout << v2[i].number << " " << v2[i].deScore << " " << v2[i].caiScore << endl;
	}
	for (int i = 0; i < v3.size(); i++)
	{
		//cout << "v3";
		cout << v3[i].number << " " << v3[i].deScore << " " << v3[i].caiScore << endl;
	}

	for (int i = 0; i < v4.size(); i++)
	{
		//cout << "v4";
		cout << v4[i].number << " " << v4[i].deScore << " " << v4[i].caiScore << endl;
	}

	in.close();
	system("pause");
	return 0;
}
