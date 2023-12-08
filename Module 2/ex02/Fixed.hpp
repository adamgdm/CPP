#ifndef FIXED_PT_HPP
# define FIXED_PT_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int nbr;
        static const int bits;
    public:
        Fixed();
        Fixed(const int nbr);
        Fixed(const float nbr);
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed();

        Fixed operator+(const Fixed &fixed) const;
        Fixed operator-(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed operator/(const Fixed &fixed) const;

        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);

        bool operator>(const Fixed &fixed) const;
        bool operator<(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed) const;
        bool operator<=(const Fixed &fixed) const;
        bool operator==(const Fixed &fixed) const;
        bool operator!=(const Fixed &fixed) const;

    	static Fixed& min(Fixed& a, Fixed& b);
    	static const Fixed& min(const Fixed& a, const Fixed& b);
    	static Fixed& max(Fixed& a, Fixed& b);
	    static const Fixed& max(const Fixed& a, const Fixed& b);

        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif