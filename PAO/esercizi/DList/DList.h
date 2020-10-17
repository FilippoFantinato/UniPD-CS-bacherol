#ifndef DLIST_H
#define DLIST_H

/*
Definire un template di classe dList<T> i cui oggetti rappresentano una struttura dati lista doppiamente concatenata (doubly linked list) per elementi di uno stesso tipo T. Il template dList<T> deve soddisfare i seguenti vincoli:

1. Gestione della memoria senza condivisione.

2. dList<T> rende disponibile un costruttore dList(unsigned int k, const T& t) che costruisce una 
lista contenente k nodi ed ognuno di questi nodi memorizza una copia di t.

3. dList<T> permette l’inserimento in testa ed in coda ad una lista in tempo O(1) (cioe` costante):
-- Deve essere disponibile un metodo void insertFront(const T&) con il seguente comportamento: dl.insertFront(t) inserisce l’elemento t in testa a dl in tempo O(1).
-- Deve essere disponibile un metodo void insertBack(const T&) con il seguente comportamento: dl.insertBack(t) inserisce l’elemento t in coda a dl in tempo O(1).

4. dList<T> rende disponibile un opportuno overloading di operator< che implementa l’ordinamento lessicografico (ad esempio, si ricorda che per l'ordinamento lessicografico tra stringhe abbiamo che "campana" < "cavolo" e che
"eccellente" < "ottimo").

5. dList<T> rende disponibile un tipo iteratore costante dList<T>::constiterator i cui oggetti permettono di iterare sugli elementi di una lista.

*/

template<class T>
class DList
{
private:
	class Nodo
	{
	public:
		T info;
		Nodo *prev, *next;

		Nodo(const T& info = T(), Nodo *prev = nullptr, Nodo *next = nullptr) 
			: info(info), prev(prev), next(next) {}

		~Nodo() { delete next; };
	};

	Nodo *first, *last;

	static Nodo* copia(Nodo *root, Nodo* prev, Nodo *& last)
	{
		if(!root) return nullptr;

		Nodo *tmp = new Nodo(root->info, prev);

		tmp->next = copia(root->next, tmp, last);

		if(!root->next) last = tmp;

		return tmp;
	}

	static bool isLess(Nodo *root1, Nodo *root2)
	{
		if(!root2) return false;

		if(!root1) return true;

		return root1->info < root2->info || (root1->info == root2->info && isLess(root1->next, root2->next));
	}

public:
	class ConstIterator
	{
		friend class DList<T>;
	private:
		Nodo *ptr;
		bool pastTheEnd;

		ConstIterator(Nodo *ptr, bool pastTheEnd = false) : ptr(ptr), pastTheEnd(pastTheEnd) {  }

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
			if(ptr && !pastTheEnd)
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

			return *this;
		}

		ConstIterator& operator--()
		{
			if(ptr && ptr->prev)
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

		bool operator==(const ConstIterator& ci)
		{
			return ptr == ci.ptr;
		}

		bool operator!=(const ConstIterator& ci)
		{
			return ptr != ci.ptr;
		}
	};

	DList(unsigned int k = 0, const T& t = T()) : first(nullptr), last(nullptr)
	{
		for(int i = 0; i < k; i++)
		{
			insertFront(t);
		}
	}

	DList(const DList& l) : first(copia(l.first, nullptr, last)) { }

	~DList() { delete first; }

	DList& operator=(const DList& l)
	{
		if(this != &l)
		{
			delete first;

			first = copia(l.first, nullptr, last);
		}

		return *this;
	}

	void insertFront(const T& t)
	{
		Nodo *tmp = new Nodo(t, nullptr, first);

		if(first)
		{
			first->prev = tmp;
		}
		else
		{
			last = tmp;
		}

		first = tmp;
	}

	void insertBack(const T& t)
	{
		Nodo *tmp = new Nodo(t, last, nullptr);

		if(last)
		{
			last->next = tmp;
		}
		else
		{
			first = tmp;
		}

		last = tmp;
	}

	ConstIterator begin()
	{
		return first;
	}

	ConstIterator end()
	{
		return ConstIterator(last + 1, true);
	}

	bool operator<(const DList& l) const
	{
		return isLess(first, l.first);
	}
};

#endif
