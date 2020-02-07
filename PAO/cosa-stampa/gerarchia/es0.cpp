#include <iostream>

using namespace std;

class A
{
private:
	int x;

public:
	A(int x = 0) : x(x) { cout << "A(int x = " << x << ") "; }
	~A() { cout << "~A() "; }
};

class B : public A
{
public:
	B() : A(7) { cout << "B() "; }
	~B() { cout << "~B() "; }
	
};

class C : public B
{
private:
	B b;

public:
	C() { cout << "C() "; }
	~C() { cout << "~C() "; }
	
};

class D : public C
{
public:
	D() { cout << "D() "; }
	~D() { cout << "~D() "; }
	
};


int main(int argc, char const *argv[])
{
	D d;
	cout << " FINE " << endl;
	
	return 0;
}
