#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Glock) : name(name), Glock(Glock)
{

}

HumanA::HumanA(HumanA &other) : Glock(other.Glock)
{
	this->name = other.name;
}

HumanA::~HumanA()
{
	
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->Glock.getType() << std::endl;
}