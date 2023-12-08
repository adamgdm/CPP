#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : nbr(0)
{
}

Fixed::Fixed (const int nbr)
{
    this->nbr = nbr << this->bits;
}


Fixed::Fixed (const float nbr)
{
    this->nbr = roundf(nbr * (1 << this->bits));
}

Fixed::Fixed(const Fixed &fixed)
{
    this->nbr = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    this->nbr = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return (this->nbr);
}

void Fixed::setRawBits(int const raw)
{
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

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed result;

    result.setRawBits(this->getRawBits() + fixed.getRawBits());
    return (result);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed result;

    result.setRawBits(this->getRawBits() - fixed.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed result;

    result.setRawBits((this->getRawBits() * fixed.getRawBits()) >> this->bits);
    return (result);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed result;

    if (fixed.getRawBits() == 0)
    {
        std::cout << "\033[31mError: division by zero\033[37m" << std::endl;
        return (result);
    }
    result.setRawBits((this->getRawBits() << this->bits) / fixed.getRawBits());
    return (result);
}

Fixed Fixed::operator++()
{
    this->nbr += 1;
    return (*this);
}  

Fixed Fixed::operator++(int)
{
    Fixed result(*this);
    this->nbr += 1;
    return (result);
}

Fixed Fixed::operator--()
{
    this->nbr -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed result(*this);
    this->nbr -= 1;
    return (result);
}

bool Fixed::operator>(const Fixed &fixed) const
{
    if (this->getRawBits() > fixed.getRawBits())
        return (true);
    return(false);
}

bool Fixed::operator<(const Fixed &fixed) const
{
    if (this->getRawBits() < fixed.getRawBits())
        return (true);
    return(false);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    if (this->getRawBits() <= fixed.getRawBits())
        return (true);
    return(false);
}


bool Fixed::operator>=(const Fixed &fixed) const
{
    if (this->getRawBits() >= fixed.getRawBits())
        return (true);
    return(false);
}


bool Fixed::operator==(const Fixed &fixed) const
{
    if (this->getRawBits() == fixed.getRawBits())
        return (true);
    return(false);
}


bool Fixed::operator!=(const Fixed &fixed) const
{
    if (this->getRawBits() != fixed.getRawBits())
        return (true);
    return(false);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}
