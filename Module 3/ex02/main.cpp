#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	std::cout << std::endl << std::endl;
	{
	    FragTrap bb8("bb8");

		bb8.attack("droid");
		bb8.takeDamage(30);
		bb8.beRepaired(30);
		bb8.highFivesGuys();
	    return 0;
	}
    return 0;
}