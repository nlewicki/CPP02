/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:21:50 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/11/27 16:32:52 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int intvalue) // constructor with int argument
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = intvalue << this->fractionalBits;
}

Fixed::Fixed(const float floatvalue) // constructor with float argument
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(floatvalue * (1 << this->fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( const Fixed & rhs )
{
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
        this->fixedPointValue = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)this->fixedPointValue / (1 << this->fractionalBits); // divide the fixed point value by 2^fractionalBits to get the float value
}

int Fixed::toInt( void ) const
{
    return this->fixedPointValue >> this->fractionalBits; // shift the fixed point value to the right by the number of fractional bits to get the integer value
}

std::ostream &operator<<( std::ostream & o, Fixed const & i ) // output stream operator to print the fixed point value
{
    o << i.toFloat(); // output the fixed point value as a float
    return o; // return the output stream
}