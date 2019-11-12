#ifndef TREE_H
#define TREE_H

#include <iostream>

template <class T>
class Tree
{
private:

	friend std::ostream& operator<< (std::ostream& os, const Tree<T>& t);

	class Node
	{
	public:
		T info;
		Node *sx, c, dx;

		Node(const T& t = T(), Node *s = 0, Node *c = 0, Node *d = 0) : info(t), sx(s), c(c), dx(d) {  };
		~Node();

		// std::ostream& recursivePrint(std::ostream& os)
		// {
		// 	os << info << ":";

		// 	if(sx) sx->recursivePrint(os);
		// 	if(c) c->recursivePrint(os);
		// 	if(dx) dx->recursivePrint(os);

		// 	return os;
		// }
		
	};

	Node *root;

	static Node *copy(Node *p)
	{
		if(!p) return nullptr;

		return new Node(p->info, copy(p->sx), copy(p->c), copy(p->dx));
	}

	static void destroy(Node *p)
	{
		if(!p) return;

		destroy(p->sx); destroy(p->c); destroy(p->dx);
	}

	static bool find(Node *p, const T& t)
	{
		if(!p) return false; 

		return p->info == t || find(p->sx, t) || find(p->c, t) || find(p->dx, t);
	}

	static bool recursiveEquality(Node *p1, Node *p2)
	{
		if(!p1 && !p2) return true;
		if(!p2 || !p1) return false;

		return p1->info && p2->info && 
				recursiveEquality(p1->sx, p2->sx) && 
				recursiveEquality(p1->c, p2->c) && 
				recursiveEquality(p1->dx, p2->dx);
	}

	static std::ostream& recursivePrint(std::ostream& os, Node *p)
	{
		if(!p) return os;

		return os << p->info << ":" << 
				recursivePrint(os, p->sx) << 
				recursivePrint(os, p->c) << 
				recursivePrint(os, p->dx);
	}

public:
	Tree() : root(nullptr) {  };
	Tree(const Tree& t): root(copy(t.root)) {  };
	~Tree();

	void insert(const T& t)
	{
		root = new Node(t, root, copy(root), copy(root));
	}

	bool search(const T& t) const
	{
		return find(root, t);
	}

	Tree& operator=(const Tree& t)
	{
		if(this != &t)
		{
			destroy(root);
			root = copy(t.root);
		}
	}

	bool operator==(const Tree& t) const
	{
		return recursiveEquality(root, t.root);
	}
};

// template<class T>
// std::ostream& operator<< (std::ostream& os, const Tree<T>& t)
// {
// 	return t.root ? t.root->recursivePrint(os) : os;
// }

template<class T>
std::ostream& operator<< (std::ostream& os, const Tree<T>& t)
{
	return t.recursivePrint(os, t.root);
}

#endif
