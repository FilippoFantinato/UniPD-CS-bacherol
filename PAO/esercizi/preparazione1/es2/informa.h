#ifndef INFORMA_H
#define INFORMA_H

#include <vector>
#include <typeinfo>

#include "workout.h"

class InForma
{
private:
	std::vector<const Workout *> workouts;

public:
	std::vector<Nuoto *> vasche(unsigned int v) const
	{
		std::vector<Nuoto *> vn;

		for(auto it = workouts.begin(); it != workouts.end(); ++it)
		{
			const Nuoto *tmp = dynamic_cast<const Nuoto *>(*it);

			if(tmp && tmp->getNumeroVasche() > v)
			{
				vn.push_back(tmp->clone());
			}
		}

		return vn;
	}

	std::vector<Workout *> calorie(unsigned int x) const
	{
		std::vector<Workout *> vw;

		for(auto it = workouts.begin(); it != workouts.end(); ++it)
		{
			if((*it)->calorie() > x && typeid(*(*it)) != typeid(Rana))
			{
				vw.push_back((*it)->clone());
			}
		}

		return vw;
	}

	void removeNuoto()
	{
		unsigned int maxCalorie = 0;

		std::vector<const Workout *> vn;

		for(auto it = workouts.begin(); it != workouts.end(); ++it)
		{
			const Nuoto *al = dynamic_cast<const Nuoto *>(*it);

			if(al)
			{
				unsigned int tmpCalorie = al->calorie();

				vn.push_back(al);

				if(tmpCalorie > maxCalorie) maxCalorie = tmpCalorie; 
			}

		}

		for(auto it = vn.begin(); it != vn.end(); ++it)
		{
			unsigned int tmpCalorie = (*it)->calorie();

			if(tmpCalorie == maxCalorie) workouts.erase(it);
		}
	}

};

#endif
