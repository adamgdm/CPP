#ifndef ZOMBIE_EX1_HPP
# define ZOMBIE_EX1_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();

		void nameTheZombie(std::string String);
		void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif