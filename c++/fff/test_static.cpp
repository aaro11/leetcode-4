

class Test
{
public:
	
	//��̬��Ա����ֻ�ܷ��� ��̬��Ա ��̬����
	static void fun()
	{
		//m_i = 10;
		fun2();
	}

	static void fun2()
	{
		//m_i = 10;
	}

	//�ܷ���static����
	//�����޸ķǾ�̬������ֵ
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

	//const��Ա����ֻ���ڹ��캯���Ĳ��������ʼ��
	const int m_ci;

	//��̬��Ա�������뱻��ʼ�� ����������Ա��������ʹ�ô˱���
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