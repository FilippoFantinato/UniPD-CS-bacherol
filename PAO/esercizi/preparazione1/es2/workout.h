#ifndef WORKOUT_H
#define WORKOUT_H

class Workout
{
private:
	unsigned int durata;

public:
	unsigned int getDurata() const
	{
		return durata;
	}

	virtual Workout* clone() const = 0;

	virtual unsigned int calorie() const = 0;
};

class Corsa : public Workout
{
private:
	double distanza;

public:
	double getDistanza() const
	{
		return distanza;
	}

	virtual Corsa* clone() const
	{
		return new Corsa(*this);
	}

	virtual unsigned int calorie() const
	{
		return 500 * distanza * distanza / getDurata();
	}
	
};

class Nuoto : public Workout
{
private:
	unsigned int numeroVasche;

public:
	unsigned int getNumeroVasche() const
	{
		return numeroVasche;
	}

	virtual Nuoto* clone() const = 0;
};

class StileLibero : public Nuoto
{
public:
	virtual StileLibero* clone() const
	{
		return new StileLibero(*this);
	}

	virtual unsigned int calorie() const
	{
		return (getDurata() < 10 ? 35 : 40) * getNumeroVasche();
	}
};

class Dorso : public Nuoto
{
public:
	virtual Dorso* clone() const
	{
		return new Dorso(*this);
	}

	virtual unsigned int calorie() const
	{
		return (getDurata() < 15 ? 30 : 35) * getNumeroVasche();
	}
};

class Rana : public Nuoto
{
public:
	virtual Rana* clone() const
	{
		return new Rana(*this);
	}

	virtual unsigned int calorie() const
	{
		return 25 * getNumeroVasche();
	}
};

#endif
