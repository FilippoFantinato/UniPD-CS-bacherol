#include <iostream>

class A
{
public:
	virtual ~A() = default;
};

class B : public A
{
public:
	virtual void bm() const = 0;
};

class C : public B
{
public:
	void bm() const
	{
		std::ostream << "CIAO" << std::endl;
	}
};

class D
{
public:
	D() = default;
};

class E : public D
{
public:
	E& operator=(const E& e)
	{
		if(this != &e)
		{
			D::operator=(e);
		}

		return *this;
	}
};
