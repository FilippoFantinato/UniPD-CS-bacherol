#include <iostream>

class D
{
private:
	int z;

public:
	D(int x = 0) : z(x) { std::cout << "D01 "; };
	D(const D& d) : z(d.z) { std::cout << "Dc "; };
};

class C 
{
private: 
	D d;

public:
	C() : d(D(5)) { std::cout << "C0 "; }
	C(int a) : d(5) { std::cout << "C1 "; }
	C(const C& c) : d(c.d) { std::cout << "Cc "; }
};

int main(int argc, char const *argv[])
{
	C c1; std::cout << "UNO" << std::endl;
	C c2(3); std::cout << "DUE" << std::endl;
	C c3(c2); std::cout << "TRE" << std::endl;
	return 0;
}
