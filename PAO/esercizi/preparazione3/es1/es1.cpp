/*
Scrivere un template di classe SmartP<T> di puntatori smart a T che definisca assegnazione profonda, costruzione di copia profonda e
distruzione profonda di puntatori smart. Il template SmartP<T> dovra essere dotato di una interfaccia pubblica che permetta di ` compilare
correttamente il seguente codice, la cui esecuzione dovra` provocare esattamente le stampe riportate nei commenti.
*/

#include <iostream>

using namespace std;

template<class T>
class SmartP
{
private:
	T *p;

public:
	SmartP(const T *p = nullptr) : p(p ? new T(*p) : nullptr) {  }
	SmartP(const SmartP& sp) : p(new T(*(sp.p))) {  }

	~SmartP() { delete p; }

	SmartP& operator=(const SmartP& sp)
	{
		if(this != &sp)
		{
			delete p;

			p = new T(*(sp.p));
		}

		return *this;
	}

	T& operator*() const
	{
		return *p;
	}

	T* operator->() const
	{
		return p;
	}

	bool operator==(const SmartP& sp) const
	{
		return sp.p == p;
	}

	bool operator!=(const SmartP& sp) const
	{
		return sp.p != p;
	}
};

class C {
public:
	int* p;
	C(): p(new int(5)) {}
};

int main() {
	const int a=1; const int* p=&a;
	SmartP<int> r; SmartP<int> s(&a); SmartP<int> t(s);
	cout << *s << " " << *t << " " << *p << endl; // 1 1 1
	*s=2; *t=3;
	cout << *s << " " << *t << " " << *p << endl; // 2 3 1
	r=t; *r=4;
	cout << *r << " " << *s << " " << *t << " " << *p << endl; // 4 2 3 1
	cout << (s == t) << " " << (s != p) << endl; // 0 1
	C c; SmartP<C> x(&c);
	cout << *(c.p) << " " << *(x->p) << endl; // 5 5
	*(c.p)=6;
	cout << *(c.p) << " " << *(x->p) << endl; // 6 6
	SmartP<C>* q = new SmartP<C>(&c);
	delete q;
	cout << *(x->p) << endl; // 6
}