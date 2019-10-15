#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<list>

//list:��ͷ˫��ѭ������

void Print(list<int> l)
{
	//������ͨ���±��ӡ

	//1.��������ʽ��ӡ
	/*for (auto it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}*/

	//2.��Χfor��ʽ��ӡ
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}
bool IsOdd(int data)
{
	if (0 == data % 2)
		return true;

	return false;
}
//1.list�Ĺ���
void Test1()
{
	list<int> l1;
	list<int> l2(6, 100);
	list<int> l3(l2.begin(), l2.end());
	list<int> l4(l2);

	cout << "l1:";
	Print(l1);
	cout << "l2:";
	Print(l2);
	cout << "l3:";
	Print(l3);
	cout << "l4:";
	Print(l4);


	cout << endl;
}

//2.������ʹ��
void Test2()
{
	int arr[] = { 1,2,3,4,5 };
	list<int> l(arr, arr+sizeof(arr) / sizeof(arr[0]));
	//1.const���͵�����
	for ( list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//2.���������
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//3.���������
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

//3.��������
void Test3()
{
	list<int> l1;
	list<int> l2(4, 7);
	cout << l2.size() << endl;
	cout << l1.empty() << endl;//1---true   0---false
}

//4.Ԫ�ط���
void Test4()
{
	int arr[] = { 1,2,3,4,5, };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	cout << l.front() << endl;
	cout << l.back() << endl;
}

//5.�޸Ĳ���
void Test5()
{
	list<int> l(4, 7);
	cout << l.front() << endl;

	l.push_front(100);
	l.push_back(100);
	cout << l.front() << endl;
	cout << l.back() << endl;

	l.pop_back();
	l.pop_front();
	cout << l.front() << endl;
	cout << l.back() << endl;

	int arr[] = { 1,2,3,4,5 };
	list<int> l2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//����
	list<int>::iterator pos = find(l2.begin(), l2.end(), 3);
	l2.insert(pos, 1,100);//һ��100��1���Ըģ����Բ�д��Ĭ��Ϊ1
	Print(l2);

	cout << endl;

	l2.erase(pos);
	Print(l2);

	list<int> l3(4, 7);
	l2.swap(l3);
	cout << "l2:";
	Print(l2);
	cout << "l3:";
	Print(l3);

	l2.clear();
	cout << l2.size() << endl;
	Print(l2);

	//remove   remove_if
	// remove_if��ɾ���������������Ľڵ�
	// ���������Ǹú����Ĳ���
	// �ú�����ʵ��ԭ����ÿ���ڵ��е�ֵ���ò�������������֤��
	//���������ɾ�������������ʲô������

	l3.remove(2);
	Print(l3);

	l3.remove_if(IsOdd);
	Print(l3);

	//unique  ʹԪ��Ψһ
	// ע�⣺ʹ��uniqueʱ���뱣֤�����������
	int arr2[] = { 1,3,5,6,2,2,9,2 };
	list<int> l4(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
	Print(l4);

	l4.sort();
	l4.unique();
	Print(l4);

}

//6.������ʧЧ
void Test6()
{
	list<int> l(2, 10);
	auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it);
		//����������erase()ִ�к�it��ָ��ڵ��Ѿ���ɾ����it��Ч

		//����������������¸�ֵ
		it = l.begin();
		it++;
	}
}
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	system("pause");
	return 0;
}