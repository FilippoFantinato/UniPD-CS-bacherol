#ifndef MULTIINFO_H
#define MULTIINFO_H

#include <iostream>

/*
Definire un template di classe C<T,size> con parametro di tipo T e parametro valore size di tipo intero senza segno che soddisfi le seguenti specifiche:
1. MultiInfo<T> e un template di classe associato ed annidato nel template ` C<T,size>. Un oggetto di MultiInfo<T> rappresenta un oggetto di tipo T, detto informazione, con una molteplicita` m ≥ 0.
2. Un oggetto di C<T,size> rappresenta un array allocato dinamicamente di dimensione size di oggetti di MultiInfo<T>.
3. C<T,size> rende disponibile un costruttore C(const T&, int) con il seguente comportamento: una invocazione C(t,k) costruisce un oggetto di C<T,size> il cui array contiene in ogni posizione un oggetto di MultiInfo<T> con informazione t e quando k e` ≥ 1 con molteplicita` k, altrimenti (cioe quando ` k e` < 1) con molteplicita` 0.
4. Nel template C<T,size> il costruttore di copia, l’assegnazione e il distruttore devono essere “profondi”.
5. C<T,size> fornisce l’overloading dell’operatore T* operator[](int) con il seguente comportamento: se 0 ≤ k < size allora una invocazione c[k] ritorna un puntatore all’informazione di tipo T memorizzata nell’array di c in posizione k, altrimenti ritorna il puntatore nullo.
6. C<T,size> fornisce un metodo int occorrenze(const T&) con il seguente comportamento: una invocazione
c.occorrenze(t) ritorna la somma delle molteplicita di tutte le occorrenze dell’informazione ` t nell’array memorizzato in c.
7. Deve essere disponibile l’overloading dell’operatore di output per oggetti di C<T,size> che permette di stampare tutte le informazioni di tipo T con relativa molteplicita memorizzate nell’array di un oggetto di ` C<T,size>.
8. Deve essere disponibile un opportuno overloading dell’operatore booleano di confronto per uguaglianza tra oggetti di C<T,size>.
*/

template<class T, unsigned int size>
class C;

template<class T, unsigned int size>
std::ostream& operator<<(std::ostream& os, const C<T, size>& c);

template<class T, unsigned int size>
class C
{
	friend std::ostream& operator<< <T, size>(std::ostream& os, const C& c);

private:
	class MultiInfo
	{
		friend class C<T, size>;
	public:
		T info;
		unsigned int m;
		MultiInfo(const T& info = T(), unsigned int m = 0) : info(info), m(m) {  };

		bool operator==(const MultiInfo& mi) const
		{
			return mi.info == info && mi.m == m;
		}
	};

	unsigned int length;

	MultiInfo *mi;

	static MultiInfo* copia(MultiInfo *mi, unsigned int length)
	{
		MultiInfo *miTmp = new MultiInfo[length];

		for(int i = 0; i < length; i++)
		{
			miTmp[i] = mi[i];
		}

		return miTmp;
	}

	static void distruggi(MultiInfo *mi)
	{
		delete[] mi;
	}

public:
	C(const T& t, int k) : mi(new MultiInfo[size]), length(size)
	{
		k = k < 1 ? 0 : k;

		for(int i = 0; i < length; i++)
		{
			mi[i] = MultiInfo(t, k);
		}
	}

	C(const C& c) : mi(copia(c.mi, c.length)), length(c.length) {  }

	~C() { distruggi(mi); }

	C& operator=(const C& c)
	{
		if(this != &c)
		{
			distruggi(mi);

			mi = copia(c.mi, c.length);
		}

		return *this;
	}

	T* operator[](int i) const
	{
		if(i < 0 || i >= length) return nullptr;

		return &(mi[i].info);
	}

	unsigned int getLength() const
	{
		return length;
	}

	bool operator==(const C& c) const
	{
		if(this == &c) return true;
		if(c.getLength() != length) return false;

		bool equal = true;

		for(int i = 0; i < length && equal; ++i)
		{
			equal &= c.mi[i] == mi[i];
		}

		return equal;
	}

	unsigned int occorrenze(const T& t) const
	{
		unsigned int sum = 0;

		for(int i = 0; i < length; ++i)
		{
			if(mi[i].info == t)
			{
				sum += mi[i].m;
			}
		}

		return sum;
	}
};

template<class T, unsigned int size>
std::ostream& operator<<(std::ostream& os, const C<T, size>& c)
{
	for(int i = 0; i < c.getLength(); ++i)
	{
		os << i << " : " << c.mi[i].info << ", " << c.mi[i].m << std::endl;
	}

	return os;
}

#endif
