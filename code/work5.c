//1.��������Ϸ
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("  welcome to my game!   \n");
	printf("********1 to play*******\n");
	printf("********0 to exit*******\n");
	printf("choose 1 as a smart men!\n");
}
void game()
{
	int ret;
	ret = rand() % 100 + 1;
	while (1)
	{
		int guess = 0;
		printf("������𰸰�");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("��С��\n");
		}
		else if (guess > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("Ӵ����Ȼ�¶���\n");
			break;
		}
	}
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));//������ӣ���ÿһ�β��������������һ��  NULL:������time�����ķ���ֵ
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("��ɶ�أ��ú���");
			break;
		}

	} while (input);
	system("pause");
	return 0;
}

//2.��¼����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i = 0;
	int count = 0;
	char password[10] = { 0 };// 0 '0�� =��\0�� NULL
	for (i = 0; i < 3; i++)
	{
		printf("����������>");
		scanf("%s", password);  //��&������������ĵ�ַ  ���Ӵ��������������Ԫ�صĵ�ַ
		if (strcmp(password, "1234") == 0)
		{
			printf("��ϲ����½�ɹ�");
			break;
		}
		else
			count--;
		printf("������󣬻���%d���������");

	}
	if (i == 3)
	{
		printf("����ȫ���˳�ϵͳ");
	}
	system("pause");
	return 0;
}

//3.���ֲ��ҷ�

/*���ֲ��ҵ��ŵ㣬�ݹ�ͷǵݹ飬����������Ļ���֮��*/
#include<stdio.h>
#include<stdlib.h>

int binarysearch(int arr[], int k, int left, int right)//arr[]������ָ�� 
//=int binarysearch(int arr[],int k, int sz)   int left; int righr=sz-1;
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;//�˾����while���棬ÿ����һ��ifҪ����
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 0;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	/*arr���Ķ��壬������ʹ��sizeof(arr) / sizeof(arr[0]) ������˾�����Ӻ�������rightֵΪ0 ����Ϊsizeof��arr��=4����һ��ָ������Ĵ�С��4��8��
	��Ϊ���ε�����Ԫ�صĵ�ַ�������Ӻ����� arr[]�����գ�����������һ��ָ��arr[]Ҳ�ɸĳ�*arr
	���ԣ��������Ӻ����ڲ������������������ֵ�����Ԫ�ظ����������Ҫ����ô����������������ٴ���ȥ int sz= sizeof(arr) / sizeof(arr[0])  ���������������*/
	int mid = left + (right - left) / 2;
	int zss = 0; //����һ�����͵�ֵ
	scanf("%d", &key);
	zss = binarysearch(arr, key, left, right);//�����������������ֵ
	if (zss == -1)
	{
		printf("can't find\n");
	}
	else
	{
		printf("�±���%d\n", zss);
	}
	system("pause");
	return 0;
}

//4.�����ַ�

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int word = 0;
	while ((word = getchar()) != EOF)//end of file ->ctrl+Z    ctrl+c �жϳ���
	{
		if (word >= 'a' && word <= 'z')
		{
			printf("%c", word - 32);//putchar(ch-32);
		}
		else if (word >= 'A' && word <= 'Z')
		{
			printf("%c", word + 32);
		}
		else if (word >= '0'&&word <= '9')//�����ifִ�����Ժ�Ͳ���ִ�к����if else��
		{


		}
	}
	system("pause");
	return 0;
}