#ifndef _WEAPONHPP_CPP_
# define _WEAPONHPP_CPP_
#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		const std::string &getType() const;
		void  setType(std::string NewType);
};

#endif