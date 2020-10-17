#ifndef STACK_H
#define STACK_H

#include <iostream>

/*
Definire un template di classe stack<T,num> i cui oggetti rappresentano uno stack di valori di un generico tipo T con al
massimo num elementi. Si ricorda che lo stack implementa la politica di inserimento/rimozione LIFO: Last In First Out. Lo
stack si dice pieno quando memorizza num elementi. Il template stack<T,num> deve soddisfare i seguenti vincoli e rendere
disponibili le seguenti funzionalita:`
1. stack<T,num> non puo usare i contenitori STL come campi dati (inclusi puntatori e riferimenti a contenitori STL). `
2. Il template stack<T,num> ha come tipo T default char e come valore num default 100.
3. Un costruttore di default che costruisce lo stack vuoto.
4. Un costruttore stack(t,k) che costruisce uno stack di k elementi che memorizzano il valore t; se k > num allora lo
stack sara di ` num elementi, se k < 0 allora lo stack sara vuoto. `
5. Metodi bool isEmpty() e bool isFull() che testano se lo stack e vuoto o pieno. `
6. Metodo unsigned int size() che ritorna il numero di elementi memorizzati dallo stack.
7. Gestione della memoria senza condivisione.
8. Operatore esplicito di conversione ad int che ritorna la dimensione dello stack.
9. Metodo bool push(const T&): in una chiamata s.push(t), inserisce al top dello stack s un nuovo elemento che
memorizza il valore t se cio non provoca il superamento del limite ` num, altrimenti lascia lo stack s invariato. Ritorna
true se l’inserimento e avvenuto, ` false altrimenti.
10. Metodo void pop(): in una chiamata s.pop() rimuove l’elemento al top dello stack s non vuoto; se s e vuoto lo lascia `
inalterato.
11. Metodo T top(): s.top() ritorna una copia dell’elemento al top dello stack s non vuoto; se s e vuoto, allora ` s.top()
provoca undefined behaviour (da definirsi opportunamente).
12. Metodo T bottom(): s.bottom() ritorna una copia dell’elemento al bottom dello stack s non vuoto; se s e vuoto, `
allora s.bottom() provoca undefined behaviour (da definirsi opportunamente).
13. Metodo bool search(const T&): in una chiamata s.search(t) ritorna true se il valore t occorre nello stack s,
altrimenti ritorna false.
14. Metodo void flush() che svuota lo stack di invocazione.
15. Overloading dell’operatore di somma tra stack: s1 + s2 deve ritornare un nuovo stack ottenuto impilando s2 sopra s1 (il
bottom di s2 e quindi sopra il top ` s1), sino all’eventuale raggiungimento del massimo num di elementi.
16. Overloading dell’operatore di uguaglianza.
17. Overloading dell’operatore di output.
*/

template<class T = char, int num = 100>
class Stack;

template<class T = char, int num = 100>
std::ostream& operator<<(std::ostream& os, const Stack<T, num>& s);


template<class T, int num>
class Stack
{
	friend std::ostream& operator<< <T, num>(std::ostream& os, const Stack& s);

private:
	T *p;
	unsigned int size;
	const unsigned int capacity;

	static T* copia(T *p, unsigned int size)
	{
		T *tmp = new T[size];

		for(int i = 0; i < size; ++i)
		{
			tmp[i] = p[i];
		}

		return tmp;
	}

	static void distruggi(T *p)
	{
		delete[] p;
	}

public:
	Stack() : p(new T[num]), size(0), capacity(num) {  }
	Stack(const T& t, unsigned int k) : p(new T[num]), size(k < 0 ? 0 : k > num ? num : k), capacity(num)
	{
		for(int i = 0; i < size; i++)
		{
			p[i] = t;
		}
	}
	Stack(const Stack& s) : p(copia(s.p)) {  }

	~Stack() { distruggi(p); }

	Stack& operator=(const Stack& s)
	{
		if(this != &s)
		{
			distruggi(p);

			p = copia(s.p, s.size);

			size = s.size;
		}

		return *this;
	}

	unsigned int length() const
	{
		return size;
	}

	bool isEmpty() const
	{
		return size == 0;
	}

	bool isFull() const
	{
		return size == capacity;
	}

	bool push(const T& t)
	{
		if(size == capacity) return false;

		p[size] = t;

		++size;

		return true;
	}

	void pop()
	{
		if(size)
		{
			--size;
		}
	}

	T top() const
	{
		if(size)
		{
			return p[size - 1];
		}
		else
		{
			std::cout << "ERROR" << std::endl;
			return T();
		}
	}

	T bottom() const
	{
		if(size)
		{
			return p[0];
		}
		else
		{
			std::cout << "ERROR" << std::endl;
			return T();
		}
	}

	bool search(const T& t)
	{
		bool found = false;

		for (int i = 0; i < size && !found; ++i)
		{
			found = p[i] == t;
		}

		return found;
	}

	void flush()
	{
		distruggi(p);

		p = new T[capacity];

		size = 0;
	}
	
	operator int() const
	{
		return size;
	}

	Stack& operator+(const Stack& s)
	{
		int actualSize = size;

		for(int i = 0; i < s.size && actualSize + i < capacity; ++i)
		{
			push(s.p[i]);
		}

		return *this;
	}

	bool operator==(const Stack& s)
	{
		if(this == &s) return true;
		if(size != s.size) return false;

		bool equal = true;

		for (int i = 0; i < size && equal; ++i)
		{
			equal = p[i] == s.p[i];
		}

		return equal;
	}

};

template<class T, int num>
std::ostream& operator<<(std::ostream& os, const Stack<T, num>& s)
{
	for (int i = 0; i < s.length(); ++i)
	{
		os << s.p[i] << " ";
	}

	return os;
}

#endif
