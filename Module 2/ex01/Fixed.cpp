#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : nbr(0)
{
    std::cout <<"\033[32mDefault constructor called\033[37m" << std::endl;
}

Fixed::Fixed (const int nbr)
{
    std::cout <<"\033[32mParametrized constructor called\033[37m" << std::endl;
    this->nbr = nbr << this->bits;
}


Fixed::Fixed (const float nbr)
{
    std::cout <<"\033[32mParametrized constructor called\033[37m" << std::endl;
    this->nbr = roundf(nbr * (1 << this->bits));
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

float Fixed::toFloat(void) const
{
    return ((float)this->nbr / (float)(1 << this->bits));
}

int Fixed::toInt(void) const
{
    return (this->nbr >> this->bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
