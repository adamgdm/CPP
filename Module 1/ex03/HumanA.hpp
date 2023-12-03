#ifndef _HUMANAHPP_CPP_
# define _HUMANAHPP_CPP_

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon		&Glock;
	public:
		HumanA(std::string name, Weapon &Glock);
		HumanA(HumanA &other);
		~HumanA();

		void attack();
};

#endif