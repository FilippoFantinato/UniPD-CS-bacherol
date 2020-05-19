#include <iostream>

class C
{
public:
	C() {  }
	C(const C& r) { std::cout << "*" << std::endl; }
};

C f(C a)
{
	C b(a);
	C c = b;

	return c;
}

int main(int argc, char const *argv[])
{
	C x;
	C y = f(f(x));

	return 0;
}
