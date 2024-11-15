#include <iostream>

class C
{
public:
	std::string s;
	C(std::string x = "1") : s(x) {  }
	~C() { std::cout << s << "Cd "; }

};

// funzione esterna, passaggio del parametro per valore
C& F(C& p)
{
	return p;
}

C w("3");// variabile globale

class D
{
public:
	static C c;
};

C D::c("4");

int main()
{
	std::cout << "PROGRAMMA UNO\n";
	C x("5"), y("6");
	D d;
	y = F(x); std::cout << "uno\n";
	C z = F(x); std::cout << "due\n";
}
