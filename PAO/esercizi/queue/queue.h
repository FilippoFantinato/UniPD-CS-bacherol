#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

/*
Definire un template di classe Coda<T> i cui oggetti rappresentano una struttura dati coda per elementi di uno stesso tipo T, ossia
la coda implementa l’usuale politica FIFO (First In First Out) di inserimento/estrazione degli elementi: gli elementi vengono
estratti nello stesso ordine in cui sono stati inseriti. Il template Coda<T> deve soddisfare i seguenti vincoli:
1. Coda<T> non puo usare i contenitori STL come campi dati (inclusi puntatori e riferimenti a contenitori STL). `
2. Il parametro di tipo del template Coda<T> ha come valore di default double.
3. Gestione della memoria senza condivisione.
4. Deve essere disponibile un costruttore di default che costruisce la coda vuota.
5. Deve essere disponibile un costruttore Coda(int k, const T& t) che costruisce una coda contenente k copie dell’elemento
t.
6. Deve essere disponibile un metodo void insert(const T&) con il seguente comportamento: c.insert(t) inserisce
l’elemento t in coda a c in tempo costante.
7. Deve essere disponibile un metodo T removeNext() con il seguente comportamento: se la coda c non e vuota, ` c.removeNext()
rimuove l’elemento in testa alla coda c in tempo costante e lo ritorna; se invece c e vuota allora provoca undefined be- `
haviour (da definirsi opportunamente).
8. Deve essere disponibile un metodo T* getNext() con il seguente comportamento: se la coda c non e vuota, ` c.getNext()
ritorna un puntatore all’elemento in testa a c in tempo costante; se invece c e vuota ritorna il puntatore nullo. `
9. Overloading di operator< che implementa il confronto lessicografico tra code.
10. Overloading dell’operatore di somma che agisca come concatenazione: c + d ritorna la coda che si ottiene aggiungendo
d in coda a c.
11. Coda<T> rende disponibile un tipo iteratore costante Coda<T>::const iterator i cui oggetti permettono di iterare
sugli elementi di una coda c senza permettere modifiche al contenuto di c.
*/

template<class T = char>
class Queue;

template<class T = char>
Queue<T>& operator+(const Queue<T>& q1, const Queue<T>& q2);

template<class T>
class Queue
{
	friend Queue& operator+ <T>(const Queue& q1, const Queue& q2);

private:
	class Nodo
	{
	public:
		T info;
		Nodo *next, *prev;

		Nodo(const T& info = T(), Nodo *next = nullptr) : info(info), next(next) {  }

		~Nodo() { delete next; }
	};

	// Coda vuota iff first = last = nullptr;
	Nodo *first, *last;

	static Nodo* copia(Nodo *nodo, Nodo *&last)
	{
		// Caso base: Nodo nullptr
		if(!nodo) return nullptr;

		// Passo induttivo: Si copia il nodo e si richiama la funzione copia sul nodo successivo

		Nodo *tmp = new Nodo(nodo->info, copia(nodo->next, last));

		if(!nodo->next) last = tmp;

		return tmp;
	}

	static void distruggi(Nodo *first)
	{
		delete first;
	}

	static bool isLess(Nodo *f1, Nodo *f2)
	{
		if(!f2) return false;
		if(!f1) return true;

		return f1->info < f2->info || (f1->info == f2->info && isLess(f1->next, f2->next)); 
	}

public:
	Queue(unsigned int k = 0, const T& t = T()) : first(nullptr), last(nullptr)
	{
		for (int i = 0; i < k; ++i)
		{
			insert(t);
		}
	}

	Queue(const Queue& q) : first(copia(first, last)) {  }

	~Queue() { distruggi(first); };

	Queue& operator=(const Queue& q)
	{
		if(this != &q)
		{
			distruggi(first);

			first = copia(q.first, last);
		}

		return *this;
	}

	void insert(const T& t)
	{
		Nodo *toAdd = new Nodo(t, first);

		if(!first)
		{
			last = toAdd;
		}

		first = toAdd;
	}
	
	T removeNext()
	{
		T toReturn;

		if(last)
		{
			if(last == first)
			{
				toReturn = last->info;

				delete last;

				first = last = nullptr;
			}
			else
			{
				toReturn = last->info;

				Nodo *tmp = first;

				while(tmp->next != last) tmp = tmp->next;

				delete last;

				last = tmp;

				last->next = nullptr;
			}
		}
		else
		{
			std::cout << "ERROR" << std::endl;
		}

		return toReturn;
	}

	T* getNext()
	{
		T* toReturn = nullptr;

		if(last)
		{
			toReturn = &(last->info);
		}
		
		return toReturn;
	}

	bool operator<(const Queue& q)
	{
		return (this != &q) && isLess(first, q.first);
	}

	class ConstIterator
	{
		friend class Queue<T>;
	private:
		Nodo *ptr;
		bool pastTheEnd;

		ConstIterator(Nodo *ptr = nullptr, bool pastTheEnd = false) : ptr(ptr), pastTheEnd(pastTheEnd) {  }

	public:
		const T& operator*()
		{
			return ptr->info;
		}

		const T* operator->()
		{
			return &(ptr->info);
		}

		ConstIterator& operator++()
		{
			if(ptr)
			{
				if(!pastTheEnd)
				{
					if(ptr->next)
					{
						ptr = ptr->next;
					}
					else
					{
						pastTheEnd = true;
						++ptr;
					}
				}
			}

			return *this;
		}

		ConstIterator& operator--()
		{
			if(ptr)
			{
				if()
			}
		}

		ConstIterator& operator==(const ConstIterator& ci)
		{
			return ci.ptr == ptr;
		}

		ConstIterator& operator!=(const ConstIterator& ci)
		{
			return ci.ptr != ptr;
		}
	};
};

template<class T>
Queue<T>& operator+(const Queue<T>& q1, const Queue<T>& q2)
{
	Queue<T> q0;
	typename Queue<T>::Nodo *tmp = q1.first;

	while(tmp)
	{
		q0.insert(tmp->info);

		tmp = tmp->next;
	}

	tmp = q2.first;

	while(tmp)
	{
		q0.insert(tmp->info);

		tmp = tmp->next;
	}

	return q0;
}

#endif
