#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : nbr(0)
{
    std::cout <<"\033[32mDefault constructor called\033[37m" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "\033[34mCopy constructor called\033[37m" << std::endl;
    this->nbr = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "\033[33mCopy assignment operator called\033[37m" << std::endl;
    this->nbr = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "\033[31mDestructor called\033[37m" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "\033[33mgetRawBits member function called\033[37m" << std::endl;
    return (this->nbr);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "\033[33msetRawBits member function called\033[37m" << std::endl;
    this->nbr = raw;
}

Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called