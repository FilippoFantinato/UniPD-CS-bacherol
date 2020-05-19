#include "multiinfo.h"

int main(int argc, char const *argv[])
{
	C<int, 5> m1(7, 1), m2(7, 1), m3(9, 1);

	// std::cout << m2;
	// std::cout << m3;

	std::cout << m1;

	m1 = m2;

	*(m1[1]) = 8;
	*(m1[2]) = 8;
	*(m1[3]) = 8;

	std::cout << m1;
	std::cout << m2;

	std::cout << (m1 == m2) << std::endl;
	std::cout << (m1.occorrenze(8)) << std::endl;

	return 0;
}
