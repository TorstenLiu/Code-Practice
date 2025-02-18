#define _CRT_SECURE_NO_WARNINGS 1
/*链接：https://www.nowcoder.com/questionTerminal/d290db02bacc4c40965ac31d16b1c3eb
来源：牛客网

扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A、2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）：
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如：4 4 4 4-joker JOKER。
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
基本规则：
（1）输入每手牌可能是个子、对子、顺子（连续5张）、三个、炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）；
（3）大小规则跟大家平时了解的常见规则相同，个子、对子、三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。


输入描述:
输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如 4 4 4 4-joker JOKER。

输出描述:
输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。

示例1
输入
4 4 4 4-joker JOKER
输出
joker JOKER*/
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

int main()
{
	string s;
	getline(cin,s);
	string sort = "345678910JQKA2jokerJOKER";//方便后面通过下标比较牌的大小，不然以字符形式比较会出错
	//如果有王炸，直接输出
	if (s.find("joker JOKER") != string::npos)
	{
		cout << "joker JOKER" << endl;
	}
	else
	{
		//分为两手牌
		int pos = s.find('-');
		string s1 = s.substr(0, pos);
		string s2 = s.substr(pos + 1);
		//通过空格数分别获得牌数
		int num1 = count(s1.begin(), s1.end(), ' ') + 1;
		int num2 = count(s2.begin(), s2.end(), ' ') + 1;
		   //如果牌数相同，获得两手牌的第一张，
		if (num1 == num2)
		{
			string first = s1.substr(0, s1.find(' '));
			string second = s2.substr(0, s2.find(' '));
			//比较，如果第一手牌的第一张大 则返回第一手牌
			if (sort.find(first) > sort.find(second))
			{
				cout << s1 << endl;
			}
			//否则 第二手
			else
			{
				cout << s2 << endl;
			}
		}
		//如果牌数不相同，说明类型不同，只有炸弹可以和其他牌比较
		else
		{
			//如果两手牌中有一手牌牌数为4，说明有炸弹(且已经在前面判断过不是王炸)，直接输出这一手牌
			if (num1 == 4)
			{
				cout << s1 << endl;
			}
			else if (num2 == 4)
			{
				cout << s2 << endl;
			}
			//如果不存在炸弹，则输出error
			else
			{
				cout << "ERROR" << endl;
			}
		}
	}
	system("pause");
	return 0;
}