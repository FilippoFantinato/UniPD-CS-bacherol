#ifndef VETTORE_H
#define VETTORE_H

#include <iostream>

/* ESERCIZIO:
Definire una classe vettore i cui oggetti rappresentano array di interi. 
vettore deve includere un costruttore di default, una operazione di 
concatenazione che restituisce un nuovo vettore v1+v2, una operazione di 
append v1.append(v2), l'overloading dell'uguaglianza, dell'operatore di 
output e dell'operatore di indicizzazione.  Deve inoltre includere il 
costruttore di copia profonda, l'assegnazione profonda e la distruzione profonda.
*/

class Vettore;

Vettore operator+(const Vettore& v1, const Vettore& v2);

class Vettore
{
	friend std::ostream& operator<<(std::ostream& os, const Vettore& v);

private:
	int *ptr;
	unsigned int size;

	void distruggi()
	{
		delete[] ptr;
	}

	void copia(const Vettore& v, unsigned int size)
	{
		for (int i = 0; i < size; ++i)
		{
			ptr[i] = v[i];
		}
	}

public:
	Vettore(unsigned int size = 0, int value = 0) : ptr(size == 0 ? nullptr : new int[size]), size(size)
	{
		for(int i = 0; i < size; ++i)
		{
			ptr[i] = value;
		}
	}

	Vettore(const Vettore& v) : ptr(v.size == 0 ? nullptr : new int[v.size]), size(v.size)
	{
		for (int i = 0; i < size; ++i)
		{
			ptr[i] = v[i];
		}
	}

	~Vettore()
	{
		delete[] ptr;
	}

	unsigned int length() const
	{
		return size;
	}

	void append(const Vettore& v)
	{
		*this = *this + v;
	}

	Vettore& operator=(const Vettore& v)
	{
		if(this != &v)
		{
			distruggi();

			ptr = v.size == 0 ? nullptr : new int[v.size];
			size = v.size;
			copia(v, size);
		}

		return *this;
	}

	bool operator==(const Vettore& v) const
	{
		if(this == &v) 		return true;
		if(v.size != size) 	return false;

		bool equal = true;

		for(int i = 0; i < size && equal; ++i)
		{
			equal &= ptr[i] == v[i];
		}

		return equal;
	}

	int& operator[](int index) const
	{
		return ptr[index];
	}
	
};

Vettore operator+(const Vettore& v1, const Vettore& v2)
{
	Vettore tmp(v1.length() + v2.length());

	int index = 0;

	for(;index < v1.length(); ++index)
	{
		tmp[index] = v1[index];
	}

	for(;index < tmp.length(); ++index)
	{
		tmp[index] = v2[index - v1.length()];
	}

	return tmp;
}

std::ostream& operator<<(std::ostream& os, const Vettore& v)
{
	for(int i = 0; i < v.size; ++i)
	{
		os << v[i];

		if((i + 1) != v.size)
		{
			os << ", ";
		}
	}

	return os;
}

#endif
