#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string type) : type(type)
{

}

Weapon::~Weapon()
{
	
}


const std::string &Weapon::getType() const
{
	return (this->type);
}

void  Weapon::setType(std::string NewType)
{
	this->type = NewType;	
}