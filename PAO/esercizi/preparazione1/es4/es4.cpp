#include <typeinfo>

#include <iostream>

class Abs
{
public:

	virtual void print() const
	{
		std::cout << "ABS" << std::endl;
	}
};

class A : public Abs {  };

class C : public A {  };

class R : public C { virtual void print() const { std::cout << "R" << std::endl; } };

class B : public R {  };

template<class T1, class T2>
bool fun(T1 *t1, T2& t2)
{
	Abs *abs = new Abs();

	std::cout << (typeid(T1) == typeid(T2)) << std::endl;
	std::cout << (typeid(*t1) == typeid(t2)) << std::endl;
	std::cout << (dynamic_cast<Abs *>(t1) != nullptr) << std::endl;

	return typeid(T1) == typeid(T2) && typeid(*t1) == typeid(t2) && dynamic_cast<Abs *>(t1) != nullptr;
}

int main(int argc, char const *argv[])
{
	B a = B();

	std::cout << fun<B, B>(new B(), a) << std::endl;

	return 0;
}
