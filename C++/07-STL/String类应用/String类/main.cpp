#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//1.String�����ĳ�������
void Test1()
{
	string s1;//����յ�string����󣬼����ַ���
	string s2("hello");//��C-String������string�����
	string s3(10, '*');//��10��*�ַ�������string�����
	string s4(s2);//��������
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

//2.string��������������
void Test2()
{
	string s("change world");
	//2.1���ַ�����Ч�ַ����ȺͿռ��ܴ�С
	cout << s.size() << endl;//size()��length()ʵ����ȫ��ͬ��size()�õĸ���
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	//2.2����ַ����Ƿ�Ϊ�մ�
	if (s.empty())
	{
		cout << "NULL" << endl;
	}
	else
	{
		cout << s << endl;//string�����֧��ֱ����cin��cout������������
	}

	//2.3�����Ч�ַ���,���ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	if (s.empty())
	{
		cout << "NULL" << endl;
	}
	else
	{
		cout << s << endl;//��ʱ�ַ���Ϊ��
	}

	//2.4����Ч�ַ��ĸ����ó�n��������ַ����ص�������Ŀռ����ַ�c���
	string s1("be successful");
	cout << s1 << endl;
	cout << s1.size() << endl;//13
	cout << s1.capacity() << endl;//15

	s1.resize(10, '!');
	cout << s1 << endl;//be success
	cout << s1.size() << endl;//10
	cout << s1.capacity() << endl;//15

	s1.resize(20,'*');//����Լ��������ַ���ȱʡֵΪ��\0��
	cout << s1 << endl;//be success*********����ԭ���Ļ����ϱ�
	cout << s1.size() << endl;//20
	cout << s1.capacity() << endl;//31

	s1.resize(6);
	cout << s1 << endl;//be suc
	cout << s1.size() << endl;//6
	cout << s1.capacity() << endl;//31

	/*�ܽ᣺1. ����ǽ�string���е���ЧԪ����С��ֻ�ı���ЧԪ�ظ���������ı�ײ�ռ��С
            2. ����ǽ�string���е���ЧԪ�����࣬������Ҫ���� */


	//2.5void reserve(size_t newcapacity): ����
	string s2(20, '*');
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//31

	s2.reserve(20);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//31

	s2.reserve(40);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//47

	s2.reserve(24);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//47

	s2.reserve(10);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//47

	s2.resize(6);
	s2.reserve(15);
	cout << s2.size() << endl;//6
	cout << s2.capacity() << endl;//15

  //�ܽ᣺ 
//newcapacity > oldcapacity(string��ɿռ��С)���ռ�����--->�����ı�(����������С >= newCapacity��vs�´�Լ��1.5�ı�������)
//newcapacity < oldcapacity(string��ɿռ��С)���ռ���С����size����capacity��ʼ����(15),��Ӱ������,��sizeС��15ʱ���ռ���С��<=15ʱ��capacity�Ż���15
//reserve���ֻ�ı�������С������ı���ЧԪ�ظ���

}

//3. ����reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���
//δ��reserve֮ǰ��
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');//��ͣ��β�壬�Զ�����
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
//��reserve֮��
//��Ϊ�Ѿ�Ԥ����100�Ŀռ䣬���Բ���������,sz������capacity�������һ��������Ҫ�ռ䳬��100���ͻ᲻ͣ������
void TestPushBackReserve()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "Capacity changed:" << sz << '\n' << endl;
		}
	}
}

//4.string�����ķ��ʼ�����

//4.1 ���ʷ�ʽ
//4.1.1 operator[] ��at()����posλ�õ��ַ���const string��������
void Test3()
{
	string s1("I love");
	const string s2("my country");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	s1.at(1) = 'h';
	cout << s1 << endl;
	//s2[0]='H'  ���� ����s2��const���Σ����ܱ��޸�

	//��������Խ��
	/*cout << s1[10] << endl;   ����Խ�磬assert����
	cout << s1.at(10) << endl;�׳�out_of_range�쳣*/
}
//4.1.2 begin+ end begin��ȡһ���ַ��ĵ����� + end��ȡ���һ���ַ���һ��λ�õĵ�
//4.1.3 rbegin + rend

//4.2 ������ʽ��
void Test4()
{
	string s("I am the best");
	//1.for+operator[]
	for (size_t i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	cout << '\n';
	//2.������
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		it++;
	}
	cout << '\n';
	//3.��Χfor
	for (auto e : s)
	{
		cout << e;
	}
	cout << '\n';
}

