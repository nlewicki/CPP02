/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:21:56 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/11/28 11:22:02 by nlewicki         ###   ########.fr       */
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
};

std::ostream &operator<<( std::ostream & o, Fixed const & i ); // output stream operator to print the fixed point value

#endif
