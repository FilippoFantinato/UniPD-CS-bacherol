#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <math.h>

/*
	Definire una classe Point i cui oggetti rappresentano
	punti nello spazio (x,y,z). Includere un costruttore di
	default, un costruttore a tre argomenti che inizializza un
	punto, selettori delle coordinate cartesiane, un metodo
	negate() che trasforma un punto nel suo negativo,
	una funzione norm() che restituisce la distanza del
	punto dall'origine, l'overloading degli operatori di somma
	e di output. Separare interfaccia ed implementazione
	della classe.
*/

class Point
{
	friend std::ostream& operator<<(std::ostream &os, const Point& p);

private:
	long x, y, z;

public:
	Point(long x = 0, long y = 0, long z = 0) : x(x), y(y), z(z)
	{

	}

	long getX()
	{
		return x;
	}

	long getY()
	{
		return y;
	}

	long getZ()
	{
		return z;
	}

	void negate()
	{
		x *= -1;
		y *= -1;
		z *= -1;
	}

	long norm()
	{
		return sqrtl(x * x + y * y + z * z);
	}

	Point operator+(const Point& p)
	{
		return Point(x + p.x, y + p.y, z + p.z);
	}
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	return os << "X = " << p.x << std::endl 
				<< "Y = " << p.y << std::endl
				<< "Z = " << p.z;
}

#endif
