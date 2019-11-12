/*
Definire un template di classe dList<T> i cui oggetti rappresentano una struttura dati lista doppiamente concatenata (doubly link
list) per elementi di uno stesso tipo T. Il template dList<T> deve soddisfare i seguenti vincoli:

1. Gestione della memoria senza condivisione.

2. dList<T> rende disponibile un costruttore dList (int k, const T& t) che costruisce una lista contenente ko o
di questi nodi memorizza una copia di t.

n

3. dList<T> permette l'inserimento in testa ed in coda ad una lista in tempo O(1) (cioè costante):

• Deve essere disponibile un metodo void insert Front (const T&) con il seguente comportamento: dl.insertFront
inserisce l'elemento t in testa a dl in tempo O(1).

. Deve essere disponibile un metodo void insertBack (const T&) con il seguente comportamento: dl.insertBack (t
inserisce l'elemento t in coda a dl in tempo O(1).

4. dList<T> rende disponibile un opportuno overloading di operator< che implementa l'ordinamento lessicografico (ad eser
si ricorda che per l'ordinamento lessicografico tra stringhe abbiamo che "campana" < "cavolo" e che
"eccellente" < "ottimo").

5. dList<I> rende disponibile un tipo iteratore costante dList<T> ::const iterator i cui oggetti permettono di iterare sug

elementi di una lista.
*/

#include <list>

#ifndef DLIST_H
#define DLIST_H

template <class T>
class DList
{
private:
	class Node
	{
	public: 
		T info;
		Node *prev, *next;
		std::list<int> a;

		Node(const T& t = T(), Node *p = nullptr, Node *n = nullptr) : info(t), prev(p), next(n) {  }
		~Node() { delete next; }
	};

	Node *first, *last;

	static Node *copy(Node *p, Node *&l)
	{
		// Base case
		if(!p) return nullptr;

		Node *prev = new Node(p->info, nullptr, nullptr);
		Node *next = prev;
		Node *start = prev;

		while(p->next)
		{
			next = new Node(p->next->info, prev, nullptr);
			prev = p->next;
			p = p->next;
			prev = prev->next;
		}

		l = next;

		return start;
	}

	static bool isLess(Node *f1, Node *f2)
	{
		if(f2 == nullptr) return false;
		if(f1 == nullptr) return true;

		return f1->info < f2->info || 
				(f1->info == f2->info && isLess(f1->next, f2->next));
	}

public:
	DList(unsigned int k = 0, const T& t = T()) : last(nullptr), first(nullptr)
	{
		for (int i = 0; i < k; ++i)
		{
			insertBack(t);
		}
	}

	DList(const DList& d) : first(copy(d.root, last)) { /*delete first; first = copy(d.root);*/ }

	~DList()
	{
		delete first;
	}

	class ConstIterator
	{
		friend class DList<T>;
	private:
		bool pastTheEnd; // true iff const itr e' "past-the-end"	
		Node *ptr;
		
		ConstIterator(Node *n, bool pte = false) : ptr(n), pastTheEnd(pte) {  }

	public:
		ConstIterator() : ptr(nullptr), pastTheEnd(false) {  }

		const T& operator*() const
		{
			return ptr->info;
		}

		const T* operator->() const
		{
			return &(ptr->info);
		}

		/*ConstIterator& operator++(int)
		{
			ConstIterator *tmp = this;

			ptr = ptr->next;

			return *tmp;
		}*/

		ConstIterator& operator++()
		{
			if(ptr)
			{
				if(!pastTheEnd)
				{
					if(ptr->next) { ptr = ptr->next;  }
					else { ++ptr; pastTheEnd = true; } 
				}
			}

			return *this;
		}

		ConstIterator& operator--()
		{
			if(ptr)
			{
				if(pastTheEnd) { --ptr; pastTheEnd = false; }
				else { ptr = ptr->prev; }
			}


			return *this;
		}

		bool operator==(const ConstIterator& x) const
		{
			return ptr == x.ptr;
		}

		bool operator!=(const ConstIterator& x) const
		{
			return ptr != x.ptr;
		}
	};

	ConstIterator begin()
	{
		return first;
	}

	ConstIterator end()
	{
		if(last)
		{
			return ConstIterator(last + 1, true);

		}
		else
		{
			return nullptr;
		}

	}

	DList& operator=(DList &d)
	{
		if(this != &d)
		{
			delete first;
			first = copy(d.first, last);
		}

		return *this;
	}

	bool operator<(const DList& list)
	{
		return isLess(first, list.first);
	}

	void insertFront(const T& t)
	{
		first = new Node(t, nullptr, first);

		if(first->next)
		{
			first->next->prev = first;
		}
		else
		{
			last = first;
		}
	}

	void insertBack(const T *t)
	{
		last = new Node(t, last, nullptr);

		if(last->prev)
		{
			last->prev->next = last;
		}
		else
		{
			first = last;
		}
	}
};

#endif
