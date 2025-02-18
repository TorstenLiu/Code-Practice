#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

inline int Add(int left, int right)
{
	return left + right;
}
int main()
{
	int ret = 0;
	ret = Add(1, 3);

	//1.C++有哪些技术代替宏？  常量定义const 和  函数定义内联函数
	//常量定义const ：
	const int a = 10;
	int*pa = (int*)&a;
	*pa = 100;
	cout << a << endl;//10,在c++里面，const相当于宏，在编译阶段就会被替换，运算的时候直接取10
	cout << *pa << endl;//100

	system("pause");
	return 0;
}

//2.内联函数和宏的区别？
// 1.宏定义是在预处理的时候把所有的宏名用宏体来替换，简单的说就是字符串替换。
//内联函数则是在编译的时候进行代码插入，
//编译器会在每处调用内联函数的地方直接把内联函数的内容展开，这样可以省去函数的调用的开销，提高效率

// 2.编译器会对内联函数的参数类型做安全检查或自动类型转换（同普通函数），而宏定义则不会，无论对还是错都是直接替换；
// 3.内联函数在运行时可调试，而宏定义不可以;
//4.宏定义和内联函数使用的时候都是进行代码展开。
//不同的是宏定义是在预编译的时候把所有的宏名替换，
//内联函数则是在编译阶段把所有调用内联函数的地方把内联函数插入。这样可以省去函数压栈退栈，提高了效率
