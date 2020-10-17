#ifndef BOLLETTA_H
#define BOLLETTA_H

class Telefonata
{
private:
	int x;

public:
	Telefonata(int x) : x(x)
	{

	}

};

class Bolletta
{
friend class Iteratore;

private:
	class Nodo
	{
		public:
			Telefonata info;
			Nodo *next;

			Nodo();
			Nodo(const Telefonata& x, Nodo *p) : info(x), next(p) {  }

			~Nodo();
	};

	Nodo *first;

	static Nodo* copia(Nodo *root);
	static Nodo* distruggi(Nodo *root);

public:
	class Iteratore
	{
		friend class Bolletta;

	private:
		Bolletta::Nodo *punt;

	public:
		bool operator==(Iteratore) const;
		bool operator!=(Iteratore) const;

		Iteratore& operator++(); // prefisso
		Iteratore& operator++(int); // postfisso


	};

	Bolletta() : first(nullptr) {  }
	Bolletta(Bolletta &b) : first(copia(b.first)) {  } 	// Copia profonda
	~Bolletta(); 										// Distruzione profonda

	Bolletta& operator=(Bolletta *b);					// Assegnazione profonda

	bool vuota() const;
	void aggiungi_telefonata();
	void togli_telefonata();
	Telefonata estrai_una();

	// Metodi che usano iteratore
	Iteratore begin() const;
	Iteratore end() const;
	Telefonata& operator[](Iteratore) const;
};

#endif
