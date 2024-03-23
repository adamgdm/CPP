#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Idea Number " + std::to_string(i + 1) + "!";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = copy.ideas[i];		
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i > 99)
		return ("Invalid index");
	return (ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i > 99)
		return ;
	ideas[i] = idea;
}
