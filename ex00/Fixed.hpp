/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:01:51 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/11/27 12:03:59 by nicolewicki      ###   ########.fr       */
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
        ~Fixed(); // destructor
        Fixed & operator=( const Fixed & rhs ); // assignation operator
        int getRawBits( void ) const; // returns the raw value of the fixed point value
        void setRawBits( int const raw ); // sets the raw value of the fixed point value
};

#endif