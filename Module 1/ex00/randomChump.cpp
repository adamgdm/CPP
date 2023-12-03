#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie Braineater = Zombie(name);
	Braineater.announce();
}