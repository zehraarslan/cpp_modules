#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->raw_bits = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int raw)
{
    std::cout << "Int constructor called" << std::endl;
    this->raw_bits = raw << Fixed::fractional_bits;
}

Fixed::Fixed(const float raw)
{
    std::cout << "Float constructor called" << std::endl;
    this->raw_bits = raw * (double)(1 << Fixed::fractional_bits); 
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw_bits = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->raw_bits;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "getRawBits member function called" << std::endl;
    this->raw_bits = raw;
}

float Fixed::toFloat(void) const
{
    return ((double)(this->getRawBits()) / (double)(1 << Fixed::fractional_bits));
}

int Fixed::toInt(void) const
{
    return (this->getRawBits() >> Fixed::fractional_bits);
}

std::ostream & operator<<(std::ostream &output, const Fixed &fixed)
{
    output << fixed.toFloat();
    return (output);
}
