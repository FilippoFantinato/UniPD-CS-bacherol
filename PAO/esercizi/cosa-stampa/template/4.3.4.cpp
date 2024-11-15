#include <iostream>

class A
{
private:
	int x;

public:
	A(int x = 0) : x(x) { std::cout << x << "A() "; };
};

template<class T>
class C
{
public:
	static A s;

	C() { std::cout << "C() "; }
};

template<class T>
A C<T>::s = A();

int main(int argc, char const *argv[])
{
	C<double> c;
	C<int> d;
	std::cout << "aa" << std::endl;
	C<int>::s = A(2);
	C<double>::s = A(2);
	
	return 0;
}
