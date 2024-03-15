#include "ClapTrap.hpp"

int main()
{
	{
		ClapTrap roboT("ZOBI");

		roboT.attack("cyborg");
		roboT.takeDamage(10);
		roboT.beRepaired(10);

		roboT.attack("cyborg");
		roboT.beRepaired(10);
	}
    return 0;
}