#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente
{
private:
	unsigned int numeroTelefonate, sms;
	double minuti, trafficoDati;

public:
	static const double COSTO_TRAFFICO_DATI;

	unsigned int getNumeroTelefonate() const
	{
		return numeroTelefonate;
	}

	unsigned int getNumeroSMS() const
	{
		return sms;
	}

	double getMinutiTelefonate() const
	{
		return minuti;
	}

	double getTrafficoDati() const
	{
		return trafficoDati;
	}

	virtual Cliente* clone() const = 0;

	virtual double costoMeseCorrente() const = 0;	
};

const double Cliente::COSTO_TRAFFICO_DATI = 0.01;

class AlMinuto : public Cliente
{
public: 
	static const double COSTO_SCATTO_RISPOSTA;
	static const double COSTO_TELEFONATA;
	static const double COSTO_SMS;

	virtual AlMinuto* clone() const
	{
		return new AlMinuto(*this);
	}

	virtual double costoMeseCorrente() const
	{
		return getNumeroTelefonate() * COSTO_SCATTO_RISPOSTA + 
				getMinutiTelefonate() * COSTO_TELEFONATA + 
				getNumeroSMS() * COSTO_SMS + 
				getTrafficoDati() * COSTO_TRAFFICO_DATI;
	}

};

const double AlMinuto::COSTO_SCATTO_RISPOSTA = 0.15;
const double AlMinuto::COSTO_TELEFONATA = 0.2;
const double AlMinuto::COSTO_SMS = 0.1;

class Abbonamento : public Cliente
{
private:
	double costoFissoMensileAbbonamento;
	double sogliaTempoMassimoTelefonate;

public:
	static const double COSTO_TELEFONATE_OLTRE_SOGLIA;

	double getSogliaTempoMassimoTelefonate() const
	{
		return sogliaTempoMassimoTelefonate;
	}

	virtual Abbonamento* clone() const
	{
		return new Abbonamento(*this);
	}

	virtual double costoMeseCorrente() const
	{
		unsigned int minutiSforamento = getMinutiTelefonate() - sogliaTempoMassimoTelefonate;

		return costoFissoMensileAbbonamento +
				getTrafficoDati() * COSTO_TRAFFICO_DATI +
				minutiSforamento <= 0 ? 0 : COSTO_TELEFONATE_OLTRE_SOGLIA * minutiSforamento;
	}
};

const double Abbonamento::COSTO_TELEFONATE_OLTRE_SOGLIA = 0.3;

#endif
