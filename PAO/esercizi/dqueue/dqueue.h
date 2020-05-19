#ifndef DQUEUE_H
#define DQUEUE_H

/*
1. Coda<T> non puo usare i contenitori STL come campi dati (inclusi puntatori e riferimenti a contenitori STL). `
2. Il parametro di tipo del template Coda<T> ha come valore di default double.
3. Gestione della memoria senza condivisione.
4. Deve essere disponibile un costruttore di default che costruisce la coda vuota.
5. Deve essere disponibile un costruttore Coda(int k, const T& t) che costruisce una coda contenente k copie dell’elemento
t.
6. Deve essere disponibile un metodo void insert(const T&) con il seguente comportamento: c.insert(t) inserisce l’elemento t in coda a c in tempo costante.
7. Deve essere disponibile un metodo T removeNext() con il seguente comportamento: se la coda c non e vuota, ` c.removeNext() rimuove l’elemento in testa alla coda c in tempo costante e lo ritorna; se invece c e vuota allora provoca undefined behaviour (da definirsi opportunamente).
8. Deve essere disponibile un metodo T* getNext() con il seguente comportamento: se la coda c non e vuota, ` c.getNext() ritorna un puntatore all’elemento in testa a c in tempo costante; se invece c e vuota ritorna il puntatore nullo. `
9. Overloading di operator< che implementa il confronto lessicografico tra code.
10. Overloading dell’operatore di somma che agisca come concatenazione: c + d ritorna la coda che si ottiene aggiungendo
d in coda a c.
11. Coda<T> rende disponibile un tipo iteratore costante Coda<T>::const iterator i cui oggetti permettono di iterare sugli elementi di una coda c senza permettere modifiche al contenuto di c.
*/

template<class T = double>
class DQueue;

template<class T = double>
DQueue<T> operator+(const DQueue<T>& q1, const DQueue<T>& q2);

template<class T>
class DQueue
{
	friend DQueue operator+ <T>(const DQueue& q1, const DQueue& q2);

private:
	class Nodo
	{
	public: 
		T info;
		Nodo *next, *prev;

		Nodo(const T& info = T(), Nodo *prev = nullptr, Nodo *next = nullptr) : 
			info(info), prev(prev), next(next) {  }

		~Nodo() { delete next; }
	};

	Nodo *first, *last;

	static Nodo* copia(Nodo *n, Nodo *prev, Nodo *&last)
	{
		if(!n) return nullptr;

		Nodo *tmp = new Nodo(n->info, prev);

		tmp->next = copia(n->next, tmp, last);

		if(!n->next) last = tmp;

		return tmp;
	}

	static void distruggi(Nodo *n)
	{
		delete n;
	}

	static bool isLess(Nodo *n1, Nodo *n2)
	{
		if(!n2) return false;

		if(!n1) return true;

		return n1->info < n2->info || (n1->info == n2->info && isLess(n1->next, n2->next));
	}

public:
	DQueue(int k = 0, const T& t = T()) : first(nullptr), last(nullptr)
	{
		for(int i = 0; i < k; ++i)
		{
			insert(t);
		}
	}

	DQueue(const DQueue& q) : first(copia(q.first, nullptr, last)) {  }
	
	~DQueue() { distruggi(first); }

	DQueue& operator=(const DQueue& q)
	{
		if(this != &q)
		{
			distruggi(first);

			first = copia(q.first, nullptr, last);
		}

		return *this;
	}

	void insert(const T& t)
	{
		Nodo *tmp = new Nodo(t, nullptr, first);

		if(first)
		{
			first->prev = tmp;

			first = tmp;
		}
		else
		{
			first = last = tmp;
		}
	}

	T removeNext()
	{
		Nodo *tmp = last;
		T value = last->info;

		last = last->prev;

		if(last)
		{
			last->next = nullptr;
		}
		else
		{
			first = last;
		}

		delete tmp;

		return value;
	}

	T* getNext() const
	{
		if(!last) return nullptr;

		return &(last->info); 
	}

	bool operator<(const DQueue& q) const
	{
		return (this != &q) && isLess(first, q.first);
	}

	class ConstIterator
	{
		friend class DQueue<T>;

	private:
		Nodo *ptr;
		bool pastTheEnd;

		ConstIterator(Nodo *ptr = nullptr, bool pastTheEnd = false) 
			: ptr(ptr), pastTheEnd(pastTheEnd) {  }

	public:
		const T& operator*() const
		{
			return ptr->info;
		}

		const T* operator->() const
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

		ConstIterator operator++(int)
		{
			ConstIterator tmp = *this;

			++(*this);

			return tmp;
		}

		ConstIterator& operator--()
		{
			if(ptr)
			{
				if(pastTheEnd)
				{
					pastTheEnd = false;
					--ptr;
				}
				else
				{
					ptr = ptr->prev;
				}
			}

			return *this;
		}

		ConstIterator operator--(int)
		{
			ConstIterator tmp = *this;

			--(*this);

			return tmp;
		}

		bool operator==(const ConstIterator& ci) const
		{
			return ptr == ci.ptr;
		}

		bool operator!=(const ConstIterator& ci) const
		{
			return ptr != ci.ptr;
		}
	};

	// friend ConstIterator;

	ConstIterator begin() const
	{
		return first;
	}

	ConstIterator end() const
	{
		return ConstIterator(last + 1, true);
	}
};

template<class T>
DQueue<T> operator+(const DQueue<T>& q1, const DQueue<T>& q2)
{
	DQueue<T> q0;

	typename DQueue<T>::Nodo *tmp = q1.first;

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
