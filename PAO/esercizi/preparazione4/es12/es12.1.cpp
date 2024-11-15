#include <iostream>

using namespace std;

class C {
public:
	int x;
	void f() { x=1; }
};

class D: public C {
public:
	double x;
	void f() { C::f(); x = 2; }

	int g() { return C::x; }
};
int main() {
	C c; D d; c.f(); d.f();
	cout << c.x << endl;
	cout << d.C::x << " " << d.x;
}
