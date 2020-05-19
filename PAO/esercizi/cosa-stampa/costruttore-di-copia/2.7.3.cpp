#include <iostream>

class Puntatore
{
public:
	int *p;
};

int main(int argc, char const *argv[])
{
	Puntatore x, y;
	x.p = new int(8);

	y = x;

	std::cout << "*(y.p) = " << *(y.p) << std::endl; // 8
	std::cout << "*(x.p) = " << *(x.p) << std::endl; // 8

	*(y.p) = 3;

	std::cout << "*(x.p) = " << *(x.p) << std::endl; // 3

	return 0;
}
