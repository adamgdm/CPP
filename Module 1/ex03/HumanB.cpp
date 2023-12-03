#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) , Glock(NULL)
{

}

HumanB::HumanB(std::string name, Weapon &Glock) : name(name)
{
	this->Glock = &Glock;
}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
	if (this->Glock == NULL)
		std::cout << this->name << " Cant attack because ma3ndo walo msikin" << std::endl;
	else	
		std::cout << this->name << " attacks with their " << this->Glock->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &Glock)
{
	this->Glock = &Glock;
}