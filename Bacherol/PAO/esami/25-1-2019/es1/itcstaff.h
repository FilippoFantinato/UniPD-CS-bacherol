#ifndef ITCSTAFF_H
#define ITCSTAFF_H

enum Laurea
{
	Informatica, Ingegneria, Altro
}

class ITCStaff
{
private:
	unsigned int stipendio;
	Laurea laurea;
	bool magistrale;

public:

	unsigned int getStipendio() const
	{
		return stipendio;
	}

	Laurea laure getLaurea() const
	{
		return laurea;
	}

	bool isMagistrale() const
	{
		return magistrale;
	}

	ITCStaff* clone() const = 0;
	double salary() const = 0;
};

class SWEngineer : public ITCStaff
{
private:
	bool sicurezza;

public:

	bool getSicurezza() const
	{
		return sicurezza;
	}

	SWEngineer* clone() const
	{
		return new SWEngineer(*this);
	}

	double salary() const
	{
		return getStipendio() + (sicurezza ? 500 : 0);
	}
};

class HWEngineer : public ITCStaff
{
private:
	unsigned int numeroTrasferte;

public:
	HWEngineer* clone() const
	{
		return new HWEngineer(*this);
	}

	double salary() const
	{
		return getStipendio() + numeroTrasferte * 300;
	}
};

#endif
