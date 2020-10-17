#include <iostream>

unsigned int sumDigits(unsigned int n)
{
	unsigned int sum = 0;

	while(n)
	{
		unsigned int digit = n % 10;

		n /= 10;

		sum += digit * digit;
	}

	return sum;
}

bool isHappy(unsigned int n)
{
	bool found = false;

	while(!found)
	{
		found = 
	}

	return found;
}

std::ostream& operator<<(std::ostream& os, bool b)
{
	return os << (b ? "TRUE" : "FALSE");
}

int main(int argc, char const *argv[])
{
	unsigned int n;

	std::cout << n << " " << isHappy(n) << std::endl;

	return 0;
}