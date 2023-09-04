#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

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

        bool operator>(const Fixed &fixed);
        bool operator<(const Fixed &fixed);
        bool operator>=(const Fixed &fixed);
        bool operator<=(const Fixed &fixed);
        bool operator==(const Fixed &fixed);
        bool operator!=(const Fixed &fixed);

        Fixed operator+(const Fixed &fixed);
        Fixed operator-(const Fixed &fixed);
        Fixed operator*(const Fixed &fixed);
        Fixed operator/(const Fixed &fixed);

        Fixed operator++();
        Fixed operator++(int raw);
        Fixed operator--();
        Fixed operator--(int raw);

        static Fixed &min(Fixed &fixed1, Fixed &fixed2);
        static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
        static Fixed &max(Fixed &fixed1, Fixed &fixed2);
        static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream & operator<<(std::ostream &output, const Fixed &fixed);

#endif