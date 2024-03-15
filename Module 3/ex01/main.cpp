#include "ScavTrap.hpp"

int main()
{
	{
		ClapTrap roboT("roboT");

		roboT.attack("cyborg");
		roboT.takeDamage(10);
		roboT.beRepaired(10);

		roboT.attack("cyborg");
		roboT.beRepaired(10);
	}
	std::cout << std::endl << std::endl;
	{
	    ScavTrap r2d2("r2d2");

    	r2d2.attack("stormtrooper");
    	r2d2.takeDamage(20);
    	r2d2.beRepaired(20);
    	r2d2.guardGate();
	}
    return 0;
}