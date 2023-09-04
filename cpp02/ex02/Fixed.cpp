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

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw_bits = fixed.getRawBits();
    return (*this);
}

Fixed::Fixed(const int raw)
{
    std::cout << "Int constructor called" << std::endl;
    this->raw_bits = raw << Fixed::fractional_bits;
}

Fixed::Fixed(const float raw)
{
    std::cout << "Float constructor called" << std::endl;
    this->raw_bits = roundf(raw * (double)(1 << Fixed::fractional_bits)); 
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->raw_bits);
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

bool Fixed::operator>(const Fixed &fixed)
{
    return (this->toFloat() > fixed.toFloat() ? true : false);
}

bool Fixed::operator<(const Fixed &fixed)
{
    return (this->toFloat() < fixed.toFloat() ? true : false);
}

bool Fixed::operator>=(const Fixed &fixed)
{
    return (this->toFloat() >= fixed.toFloat() ? true : false);
}

bool Fixed::operator<=(const Fixed &fixed)
{
    return (this->toFloat() <= fixed.toFloat() ? true : false);
}

bool Fixed::operator==(const Fixed &fixed)
{
    return (this->toFloat() == fixed.toFloat() ? true : false);
}

bool Fixed::operator!=(const Fixed &fixed)
{
    return (this->toFloat() != fixed.toFloat() ? true : false);
}

Fixed Fixed::operator+(const Fixed &fixed)
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed)
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed)
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed)
{
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed Fixed::operator++()
{
    this->raw_bits++;
    return (*this);
}

Fixed Fixed::operator++(int raw)
{
    Fixed tmp = *this;
    this->raw_bits++;
    return tmp;
}

Fixed Fixed::operator--()
{
    this->raw_bits--;
    return (*this);
}

Fixed Fixed::operator--(int raw)
{
    Fixed tmp = *this;
    this->raw_bits--;
    return (tmp);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    return (fixed1.getRawBits() < fixed2.getRawBits() ? fixed1 : fixed2);
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
    return (fixed1.getRawBits() < fixed2.getRawBits() ? fixed1 : fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    return (fixed1.getRawBits() > fixed2.getRawBits() ? fixed1 : fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
    return (fixed1.getRawBits() > fixed2.getRawBits() ? fixed1 : fixed2);
}

std::ostream & operator<<(std::ostream &output, const Fixed &fixed)
{
    output << fixed.toFloat();
    return (output);
}
