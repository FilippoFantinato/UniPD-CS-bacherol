#ifndef SEDEMOON_H
#define SEDEMOON_H

#include <vector>
#include <typeinfo>

#include "Cliente.h"

class SedeMoon
{
private:
	std::vector<Cliente *> clienti;

public:
	void aggiungiCliente(const Cliente& c)
	{
		clienti.push_back(c.clone());
	}

	double incassoMensileCorrente()
	{
		double costo = 0;

		for(auto it = clienti.begin(); it != clienti.end(); ++it)
		{
			costo = (*it)->costoMeseCorrente();
		}

		return costo;
	}

	int numClientiAbbonatiOltreSoglia()
	{
		unsigned int n = 0;

		for(auto it = clienti.begin(); it != clienti.end(); ++it)
		{
			if(typeid(*(*it)) == typeid(Abbonamento))
			{
				Abbonamento* cliente = static_cast<Abbonamento*>(*it);

				if(cliente->getSogliaTempoMassimoTelefonate() < cliente->getMinutiTelefonate())
				{
					++n;
				}
			}
		}

		return n;
	}

	std::vector<AlMinuto *> alMinutoSMS(int x)
	{
		std::vector<AlMinuto *> alm;

		for(auto it = clienti.begin(); it != clienti.end(); ++it)
		{
			if(typeid(*(*it)) == typeid(AlMinuto) && (*it)->getNumeroSMS() > x)
			{
				alm.push_back(static_cast<AlMinuto *>(*it));
			}
		}

		return alm;
	}
};

#endif
