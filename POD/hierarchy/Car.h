#ifndef CAR_H
#define CAR_H

#include <string>

using std::string;

class Car
{
private:
	string brand;

public:
	Car(const string& brand) : brand(brand) {  }

	int getBrand() const
	{
		return 0;
	}

	const string& getBrand(const string& model) const
	{
		return model;
	}
};

class Ferrari : public Car
{
public:
	Ferrari() : Car("Ferrari") {  }

	string getBrand(const int& i) const
	{
		return "Ciao" + std::to_string(i);
	}
};

#endif
