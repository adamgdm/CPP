#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j; // should not create a leak
    delete i;

	std::cout << std::endl << "+-------------------------------------+ My tests +-------------------------------------+" << std::endl << std::endl;

    const int size = 4;
    Animal** animals = new Animal*[size];

    for (int i = 0; i < size / 2; ++i)
    {
        std::cout << CYAN << "\nCreating a new Dog..." << RESET << std::endl;
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i)
    {
        std::cout << PURPLE << "\nCreating a new Cat..." << RESET << std::endl;
        animals[i] = new Cat();
	}

	std::cout << BLUE << "\nDeleting all animals..." << RESET << std::endl;
    for (int i = 0; i < size; ++i)
        delete animals[i];
    delete[] animals;

    std::cout << std::endl;
    std::cout << BLUE << "\nTesting deep copy for Dog..." << RESET << std::endl;
	Dog basica;
	{
		Dog tmp = basica;
	}
	std::cout << "check for deep copy: If the brain destructor is called twice, then it's a shallow copy" << std::endl;

    std::cout << BLUE << "\nTesting deep copy for Cat..." << RESET << std::endl;
	Cat basic;
	{
		Cat tmp = basic;
	}
	std::cout << "check for deep copy: If the brain destructor is called twice, then it's a shallow copy" << std::endl;
	std::cout << std::endl << std::endl << std::endl;
    return 0;
}