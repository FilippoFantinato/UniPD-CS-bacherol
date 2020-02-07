#include <iostream>

using namespace std;

template<class T> class D; // dichiarazione incompleta

template<class T1, class T2>
class C
{
	friend class D<T1>;
private:
	T1 t1;
	T2 t2;
};

template<class T>
class D {
public:
	void m() {C<T,T> c; cout << c.t1 << c.t2;}
	void n() {C<int,T> c; cout << c.t1 << c.t2;}
	void o() {C<T,int> c; cout << c.t1 << c.t2;}
	void p() {C<int,int> c; cout << c.t1 << c.t2;}
	void q() {C<int,double> c; cout << c.t1 << c.t2;}
	void r() {C<char,double> c; cout << c.t1 << c.t2;}
};

int main(int argc, char const *argv[])
{
	// D<char> d; d.m();
	// D<char> d; d.n();
	// D<char> d; d.o();
	// D<char> d; d.p();
	// D<char> d; d.q();
	D<char> d; d.r();

	return 0;
}
