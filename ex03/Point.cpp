/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:05:00 by nlewicki          #+#    #+#             */
/*   Updated: 2024/11/28 13:19:34 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) // default constructor that initializes x and y to 0
{
}

Point::Point(const Point &src) : x(src.x), y(src.y) // copy constructor that initializes x and y to the values of src
{
}

Point::Point(const float x, const float y) : x(x), y(y) // constructor that initializes x and y to the values of the parameters
{
}

Point::~Point() // destructor
{
}

Point& Point::operator=(const Point &rhs) // assignation operator that sets x and y to the values of rhs
{
	if (this != &rhs)
	{
		const_cast<Fixed&>(x) = rhs.x;
		const_cast<Fixed&>(y) = rhs.y;
	}
	return *this;
}

bool Point::operator==(const Point &rhs) const // comparison operator that returns true if the x and y values are equal
{
	return x == rhs.x && y == rhs.y; // would also work with this->x and this->y
}

Fixed Point::getX(void) const // returns the x value
{
	return x;
}

Fixed Point::getY(void) const // returns the y value
{
	return y;
}
