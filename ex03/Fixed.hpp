/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:04:48 by nlewicki          #+#    #+#             */
/*   Updated: 2024/11/28 13:07:42 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 fixedPointValue;
        static const int    fractionalBits = 8;

    public:
        Fixed();
        Fixed( const Fixed & src );
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        Fixed & operator=( const Fixed & rhs );
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        bool operator>(const Fixed & rhs) const;
        bool operator<(const Fixed & rhs) const;
        bool operator>=(const Fixed & rhs) const;
        bool operator<=(const Fixed & rhs) const;
        bool operator==(const Fixed & rhs) const;
        bool operator!=(const Fixed & rhs) const;

        float operator+(const Fixed & rhs) const;
        float operator-(const Fixed & rhs) const;
        float operator*(const Fixed & rhs) const;
        float operator/(const Fixed & rhs) const;


        Fixed & operator++();
        Fixed operator++(int);
        Fixed & operator--();
        Fixed operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<( std::ostream & o, Fixed const & i );

#endif
