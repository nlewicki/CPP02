/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:01:51 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/11/28 11:22:54 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 fixedPointValue; // fixed point value
        static const int    fractionalBits = 8; // number of fractional bits (256 = 1, because of 8 fractional bits)

    public:
        Fixed(); // constructor
        ~Fixed(); // destructor
        Fixed( const Fixed & src ); // copy constructor
        Fixed & operator=( const Fixed & rhs ); // assignation operator
        int getRawBits( void ) const; // returns the raw value of the fixed point value
        void setRawBits( int const raw ); // sets the raw value of the fixed point value
};

#endif
