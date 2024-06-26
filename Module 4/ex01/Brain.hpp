#pragma once

# include <iostream>
# include <string>

class Brain
{
	private :
		std::string ideas[100];
	public :
		Brain();
		Brain(const Brain &copy);
		virtual ~Brain();
		Brain &operator=(const Brain &copy);

		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
};
