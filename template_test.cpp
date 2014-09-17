
template<typename T>
class MyClass
{
private:
	T a;

public:
	MyClass(){}
	~MyClass();
};

//class B
//{
//
//	B(){}
//	~B();
//
//	template<typename T>
//	friend class MyClass;
//
//};
int main()
{
	MyClass<int> dd;

	return 0;
}


