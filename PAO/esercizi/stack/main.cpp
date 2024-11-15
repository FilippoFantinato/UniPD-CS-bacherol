#include <iostream>

#include "stack.h"


int main(int argc, char const *argv[])
{
	Stack<char, 10> p('p', 2), a('a', 10);

	Stack<char, 10> b('b', 10);

	std::cout << p << std::endl << a << std::endl;

	std::cout << (a == p) << std::endl;

	a = p;

	p.push('c');

	std::cout << p << std::endl << a << std::endl;

	a.push('c');

	std::cout << "A: " << a << std::endl;

	std::cout << a.top() << std::endl;

	a.pop();

	std::cout << "A: " << a << std::endl;

	a.push('a');

	std::cout << "A: " << a << std::endl;

	std::cout << a.top() << std::endl;


	return 0;
}
