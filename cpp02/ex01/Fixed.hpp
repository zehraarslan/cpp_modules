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
        Fixed(const int raw);
        Fixed(const float raw);
        Fixed(const Fixed &fixed);
        Fixed & operator=(const Fixed &fixed);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream & operator<<(std::ostream &output, const Fixed &fixed);

#endif