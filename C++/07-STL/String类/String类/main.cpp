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

  //�ܽ᣺ 
//newcapacity > oldcapacity(string��ɿռ��С)���ռ�����--->�����ı�(����������С >= newCapacity��vs�´�Լ��1.5�ı�������)
// newcapacity < oldcapacity(string��ɿռ��С)���ռ���С����Ӱ������
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
void Test5()
{
	string s;
	s.push_back('z');//��s�������һ���ַ�z
	s.append("ss");//��s����׷��һ���ַ�ss
	s += 'n';//��s����׷��һ���ַ�n
	s += "b!";//��s�����һ���ַ���"b��"
	cout << s << endl;

	string s2("I love");
	string s3(" pxy");
	s2 += s3;
	s2.append(3,'!');
	cout << s2 << endl;
	cout << s2.c_str() << endl;//��C���Եķ�ʽ��ӡ�ַ���

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

	system("pause");
	return 0;
}