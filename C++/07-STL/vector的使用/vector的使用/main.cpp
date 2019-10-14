#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


void Print(vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

//1.���캯��
void Test1()
{
	//�޲ι���
	vector<int> v1;
	//���첢��ʼ��n��ֵ
	vector<int> v2(4, 100);
	//��������
	vector<int> v3(v2);
	//��������ʼ������
	vector<int> v4(v2.begin(), v2.end());

	int array[] = { 1,2,3,4,5,6,7 };
	vector<int> v5(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v6{ 1,2,3,4,5,6,7 };

	cout << "v1:";
	Print(v1);
	cout << "v2:";
	Print(v2);
	cout << "v3:";
	Print(v3);
	cout << "v4:";
	Print(v4);
	cout << "v5:";
	Print(v5);
	cout << "v6:";
	Print(v6);
}

//2.����������
void Test2()
{
	vector<int> v1{ 1,2,3 };

	//1.�õ��������б�����ӡ
	//vector<int>::iterator it = v1.begin(); c++98��֧�ַ�ʽ
	auto it = v1.begin();  //begin��end���Ի���rbegin��rend  ���������
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//2.�õ����������޸�
	it = v1.begin();
	while (it != v1.end())
	{
		*it *= 2;
		it++;
	}
	Print(v1);
}

//3.��������
void Test3()
{
	vector<int> v1{ 1,2,3,4,5,6,7 };
	cout << "size:" << v1.size() << endl;
	cout << "capacity" << v1.capacity() << endl;

	//����
	vector<int> v2;
	//v2[0] = 1;���������޷�����Ԫ��
	size_t sz = v2.capacity();
	for (int i = 0; i < 100; i++)
	{
		v2.push_back(i);
		if (sz != v2.capacity())
		{
			sz = v2.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}

	cout << endl;

	//��ǰ��reserve
	vector<int> v3;
	v3.reserve(100);
	//v3[0] = 1;����
	//������v3.resize(100); ��Ϊj=0ʱ�Ǵ�100����ЧԪ�غ��濪ʼ���룬���ǵ�101�����ᷢ��150��225����
	size_t szz = v3.capacity();
	for (int j = 0; j < 100; j++)
	{
		v3.push_back(j);
		if (szz != v3.capacity())
		{
			szz = v3.capacity();
			cout << "capacity changed:" << szz << endl;
		}
	}
}

//4.��ɾ�Ĳ��Ԫ�ط���
void Test4()
{
	vector<int> v1{ 1,2,3,4,5,6,7 };
	Print(v1);

	v1.push_back(1);//β��
	Print(v1);
	v1.pop_back();//βɾ
	Print(v1);

	// find / insert / erase

	// ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v1.begin(), v1.end(),3);

	// ��posλ��֮ǰ����30
	v1.insert(pos, 30);
	Print(v1);

	// ɾ��posλ�õ�����
	pos = find(v1.begin(), v1.end(), 3);//���뽫pos���¶�λ,�������ʧЧ��������
	v1.erase(pos);
	Print(v1);

	// operator[]+index �� C++11��vector����ʽfor+auto�ı���
	//ͨ��[]��ȡ��0��λ��
	v1[0] = 100;
	Print(v1);

	//swap:��������vector�����ݿռ�
	vector<int> v2{ 1,2,3 };
	v1.swap(v2);
	Print(v1);
	Print(v2);
}

//5.������ʧЧ  
// ��������������ָ���һ�����ͣ����Խ�����������Ķ��󵱳�ָ��ķ�ʽ����Ӧ��
// ���ã������û�͸����(�û����Բ���֪���������ĵײ����ݽṹ)���������е�Ԫ��
void Test5()
{
	vector<int> v1{ 1,2,3,4,5 };

	//1.ʹ��find����3����λ�õ�iterator
	auto pos = find(v1.begin(), v1.end(), 3);
	//2.ɾ��posλ�õ����ݣ�����pos������ʧЧ��
	v1.erase(pos);
	//cout << *pos << endl;//�Ƿ�����

	//ͬ����posǰ�������ݣ�Ҳ�ᵼ�µ�����ʧЧ����Tset4�������
	//insert��push_back,�ᵼ�����ݣ���pos��ָ��ԭ���Ŀռ䣬�������ݻῪ���¿ռ䣬�ͷ�ԭ���ռ�
	//resize��reserve��assgin


	//�����ʽ�������������¸�ֵ
	int arr[] = { 1,2,3,4,5,6,7 };
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//ɾ��v2�����е�ż��������ʽ
	//vector<int>::iterator it = v2.begin();
	//while (it != v2.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v2.erase(it);
	//	}
	//	it++;//erase����itʧЧ����++���³������
	//}
	//���ƺ�
	vector<int>::iterator it = v2.begin();
	while (it != v2.end())
	{
		if (*it % 2 == 0)
		{
			it = v2.erase(it);//erase�᷵�ص�ǰɾ��λ�õ���һ��λ��
		}
		it++;
	}
	Print(v2);
}

//6.����ʧЧ
void Test6()
{
	vector<int> v1{ 1,2,3 };
	int& rv = v1[0];
	rv = 100;
	Print(v1);

	v1.push_back(1);//�¿ռ�
	rv = 10;//����rv���õ�ԭ���Ŀռ��Ѿ�ʧЧ
	Print(v1);
	cout << rv << endl;//����rv����ŵ������ֵ

	//���
	rv = v1[0];
	rv = 10;
	Print(v1);
	cout << rv << endl;
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