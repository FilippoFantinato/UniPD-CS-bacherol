#include <iostream>

#include "Car.h"

int main(int argc, char const *argv[])
{
	Ferrari *f = new Ferrari();

	std::cout << f->getBrand(5) << " " << f->getBrand(string("Bello")) << std::endl;
	// std::cout << f.getBrand(5) << std::endl;

	Car *c = f;

	delete c;

	return 0;
}