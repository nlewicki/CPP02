/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:04:35 by nlewicki          #+#    #+#             */
/*   Updated: 2024/11/29 12:18:55 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src )
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int intvalue)
{
    //std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = intvalue << this->fractionalBits;
}

Fixed::Fixed(const float floatvalue)
{
    //std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(floatvalue * (1 << this->fractionalBits));
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( const Fixed & rhs )
{
    //std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
        this->fixedPointValue = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)this->fixedPointValue / (1 << this->fractionalBits);
}

int Fixed::toInt( void ) const
{
    return this->fixedPointValue >> this->fractionalBits;
}

std::ostream &operator<<( std::ostream & o, Fixed const & i )
{
    o << i.toFloat();
    return o;
}


bool Fixed::operator>(const Fixed & rhs) const
{
    return fixedPointValue > rhs.fixedPointValue;
}

bool Fixed::operator<(const Fixed & rhs) const
{
    return fixedPointValue < rhs.fixedPointValue;
}

bool Fixed::operator>=(const Fixed & rhs) const
{
    return fixedPointValue >= rhs.fixedPointValue;
}

bool Fixed::operator<=(const Fixed & rhs) const
{
    return fixedPointValue <= rhs.fixedPointValue;
}

bool Fixed::operator==(const Fixed & rhs) const
{
    return fixedPointValue == rhs.fixedPointValue;
}

bool Fixed::operator!=(const Fixed & rhs) const
{
    return fixedPointValue != rhs.fixedPointValue;
}



float Fixed::operator+(const Fixed & rhs) const
{
    return this->toFloat() + rhs.toFloat();
}

float Fixed::operator-(const Fixed & rhs) const
{
    return this->toFloat() - rhs.toFloat();
}

float Fixed::operator*(const Fixed & rhs) const
{
    return this->toFloat() * rhs.toFloat();
}

float Fixed::operator/(const Fixed & rhs) const
{
    return this->toFloat() / rhs.toFloat();
}



Fixed & Fixed::operator++()
{
    this->fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->fixedPointValue++;
    return tmp;
}

Fixed & Fixed::operator--()
{
    this->fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->fixedPointValue--;
    return tmp;
}


Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}
