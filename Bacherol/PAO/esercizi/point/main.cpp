#include <iostream>

#include "Point.h"

int main(int argc, char const *argv[])
{
	Point a(5, 7, 9), b(7, 8, 1);

	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "A + B = " << a + b << std::endl;

	b.negate();
	std::cout << "A = " << a << std::endl;
	std::cout << "-B = " << b << std::endl;
	std::cout << "A - B = " << a + b << std::endl;


	return 0;
}
