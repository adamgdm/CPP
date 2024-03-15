#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << GREEN << "Unnamed FragTrap Default Constructor Called!" << WHITE << std::endl;
	Name = "Unnamed";
	HitPts = 100;
	EnergyPts = 50;
	AttackDmg = 20;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << GREEN << "FragTrap " << BLUE << name << GREEN << " Default Constructor Called!" << WHITE << std::endl;
	HitPts = 100;
	EnergyPts = 100;
	AttackDmg = 30;
}

FragTrap::FragTrap(const FragTrap &Frag)
{
	Name = Frag.Name;
	HitPts = Frag.HitPts;
	EnergyPts = Frag.EnergyPts;
	AttackDmg = Frag.AttackDmg;
}

FragTrap& FragTrap::operator=(const FragTrap &Frag)
{
	this->Name = Frag.Name;
	this->HitPts = Frag.HitPts;
	this->EnergyPts = Frag.EnergyPts;
	this->AttackDmg = Frag.AttackDmg;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap " << BLUE << Name << RED << " Default Destructor Called!" << WHITE << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << BLUE << Name << WHITE << " wants to high five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->EnergyPts > 0 && this->HitPts > 0)
	{
		std::cout  << BLUE << this->Name << WHITE << ", THE DAMNED FRAGTRAPIAN" << " attacks " << target << ", causing " << this->AttackDmg << " points of damage!" << std::endl;
		this->EnergyPts--;
	}
	else
		std::cout << BLUE << this->Name << WHITE << " is out of energy!" << std::endl;
}