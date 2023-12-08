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

        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif