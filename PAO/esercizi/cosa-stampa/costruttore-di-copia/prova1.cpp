#include <iostream>

class D
{
public:
	int x;

	D() : x(0) { std::cout << "D0 " << std::endl; }
	D(int x) : x(x) { std::cout << "D1 " << x << std::endl; };
	D(const D& d) : x(d.x) { std::cout << "DP " << d.x << std::endl; };

	~D() { std::cout << "DD " << x << std::endl; }
	
};

class C
{
private:
	D d1;
	D d2;
	D d3;

public:
	C(int x = 0) : d1(D(x + 1)), d2(D(x + 2)), d3(D(x + 3))
	{

	};
	C(const C& c)
	{
		std::cout << "CP-D3 " << d3.x << std::endl;
		d3 = c.d3;
		std::cout << "CP-D3E " << d3.x << std::endl;

		std::cout << "CP-D1 " << d1.x << std::endl;
		d1 = c.d1;
		std::cout << "CP-D1E " << d1.x << std::endl;

		std::cout << d2.x << std::endl;

		std::cout << "CP " << std::endl;
	}

	~C() { std::cout << "CD " << std::endl; }
};

void f(C c1, C c2)
{
	std::cout << "F" << std::endl;
}

int main(int argc, char const *argv[])
{
	C c1;
	std::cout << "UNO" << std::endl;

	C c2(4);
	std::cout << "DUE" << std::endl;

	f(c1, c2);

	return 0;
}
