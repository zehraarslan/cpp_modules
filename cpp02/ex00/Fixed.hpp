#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int raw_bits;
        const static int fractional_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed & operator=(const Fixed &fixed);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
};



#endif