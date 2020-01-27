//1.
char *myString()
{
	char buffer[6] = { 0 };
	char *s = "hello world";
	for (int i = 0; i < sizeof(buffer) - 1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}
int main()
{
	char * buffer = myString();
	printf("%s\n", buffer);//结果为烫烫烫的随机值，因为buffer为局部数组，函数结束后会被收回
	system("pause");
	return 0;
}

//2.
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d\n", strlen(a));//255
	system("pause");
	return 0;
}

//3.
int main()
{
	const int i = 0;
	int *j = (int *)&i;
	*j = 1;
	printf("%d,%d", i, *j);//1,1
	system("pause");
	return 0;
}
//4.
int main()
{
	unsigned int a = 0xFFFFFFF7;
	unsigned char i = (unsigned char)a;
	char *b = (char *)&a;
	printf("%08x,%08x", i, *b);
	system("pause");
	return 0;
}
//5.
int main()
{
	char *str = "abcde";
	str += 2;
	printf("%lu\n", str);//打印c的地址
	system("pause");
	return 0;
}

//6.
int main()
{
	int x, y, z;
	x = 1;
	y = 1;
	z = x++, y++, ++y;
	printf("%d,%d,%d\n", x, y, z);
	//x=2  y=3  z=1 赋值运算符优先级高于逗号表达式，所以先算
	//(z=x++),y++,++y
}

//7.
int main()
{
	int i = 10;
	int j = 10, k = 3;
	k *= i + j;
	printf("%d\n", k);
	//  k=3  +优先级高于*=
}
