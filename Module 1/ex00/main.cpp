#include "Zombie.hpp"

int main()
{
 	// Allocates dynamically :
	Zombie *simo = newZombie("simo");
	simo->announce();

	randomChump("khalid");
	delete simo;
}