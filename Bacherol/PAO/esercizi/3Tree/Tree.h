#ifndef TREE_H
#define TREE_H

#include <iostream>

/* 
Definire un template di classe albero<T> i cui oggetti rappresentano 
un albero 3-ario ove i nodi memorizzano dei valori di tipo T ed hanno 
3 figli (invece dei 2 figli di un usuale albero binario). Il template 
albero<T> deve soddisfare i seguenti vincoli:
1. Deve essere disponibile un costruttore di default che costruisce l’albero vuoto. 
2. Gestione della memoria senza condivisione.
3. Metodo void insert(const T&): a.insert(t) inserisce nell'albero a una nuova radice che memorizza il valore t ed avente come figli 3 copie di a 
4. Metodo bool search(const T&): a.search(t) ritorna true se t occorre nell'albero a, altrimenti ritorna false.
5. Overloading dell'operatore di uguaglianza.
6. Overloading dell'operatore di output.

*/
template <class T>
class Tree;

template <class T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& t);

template <class T>
class Tree
{
	friend std::ostream& operator<< <T>(std::ostream& os, const Tree& t);

private:
	class Nodo
	{
	public: 
		T info;
		Nodo *l, *m, *r;

		Nodo(const T& info, Nodo *l = nullptr, Nodo *m = nullptr, Nodo *r = nullptr) : info(info), l(l), m(m), r(r) {  }

		std::ostream& print(std::ostream& os)
		{
			os << info << " ";

			if(l) l->print(os) << " ";
			if(m) m->print(os) << " ";
			if(r) r->print(os) << " ";

			return os;
		}
	};

	Nodo *root;

	static Nodo* copia(Nodo *root)
	{
		if(root == nullptr) return nullptr;

		return new Nodo(root->info, copia(root->l), copia(root->m), copia(root->r));
	}

	static void distruggi(Nodo *root)
	{
		if(root)
		{
			distruggi(root->l);
			distruggi(root->m);
			distruggi(root->r);

			delete root;
		}
	}

	static bool equalRecursive(Nodo *root, Nodo *tRoot)
	{
		if(root == nullptr && tRoot == nullptr) return true;

		if(!root || !tRoot) return false;
 
		return root->info == tRoot->info && 
				equalRecursive(root->l, tRoot->l) && 
				equalRecursive(root->m, tRoot->m) && 
				equalRecursive(root->r, tRoot->r);
	}

	static bool searchRecursive(Nodo *root, const T& info)
	{
		if(!root) return false;

		return root->info == info || 
				searchRecursive(root->l, info) || 
				searchRecursive(root->m, info) || 
				searchRecursive(root->r, info);
	}

public:
	// Albero vuoto iff root == nullptr
	Tree() : root(nullptr) {  }
	Tree(const Tree& t) : root(copia(t.root)) {  } 
	~Tree() { distruggi(root); }

	Tree& operator=(const Tree& t)
	{
		if(this != &t)
		{
			distruggi(root);

			root = copia(t.root);
		}

		return *this;
	}

	void insert(const T& info)
	{
		root = new Nodo(info, copia(root), copia(root), copia(root));
	}

	bool search(const T& info) const
	{
		return searchRecursive(root, info);
	}

	bool operator==(const Tree& t) const
	{
		return equalRecursive(root, t.root);
	}

};

template <class T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& t)
{
	if(t.root) return t.root->print(os);
	return os;
}

#endif
