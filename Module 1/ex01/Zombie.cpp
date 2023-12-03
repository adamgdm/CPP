#include "Zombie.hpp"

void Zombie::nameTheZombie(std::string String)
{
	this->name = String;
}

Zombie::Zombie()
{
	
}

Zombie::~Zombie()
{
	std::cout << "\033[31m" << this->name <<"\033[37m has unfortunately died!" << std::endl;
}

void Zombie::announce()
{
	std::cout << "\033[32m" << this->name << "\033[37m: BraiiiiiiinnnzzzZ..." << std::endl;
}