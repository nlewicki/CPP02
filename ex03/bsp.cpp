/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:05:15 by nlewicki          #+#    #+#             */
/*   Updated: 2024/11/29 13:36:14 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float calcAngleVectors(Point const u, Point const v)
{
	float dotProduct = u.getX().toFloat() * v.getX().toFloat() + u.getY().toFloat() * v.getY().toFloat();
	float magnitudeU = sqrt(pow(u.getX().toFloat(), 2) + pow(u.getY().toFloat(), 2));
	float magnitudeV = sqrt(pow(v.getX().toFloat(), 2) + pow(v.getY().toFloat(), 2));

	return acos(dotProduct / (magnitudeU * magnitudeV));
}

float calculateAngle(Point const a, Point const b, Point const c, Point const p)
{
	Point pa(a.getX() - p.getX(), a.getY() - p.getY());
	Point pb(b.getX() - p.getX(), b.getY() - p.getY());
	Point pc(c.getX() - p.getX(), c.getY() - p.getY());

	float angle1 = calcAngleVectors(pa, pb);
	float angle2 = calcAngleVectors(pb, pc);
	float angle3 = calcAngleVectors(pc, pa);

	if (std::abs(angle1 - M_PI) < 0.0001f || std::abs(angle2 - M_PI) < 0.0001f || std::abs(angle3 - M_PI) < 0.0001f)
		return 23.0f;
	return angle1 + angle2 + angle3;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float angle;

	angle = calculateAngle(a, b, c, point);

	std::cout << "angle: " << angle << std::endl;

	return (std::abs(angle - 2 * M_PI) < 0.0001f);
}

