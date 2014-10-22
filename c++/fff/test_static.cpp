

class Test
{
public:
	
	//静态成员函数只能访问 静态成员 静态函数
	static void fun()
	{
		//m_i = 10;
		fun2();
	}

	static void fun2()
	{
		//m_i = 10;
	}

	//能访问static变量
	//不能修改非静态变量的值
	const int fun4()const
	{
		m_i;
		m_sdata = 1;
		return m_i;
	}

	int fun1()
	{
		return 2;
	}

	Test();
	~Test();

private:
	int m_i;

	//const成员变量只能在构造函数的参数表里初始化
	const int m_ci;

	//静态成员变量必须被初始化 否则其它成员函数不能使用此变量
	static int m_sdata;
};

int Test::m_sdata = 10;

Test::Test() :m_ci(22)
{
	m_sdata = 99;
}

Test::~Test()
{

}

int main()
{
	Test::fun();

	Test a;
	a.fun4();

	return 0;
}