#ifndef AMAZONIA_H
#define AMAZONIA_H

#include <vector>
#include <typeinfo>

#include "itcstaff.h"

class Amazonia
{
private:
	class SmartP
	{
	private:
		ITCStaff *ptr;

	public:
		SmartP(ITCStaff *ptr) : ptr(ptr->clone()) {  }

		SmartP(const SmartP& sp) : ptr(sp.ptr->clone()) {  }

		~SmartP() { delete ptr; }

		SmartP& operator=(const SmartP& sp)
		{
			if(this != &sp)
			{
				delete ptr;

				ptr = sp.ptr->clone();
			}

			return *this;
		}

		SmartP& operator*()
		{
			return *(ptr);
		}

		SmartP* operator->()
		{
			return ptr;
		}
	};

	std::vector<SmartP *> v;

public:
	bool insert(SWEngineer *p, unsigned int k)
	{
		unsigned int num = 0;

		for(auto it = v.begin(); it != b.end() && num < k; ++it)
		{
			if(typeid(*(*it)) == typeid(SWEngineer) && (*it)->getSicurezza())
			{
				++num;
			}
		}

		bool isLess = num < k;

		if(isLess)
		{
			v.push_back(p);
		}

		return isLess;
	}

	std::vector<HWEngineer> fire(double s)
	{
		std::vector<HWEngineer> hwv;

		for(auto it = v.begin(); it != v.end(); ++it)
		{
			if((*it)->salary() > s)
			{
				if(typeid(*(*it)) == typeid(HWengineer))
				{
					hwv.push_back(*(*it));
				}

				v.erase(it);
			}
		}

		return hwv;
	}

	std::vector<SWEngineer *> masterInf()
	{
		std::vector<SWEngineer *> swv;

		for(auto it = v.begin(); it != v.end(); ++it)
		{
			if(typeid(*(*it)) == typeid(SWEngineer))
			{
				if(*it->getLaurea() == Laurea::Informatica && *(*it).isMagistrale())
				{
					swv.push_back((*(*it).clone());
				}
			}
		}

		return swv;
	}
}

#endif
