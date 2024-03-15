#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Unnamed"), HitPts(10), EnergyPts(10), AttackDmg(0)
{
	std::cout << GREEN << "Unnamed ClapTrap Default Constructor Called!" << WHITE << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : Name(name), HitPts(10), EnergyPts(10), AttackDmg(0)
{
	if (name == "")
		Name = "Unnamed";
	std::cout << GREEN << "ClapTrap " << BLUE << Name << GREEN << " Default Constructor Called!" << WHITE << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
	this->Name = clap.Name;
	this->AttackDmg = clap.AttackDmg;
	this->HitPts = clap.HitPts;
	this->EnergyPts = clap.EnergyPts;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& clap)
{
	this->Name = clap.Name;
	this->AttackDmg = clap.AttackDmg;
	this->HitPts = clap.HitPts;
	this->EnergyPts = clap.EnergyPts;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap " << BLUE << Name << RED << " Default Destructor Called!" << WHITE << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPts > 0 && this->HitPts > 0)
	{
		std::cout << BLUE <<this->Name << WHITE << " attacks " << target << ", causing " << this->AttackDmg << " points of damage!" << std::endl;
		this->EnergyPts--;
	}
	else
		std::cout << BLUE << this->Name << WHITE << " is out of energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPts - amount <= 0)
    {
        this->HitPts = 0;
        std::cout << BLUE << this->Name << WHITE << " took " << amount << " points of damage and died!" << std::endl;
    }
    else
    {
        this->HitPts -= amount;
        std::cout << BLUE <<this->Name << WHITE << " took " << amount << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HitPts <= 0)
        std::cout << BLUE << this->Name << WHITE << " is dead!" << std::endl;
    else if (this->EnergyPts <= 0)
		std::cout << BLUE << this->Name << WHITE << " is out of energy!" << std::endl;
    else
    {
        this->HitPts += amount;
        this->EnergyPts--;
		std::cout << BLUE << this->Name << WHITE << " was repaired for " << amount << " points of damage!" << std::endl;
    }
}