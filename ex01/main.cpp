/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:22:05 by nicolewicki       #+#    #+#             */
/*   Updated: 2024/11/27 16:31:53 by nicolewicki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    Fixed a; // default constructor
    Fixed const b( 10 ); // int constructor
    Fixed const c( 42.42f ); // float constructor
    Fixed const d( b ); // copy constructor
    
    a = Fixed( 1234.4321f ); // assignation operator
    
    std::cout << "a is " << a << std::endl; // output stream operator to print the fixed point value
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl; // toInt() returns the fixed point value as an integer
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    
    return 0;
}