#include "main.hpp"

Contact::Contact() : first(""), last(""), nickname(""),number(""), secret(""), is_full(0)
{

}

Contact::~Contact()
{

}

Contact::Contact(std::string first, std::string last, std::string nickname, std::string number, std::string secret) 
{
	this->first = first;
	this->last = last;
	this->nickname = nickname;
	this->number = number;
	this->secret = secret;
	this->is_full = 1;
}
std::string Contact::retrieve_first()
{
	return (this->first);
}
std::string Contact::retrieve_last()
{
	return (this->last);
}
std::string Contact::retrieve_nickname()
{
	return (this->nickname);
}
std::string Contact::retrieve_number()
{
	return (this->number);
}
std::string Contact::retrieve_secret()
{
	return (this->secret);
}
int Contact::retrieve_is_full()
{
	return (this->is_full);
}