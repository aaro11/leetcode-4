
#define DECLTYPE(x) (decltype(x))

#define DECLTYPE_ASSIGN(dst,src)                                                 \
do {\
	(dst) = DECLTYPE(dst)(src); \
} while (0)


const int&& gg(){ return 0; }
const int hh(){ return 0; }
struct A { double x; };
int main()
{

	const int&& foo(int x); 
	const int bar();
	int i; 
	

	const A* a = new A();

	decltype(foo) x1; // ����Ϊconst int&&
	decltype(bar()) x2 = 0; // ����Ϊint
	decltype(i) x3 = 0; // ����Ϊint
	decltype(a->x) x4 = 0.00; // ����Ϊdouble
	decltype((a->x)) x5 = 0.00; // ����Ϊconst double&

	/*( (void*) (  ( (char*)(hhp) ) - ( (tbl)->hho )  )    )

	DECLTYPE_ASSIGN(out, )

	decltype(foo)(1);*/

	return 0;
}