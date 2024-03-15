# ifndef FragTRAP_HPP
#define FragTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap &Frag);
        FragTrap &operator=(const FragTrap &Frag);
        ~FragTrap();

        void attack(const std::string& target);
        void highFivesGuys();
};

#endif