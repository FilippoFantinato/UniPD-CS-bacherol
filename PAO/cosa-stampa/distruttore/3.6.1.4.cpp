#include <iostream>

class A
{
private:
	int z;

public:
	~A() { std::cout << "Ad "; };
	
};

class B
{
public:
	A *p;
	A a;
	~B() { std::cout << "Bd "; }
};

class C
{
public:
	static B s;
	int k;
	A a;

	~C() { std::cout << "Cd "; };
};

B C::s = B();

int main(int argc, char const *argv[])
{
	C c1, c2;
	return 0;
}
