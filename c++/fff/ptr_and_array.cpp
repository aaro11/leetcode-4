#include <iostream>
#include <string>
using namespace std;

//sizeof�ڱ���׶δ�������ԡ�����sizeof���ܱ�����ɻ����룬
//����sizeof���÷�Χ�ڣ�Ҳ����()���������Ҳ���ܱ����룬���Ǳ��滻�����͡�
//= ����������������������ͣ�����a = 3�൱��int��������Ҳ���滻Ϊ��

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