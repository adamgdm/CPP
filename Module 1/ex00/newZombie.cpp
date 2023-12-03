#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* pointer = new(std::nothrow) Zombie(name);
	if (!pointer)
		return (NULL);
	return (pointer);
}