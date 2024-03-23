#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  std::cout << RESET;

  std::cout << std::endl << YELLOW << "My tests : " << RESET << std::endl << std::endl;
  std::cout << RED << "====> Deleting the previously allocated memory" << RESET << std::endl;
  std::cout << BLUE << "> Animal Class Meta :" << RESET << std::endl; 
  delete meta;	
  std::cout << BLUE << "> Dog Class J :" << RESET << std::endl;
  delete j;
  std::cout << BLUE << "> Cat Class I :" << RESET << std::endl;
  delete i;

  std::cout << std::endl << PURPLE << "====> Test with WrongAnimal and WrongCat : " << RESET << std::endl;

  std::cout << GRAY << "> Creating new instances of WrongAnimal and WrongCat: " << RESET << std::endl;
  const WrongAnimal* first = new WrongAnimal();
  const WrongAnimal* second = new WrongCat();
  const WrongCat* third = new WrongCat();

  std::cout << GRAY << "> Calling makeSound() on each instance" << RESET << std::endl;
  std::cout << CYAN;
  first->makeSound();
  second->makeSound();
  third->makeSound();
  std::cout << RESET;

  std::cout << std::endl << RED << "====> Deleting the previously allocated memory" << RESET << std::endl;
  std::cout << BLUE << "> WrongAnimal Class First :" << RESET << std::endl;
  delete first;
  std::cout << BLUE << "> WrongAnimal Class Second :" << RESET << std::endl;
  delete second;
  std::cout << BLUE << "> WrongCat Class Third :" << RESET << std::endl;
  delete third;
  return 0;
}
