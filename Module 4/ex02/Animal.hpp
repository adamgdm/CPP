#pragma once

# include <iostream>
# include <string>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define GRAY "\033[0;37m"
# define CYAN "\033[0;36m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# define BLUE "\033[0;34m"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &copy);

		std::string getType() const;
		virtual void makeSound() const = 0;
};