//5.string�������޸Ĳ���
//5.1 push_back��append��operator+=��c_str
void Test5()
{
	string s;
	s.push_back('z');//��s�������һ���ַ�zl
	s.append("ss");//��s����׷��һ���ַ�ss
	s += 'n';//��s����׷��һ���ַ�n
	s += "b!";//��s�����һ���ַ���"b��"
	cout << s << endl;

	string s2("I love");
	string s3(" pxy");
	s2 += s3;
	s2.append(3,'!');
	cout << s2 << endl;
	cout << s2.c_str() << endl;//��C���Եķ�ʽ��ӡ�ַ��� ����ֵΪconst char*
	cout << atoi(s2.c_str()) << endl;//atoi--���� ���ַ���ת���������� int atoi(const char *nptr)
}
//5.2 find+npos, rfind, substr,erase
void Test6()
{
	//find+npos ��ǰ������

	string s1("I love C++!");
	//����һ���ַ��������±�
	size_t pos = s1.find('C');
	if (pos != string::npos)//string �ཫ npos ����Ϊ��֤�����κ���Ч�±��ֵ
	{
		cout << 'C' << " is in s1 " << pos << endl;
	}
	else
	{
		cout << "not in" << endl;
	}
	//����һ���ַ�����������Ԫ���±�
	size_t pos2 = s1.find("love");
	if (pos2 != string::npos)
	{
		cout << "love" << " is in s1 " << pos2 << endl;
	}
	else
	{
		cout << "not in" << endl;
	}


	//rfind�Ӻ���ǰ��,substr��pos�����ȡn���ַ�������,������nʱ�������ַ�����β

	//��ȡ�ļ��ĺ�׺��
	string s2("main.cpp");
	size_t pos3 = s2.rfind('.') + 1;
	cout << s2.substr(pos3) << endl;
	cout << s2.substr(pos3, s2.size() - pos3) << endl;
	//ȡ��һ����վ������
	string s3("http://www.cplusplus.com/reference/string/string/find/");
	cout << s3 << endl;
	size_t start = s3.find("://");
	if (start == string::npos)
	{
		cout << " not in" << endl;
	}
	start += 3;
	size_t end = s3.find('/', start);
	cout << s3.substr(start, end - start) << endl;

	//erase ����
	//ɾ�� s3��Э��ǰ׺
	size_t pos4 = s3.find("://");
	s3.erase(0, pos4 + 3);
	cout << s3 << endl;
}

//6.string��ķǳ�Ա���� operator+��operator>>, operator<<, getline, relational operators


//7.һЩ��Ŀ
//7.1 ��ת�ַ���
void ReverseString1(string& s)
{
	//ָ��
	char* begin = (char*)s.c_str();
	char* end = begin + s.size() - 1;
	while (begin < end)
	{
		swap(*begin, *end);
		begin++;
		end -- ;
	}
}
void ReverseString2(string& s)
{
	//�⺯��
	reverse(s.begin(), s.end());
}
//���װ--�±�
class Solution
{
public:
	string ReverseString3(string& s)
	{
		size_t begin = 0;
		size_t end = s.size() - 1;
		while (begin < end)
		{
			swap(s[begin], s[end]);
			begin++;
			end--;
		}
		return s;
	}
};
void Test7()
{
	string s("programing every day");
	//ReverseString1(s);
	//ReverseString2(s);

	Solution s1;
	cout << s1.ReverseString3(s) << endl;

	//cout << s << endl;
}

//7.2���ַ����е�һ��ֻ����һ�ε��ַ�
class Way
{
public:
	char FindFirUp(string& s)
	{
		//��ͳ��ÿ�����ֳ��ֵĴ���
		int count[256] = { 0 };

		/*for (int i = 0; i < s.size(); i++)
		{
			count[s[i]]++;
		}*/
		for (auto e : s)
		{
			count[e]++;
		}

		//���ҳ���һ�����ִ���Ϊ1 ���ַ�
		for (int i = 0; i < s.size(); i++)
		{
			if (1 == count[s[i]])
			{
				return s[i];
			}
		}
		return -1;
	}
};
void Test8()
{
	string s("apple");
	Way w;
	cout << w.FindFirUp(s) << endl;
}

//7.3 ���ַ����������һ�����ʵĳ���
void Test9()
{
	string s;
	getline(cin, s);// ����ʹ��cin>>line,��Ϊ���������ո�ͽ�����
	size_t pos = s.rfind(' ');
	cout << s.size() - pos - 1 << endl;

}
//7.4 �����ַ������
class Method
{
public:
	string Add(string s1, string s2)
	{
		size_t str1 = s1.size() - 1;
		size_t str2 = s2.size() - 1;
		int value1, value2, next = 0;
		int valuest = 0;
		string result;
		while (str1 >= 0 || str2 >= 0) 
		{
			if (str1 >= 0)
			{
				value1 = s1[str1] - '0';
				str1--;
			}
			else
			{
				value1 = 0;
			}
			if (str2 >= 0)
			{
				value2 = s2[str2] - '0';
				str2--;
			}
			else
			{
				value2 = 0;
			}
			valuest = value1 + value2 + next;
			if (valuest > 9)
			{
				next = 1;
				valuest -= 10;
			}
			else
			{
				next = 0;
			}
			result += (valuest + '0');	
		}
		if (next == 1)
		{
			result += '1';
		}
		reverse(result.begin(), result.end());
		return result;
	}

};
void Test10()
{
	string s1("1234");
	string s2("234");
	string s3("9999");

	Method m;
	cout << "s1+s2:" << m.Add(s1, s2) << endl;
	//cout << "s1+s3:" << m.Add(s1, s3) << endl;
	//cout << "s2+s3:" << m.Add(s2, s3) << endl;

}

int main()
{
	Test1();
	Test2();
	TestPushBack();
	TestPushBackReserve();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	//Test9();
	Test10();

	system("pause");
	return 0;
}