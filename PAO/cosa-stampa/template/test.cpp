#include <iostream>

class C
{
public:
	C() { std::cout << "C0" << std::endl; }
};

int main(int argc, char const *argv[])
{
	C *p = new C[0];

	return 0;
}