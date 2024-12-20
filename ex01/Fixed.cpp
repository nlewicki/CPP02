/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:21:50 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/12/02 11:47:23 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) // initialize the fixed point value to 0
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src ) // copy constructor
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src; // delegate the assignation operator to copy the fixed point value
}

Fixed::Fixed(const int intvalue) // constructor with int argument (essentially multiplying by 2^fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = intvalue << this->fractionalBits; // shift the integer value to the left by the number of fractional bits to get the fixed point value
}

Fixed::Fixed(const float floatvalue) // constructor with float argument (multiply by 2^fractionalBits and round to the nearest integer)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(floatvalue * (1 << this->fractionalBits)); // multiply the float value by 2^fractionalBits and round to the nearest integer to get the fixed point value
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( const Fixed & rhs ) // assignation operator
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
