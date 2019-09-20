#define _CRT_SECURE_NO_WARNINGS 1

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)//���캯��
		:_year(year)
		, _month(month)
		, _day(day)
	{
		//�ڹ��캯�������ж�������ʼ�����Ƿ�Ϸ�

	}
	
	Date(const Date& d);//�������캯��
	Date& operator=(const Date& d);//=����
	Date operator+(int days);//+���أ����㵱ǰ��ĵڶ������
	Date operator-(int days);//���㵱ǰ��ĵڶ�����ǰ
	int operator-(const Date& d);//��������������������
	Date& operator++();//ǰ��++
	Date& operator++(int);//����++
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
private:
	int _year;
	int _month;
	int _day;
};