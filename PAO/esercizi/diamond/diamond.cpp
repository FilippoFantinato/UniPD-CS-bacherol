#include <iostream>

class A
{
private:
	int x;

public: 
	A(int x = 0) : x(x)
	{
		std::cout << "A: " << x << std::endl;
	}
};

class B : virtual public A
{
private:
	int x;

public: 
	B(int x = 0) : A(x)
	{
		std::cout << "B: " << x << std::endl;
	}
};

class C : virtual public A
{
private:
	int x;

public: 
	C(int x = 0) : A(x)
	{
		std::cout << "C: " << x << std::endl;
	}
};

class D : public B, public C
{
private:
	int x;

public: 
	D(int x = 0) : B(x), C(x)
	{
		std::cout << "D: " << x << std::endl;
	}
};

int main(int argc, char const *argv[])
{
	D d(10);



	return 0;
}
