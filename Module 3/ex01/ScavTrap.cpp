#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << GREEN << "Unnamed ScavTrap Default Constructor Called!" << std::endl;
	Name = "Unnamed";
	HitPts = 100;
	EnergyPts = 50;
	AttackDmg = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << GREEN << "ScavTrap " << BLUE << name << GREEN << " Default Constructor Called!" << std::endl;
	HitPts = 100;
	EnergyPts = 50;
	AttackDmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scav)
{
	Name = scav.Name;
	HitPts = scav.HitPts;
	EnergyPts = scav.EnergyPts;
	AttackDmg = scav.AttackDmg;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scav)
{
	this->Name = scav.Name;
	this->HitPts = scav.HitPts;
	this->EnergyPts = scav.EnergyPts;
	this->AttackDmg = scav.AttackDmg;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap " << BLUE << Name << RED << " Default Destructor Called!" << WHITE << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << BLUE << Name << WHITE << " is now in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->EnergyPts > 0 && this->HitPts > 0)
	{
		std::cout  << BLUE << this->Name << WHITE << ", THE DAMNED SCAVTRAPIAN" << WHITE << " attacks " << target << ", causing " << this->AttackDmg << " points of damage!" << std::endl;
		this->EnergyPts--;
	}
	else
		std::cout << BLUE << this->Name << WHITE << " is out of energy!" << std::endl;
}