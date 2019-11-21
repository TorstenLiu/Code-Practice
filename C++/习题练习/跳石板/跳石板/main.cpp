#define _CRT_SECURE_NO_WARNINGS 1

/*���ӣ�https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8
��Դ��ţ����
С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
���磺
N = 4��M = 24��
4->6->8->12->18->24
����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��

��������:
����Ϊһ�У�����������N��M���Կո������ (4 �� N �� 100000) (N �� M �� 100000)

�������:
���С��������Ҫ��Ծ�Ĳ���,������ܵ������-1
ʾ��1
����
4 24
���
5*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��Լ��
 void Get(int num, vector<int>& v) 
 {
	 for (int i = 2; i <= num/2; i++) {
		 if (num%i == 0) {
			 v.push_back(i);
			 if (num / i != i)
				 v.push_back(num / i);
		 }
	 }
 }

 int main() 
 {
	 int N, M;
     vector<int> res(M + 1, 0);
     res[N] = 1;
     for (int i = N; i <= M; i++) 
 {
	 vector<int> v;

	 //λ��i�޷��������
	 if (res[i] == 0)
		 continue;
	 Get(i, v);//��¼����㵽i����С����
	 for (int j = 0; j < v.size(); j++) 
	 {
		 //�ɵ�i�����ܵ���ĵ�
		 if ((v[j] + i) <= M && res[v[j] + i] != 0)
			 //������Ҳ�ܵ���Ƚϴ�С����¼��С����
			 res[v[j] + i] = min(res[v[j] + i], res[i] + 1);
		 else if ((v[j] + i) <= M)
			 //�����i����С������1
			 res[v[j] + i] = res[i] + 1;
	 }
 }
     if (res[M] == 0)
     {
		 cout << -1 << endl;
     }
     else
     {
		 cout << res[M] - 1 << endl;
     }
	 return 0;
 }