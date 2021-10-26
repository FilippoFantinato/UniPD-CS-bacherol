#include <iostream>

class C
{
	friend std::ostream& operator<<(std::ostream& os, const C& c);
private:
	int x;

public:
	C(int x) : x(x)
	{
		std::cout << "C0 " << x << std::endl;
	}

	C(const C& c)
	{
		std::cout << "CP " << c.x << " " << x << std::endl;

		x = c.x;

		std::cout << "CP " << c.x << " " << x << std::endl;
	}

	C& operator=(const C& c)
	{
		if(this != &c)
		{
			std::cout << "= " << c.x << " " << x << std::endl;
			x = c.x;
		}
		else
		{
			std::cout << "UGUALI" << std::endl;
		}

		return *this;
	}
};

std::ostream& operator<<(std::ostream& os, const C& c)
{
	return os << "C = " << c.x;
}

int main(int argc, char const *argv[])
{
	C a = 20;
	C b = 10;

	std::cout << "UNO" << std::endl;

	b = b;

	std::cout << a << std::endl;

	return 0;
}
