#ifndef CONTACT_PHONEBOOK_HPP
# define CONTACT_PHONEBOOK_HPP

# include <iostream>
# include <string>

class Contact
{
  private:
	std::string first;
	std::string last;
	std::string nickname;
	std::string number;
	std::string secret;
	int is_full;

  public:
	Contact();
	Contact(std::string first, std::string last, std::string nickname,
			std::string number, std::string secret);
	std::string retrieve_first();
	std::string retrieve_last();
	std::string retrieve_nickname();
	std::string retrieve_number();
	std::string retrieve_secret();
	int retrieve_is_full();
	~Contact();
};

#endif