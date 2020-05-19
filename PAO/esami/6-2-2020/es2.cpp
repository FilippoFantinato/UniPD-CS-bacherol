#include <iostream>

template<class T>
class SmartP
{
private:
	T* p;

public:
	SmartP(const T* t = nullptr) : p(t ? new T(*t) : nullptr) {  }
	SmartP(const SmartP& sp) : p(sp.p ? new T(*(sp.p)) : nullptr) {  }
	~SmartP() { delete p; }

	SmartP& operator=(const SmartP& sp)
	{
		if(this != &sp)
		{
			delete p;

			p = sp.p ? new T(*(sp.p)) : nullptr;
		}

		return *this;
	}

	T& operator*() const
	{
		return *(p);
	}

	bool operator==(const SmartP& sp) const
	{
		return sp.p == p;
	}
};



class C
{
public:
	int* p;
	C(): p(new int(5)) {}
};
int main() {
	const int a=1; const int* p=&a;
	SmartP<int> r; SmartP<int> s(&a); SmartP<int> t(s);
	std::cout << *s << " " << *t << " " << *p << std::endl; // 1 1 1
	std::cout << (s == t) << " " << !(s == p) << std::endl; // 0 1
	*s=2; *t=3;
	std::cout << *s << " " << *t << " " << *p << std::endl; // 2 3 1
	r=t; *r=4;
	std::cout << *r << " " << *s << " " << *t << " " << *p << std::endl; // 4 2 3 1
	C c; SmartP<C> x(&c); SmartP<C> y(x);
	std::cout << (x == y) << std::endl; // 0
	std::cout << *(c.p) << std::endl; // 5
	*(c.p)=6;
	std::cout << *(c.p) << std::endl; // 6
	SmartP<C>* q = new SmartP<C>(&c);
	delete q;
}