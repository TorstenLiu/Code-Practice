#define _CRT_SECURE_NO_WARNINGS 1


/*������������ڣ���������һ��ĵڼ��졣��
��ϸ������
����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��
���ӣ�https://www.nowcoder.com/questionTerminal/769d45d455fe40b385ba32f97e7bcded
��Դ��ţ����

��������:
�������У��ֱ����꣬�£���

�������:
�ɹ�:����outDay��������ĵڼ���;   ʧ��:����-1
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Get(int year, int month, int day)
{
	vector<int> days{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;
	int i = 0;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		days[1] = 29;
	}
	while (month-1)
	{
		sum += days[i];
		i++;
		month--;
	}
	sum += day;
	return sum;
}
int main()
{
	int year = 0;
	int month = 0;
	int day = 0;
	while (cin >> year >> month >> day)
	{
		cout << Get(year, month, day) << endl;
	}

	system("pause");
	return 0;
}