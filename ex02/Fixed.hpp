/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:30:21 by nlewicki          #+#    #+#             */
/*   Updated: 2024/12/02 11:56:53 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 fixedPointValue; // fixed point value
        static const int    fractionalBits = 8; // number of fractional bits

    public:
        Fixed(); // constructor
        Fixed( const Fixed & src ); // copy constructor
        Fixed(const int value); // constructor with int argument
        Fixed(const float value); // constructor with float argument
        ~Fixed(); // destructor
        Fixed & operator=( const Fixed & rhs ); // assignation operator
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const; // convert the fixed point value to a floating point value
        int toInt( void ) const; // convert the fixed point value to an integer value

        bool operator>(const Fixed & rhs) const; // greater than operator
        bool operator<(const Fixed & rhs) const; // less than operator
        bool operator>=(const Fixed & rhs) const; // greater than or equal to operator
        bool operator<=(const Fixed & rhs) const; // less than or equal to operator
        bool operator==(const Fixed & rhs) const; // equal to operator
        bool operator!=(const Fixed & rhs) const; // not equal to operator

        float operator+(const Fixed & rhs) const; // addition operator
        float operator-(const Fixed & rhs) const; // subtraction operator
        float operator*(const Fixed & rhs) const; // multiplication operator
        float operator/(const Fixed & rhs) const; // division operator


        Fixed & operator++(); // pre-increment operator (++a)
        /*
        Fixed a(5);       // Suppose a represents the value 5
        Fixed b = a++;    // a is assigned to b first, then incremented
        // a = 6, b = 5
        */
        Fixed operator++(int); // post-increment operator (a++)
        /*
        Fixed a(5);       // Suppose a represents the value 5
        Fixed b = a++;    // a is assigned to b first, then incremented
        // a = 6, b = 5
        */
        Fixed & operator--(); // pre-decrement operator (--a)
        Fixed operator--(int); // post-decrement operator (a--)
        // in our case, increment by the smallest representable value (1/256) and decrement by the smallest representable value (1/256) = 0.00390625

        static Fixed &min(Fixed &a, Fixed &b); // returns the smallest of two modifiable Fixed values
        static const Fixed &min(const Fixed &a, const Fixed &b); // returns the smallest of two read-only Fixed values
        static Fixed &max(Fixed &a, Fixed &b); // returns the largest of two modifiable Fixed values
        static const Fixed &max(const Fixed &a, const Fixed &b); // returns the largest of two read-only Fixed values
        // static functions do not have access to instance specific data
        // can be called without creating an instance of the class
};

std::ostream &operator<<( std::ostream & o, Fixed const & i ); // output stream operator to print the fixed point value

#endif


/*
can call min or max directly on the class without needing an instance, like this:

Fixed a(10);  // Fixed object with value 10
Fixed b(20);  // Fixed object with value 20

Fixed &smaller = Fixed::min(a, b);
Fixed &larger = Fixed::max(a, b);


if these methods were non-static, you would need to call them on an instance of Fixed like so:
Fixed smaller = a.min(b)
Fixed larger = a.max(b)
*/
