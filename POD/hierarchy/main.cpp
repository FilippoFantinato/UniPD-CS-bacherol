#include <iostream>

#include "Car.h"

int main(int argc, char const *argv[])
{
	Ferrari f;

	//std::cout << f.getBrand(5) << " " << f.getBrand(string("Bello")) << std::endl;
	std::cout << f.getBrand() << std::endl;

	return 0;
}