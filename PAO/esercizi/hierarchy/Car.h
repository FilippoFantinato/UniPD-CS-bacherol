#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using std::string;

class Car
{
private:
	string brand;

public:
	Car() : brand("BASE") { std::cout << "CAR0" << std::endl; }

	Car(const string& brand) : brand(brand)
	{
		std::cout << "CAR1" << std::endl;
	}
	~Car() 	{ std::cout << "CARD0" << std::endl; }

	int getBrand() const
	{
		return 0;
	}

	const string& getBrand(const string& model) const
	{
		return model;
	}

	string getBrand(int i) const
	{
		return "Ciao" + std::to_string(i);
	}
};

class Ferrari : public Car
{
public:
	Ferrari() 	{ std::cout << "FERRARI0" << std::endl; }
	~Ferrari() 	{ std::cout << "FERRARID0" << std::endl; }
};

#endif
