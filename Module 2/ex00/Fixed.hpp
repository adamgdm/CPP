#ifndef FIXED_PT_HPP
# define FIXED_PT_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int nbr;
        static const int bits;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif