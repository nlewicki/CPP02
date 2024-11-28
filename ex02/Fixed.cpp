/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:30:13 by nlewicki          #+#    #+#             */
/*   Updated: 2024/11/28 11:58:21 by nlewicki         ###   ########.fr       */
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
    this->fixedPointValue = intvalue << this->fractionalBits;
}

Fixed::Fixed(const float floatvalue) // constructor with float argument (multiply by 2^fractionalBits and round to the nearest integer)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(floatvalue * (1 << this->fractionalBits));
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

//------------------------------------------------------------------------------------------------------------------------


bool Fixed::operator>(const Fixed & rhs) const
{
    return fixedPointValue > rhs.fixedPointValue; // return true if the fixed point value is greater than the fixed point value of the right-hand side
}

bool Fixed::operator<(const Fixed & rhs) const
{
    return fixedPointValue < rhs.fixedPointValue; // return true if the fixed point value is less than the fixed point value of the right-hand side
}

bool Fixed::operator>=(const Fixed & rhs) const
{
    return fixedPointValue >= rhs.fixedPointValue; // return true if the fixed point value is greater than or equal to the fixed point value of the right-hand side
}

bool Fixed::operator<=(const Fixed & rhs) const
{
    return fixedPointValue <= rhs.fixedPointValue; // return true if the fixed point value is less than or equal to the fixed point value of the right-hand side
}

bool Fixed::operator==(const Fixed & rhs) const
{
    return fixedPointValue == rhs.fixedPointValue; // return true if the fixed point value is equal to the fixed point value of the right-hand side
}

bool Fixed::operator!=(const Fixed & rhs) const
{
    return fixedPointValue != rhs.fixedPointValue; // return true if the fixed point value is not equal to the fixed point value of the right-hand side
}



float Fixed::operator+(const Fixed & rhs) const
{
    return this->toFloat() + rhs.toFloat(); // return the sum of the fixed point value and the fixed point value of the right-hand side
}

float Fixed::operator-(const Fixed & rhs) const
{
    return this->toFloat() - rhs.toFloat(); // return the difference between the fixed point value and the fixed point value of the right-hand side
}

float Fixed::operator*(const Fixed & rhs) const
{
    return this->toFloat() * rhs.toFloat(); // return the product of the fixed point value and the fixed point value of the right-hand side
}

float Fixed::operator/(const Fixed & rhs) const
{
    return this->toFloat() / rhs.toFloat(); // return the quotient of the fixed point value and the fixed point value of the right-hand side
}



Fixed & Fixed::operator++() // pre-increment operator (++a)
{
    this->fixedPointValue++; // increment the fixed point value
    return *this; // return the fixed point value
}

Fixed Fixed::operator++(int) // post-increment operator (a++)
{
    Fixed tmp(*this); // create a temporary fixed point value
    this->fixedPointValue++; // increment the fixed point value
    return tmp; // return the temporary fixed point value
}

Fixed & Fixed::operator--() // pre-decrement operator (--a)
{
    this->fixedPointValue--; // decrement the fixed point value
    return *this; // return the fixed point value
}

Fixed Fixed::operator--(int) // post-decrement operator (a--)
{
    Fixed tmp(*this); // create a temporary fixed point value
    this->fixedPointValue--; // decrement the fixed point value
    return tmp; // return the temporary fixed point value
}


Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b; // return the smaller of the two fixed point values
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b; // return the smaller of the two fixed point values
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b; // return the larger of the two fixed point values
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b; // return the larger of the two fixed point values
}
