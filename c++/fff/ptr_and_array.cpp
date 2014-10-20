#include <iostream>
#include <string>
using namespace std;

//sizeof在编译阶段处理的特性。由于sizeof不能被编译成机器码，
//所以sizeof作用范围内，也就是()里面的内容也不能被编译，而是被替换成类型。
//= 操作符返回左操作数的类型，所以a = 3相当于int，而代码也被替换为：

void fun(int a[])
{
	int j = 10;
	return;
}

union u
{
	double a;
	int b;
};

union u2
{
	char a[13];
	int b;
};

union u3
{
	char a[13];
	char b;
};

class A
{
public:
	A();
	~A();

private:

};

A::A()
{
}

A::~A()
{
}

struct B
{

};

int main()
{
	/*int *p;
	int a[4];

	p = a;
	fun(p);

	double* (*b)[3][6];

	double *f[3][6];
	double(*f1)[3][6];

	string s = "hello";*/

	cout << sizeof(u) << endl;   // 8
	cout << sizeof(u2) << endl;   // 16
	cout << sizeof(u3) << endl;   // 13



	return 0;
}