#include <iostream>
#include <vector>

class A
{
public:
	A() { std::cout << "A() " << std::endl; }
	virtual void m() const = 0;
	
};

class B : public A
{
public:
	int a;
	B() { std::cout << "B() " << std::endl; }
	
};

class C : public B
{
private:
	std::vector<int *> v;
	int& ref;
	float *p;

public:
	C() : ref(*(new int(5))) { std::cout << "C() " << std::endl; }
	C(const C& c) : B(c), v(c.v), ref(c.ref), p(c.p) {}

	void m() const {}
};

int main(int argc, char const *argv[])
{
	C c;
	return 0;
}
