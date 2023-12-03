#ifndef _HUMANBHPP_CPP_
# define _HUMANBHPP_CPP_

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon		*Glock;
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon &Glock);
		// HumanB(HumanB &other);
		~HumanB();

		void setWeapon(Weapon &Glock);
		void attack();
};

#endif