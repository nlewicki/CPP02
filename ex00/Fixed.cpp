/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:01:43 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/11/27 12:17:36 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) // constructor get called when the object is created with no arguments
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src ) // copy constructor is called when the object is created as a copy with another object as argument
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() // destructor
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( const Fixed & rhs ) // assignation operator is called when u assign an object to another object
{
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs) // prevents copying the object to itself (rhs is the right hand side object)
        this->fixedPointValue = rhs.getRawBits(); // copy the value
    return *this; // return the object (allows chained assignments like a = b = c)
}

/*
Default constructor: Creating a blank object
Copy constructor: Creating a perfect clone of another object
Copy assignment: Updating an existing object to be a clone of another
*/

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue; // return the fixed point value
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw; // set the fixed point value to the raw value passed as argument
}