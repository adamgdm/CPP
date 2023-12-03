#include "Zombie.hpp"

int main()
{
	Zombie *ptr;

	ptr = zombieHorde(3, "Adam");
	if (!ptr)
	{
		std::cout << "Allocation Failed!" << std::endl;
		return (1);
	}
	for (int i = 0; i < 3; i++)
		ptr->announce();
	delete[] ptr;
	ptr = NULL;
	return (0);
}