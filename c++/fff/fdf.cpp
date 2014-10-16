

class MyClass
{
public:
	MyClass();
	~MyClass();

	friend void fun1();
	friend class B;

private:
	int a;
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

class B
{
public:
	B();
	~B();

private:

};

B::B()
{
	MyClass ss;
	ss.a = 10;
	int h = 5;
}

B::~B()
{
}

void fun1()
{
	MyClass ss;
	ss.a = 10;

	int h = 5;
}

int main()
{
	B hh;
	fun1();

	return 0;
}
