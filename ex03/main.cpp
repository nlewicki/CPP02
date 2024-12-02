/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:40:26 by nlewicki          #+#    #+#             */
/*   Updated: 2024/12/02 12:04:06 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	Point p(2.0f, 2.0f);
	Point q(12.0f, 12.0f);
	Point r(5.0f, 6.0f);
	Point s(0.0f, 10.0f);
	Point t(0.0f, 5.0f);
	Point u(4.0f, 4.0f);
	Point v(1.0f, 8.0f);

	std::cout << "Triangle ABC" << std::endl;
	std::cout << "A: " << a.getX() << " " << a.getY() << std::endl;
	std::cout << "B: " << b.getX() << " " << b.getY() << std::endl;
	std::cout << "C: " << c.getX() << " " << c.getY() << std::endl;

	std::cout << std::endl;

	std::cout << "1: Point in the triangle" << std::endl;
	std::cout << "0: Point outside of the triangle or a vertex or on edge" << std::endl;
	std::cout << std::endl;

	std::cout << "[ p ] " << p.getX() << " " << p.getY() << std::endl;
	std::cout << "[ q ] " << q.getX() << " " << q.getY() << std::endl;
	std::cout << "[ r ] " << r.getX() << " " << r.getY() << std::endl;
	std::cout << "[ s ] " << s.getX() << " " << s.getY() << std::endl;
	std::cout << "[ t ] " << t.getX() << " " << t.getY() << std::endl;
	std::cout << "[ u ] " << u.getX() << " " << u.getY() << std::endl;
	std::cout << "[ v ] " << v.getX() << " " << v.getY() << std::endl;

	std::cout << std::endl;

	bool result = bsp(a, b, c, p);
	bool result2 = bsp(a, b, c, q);
	bool result3 = bsp(a, b, c, r);
	bool result4 = bsp(a, b, c, s);
	bool result5 = bsp(a, b, c, t);
	bool result6 = bsp(a, b, c, u);
	bool result7 = bsp(a, b, c, v);

	std::cout << "[ p ] point is in triangle: " << result << std::endl;
	std::cout << "[ q ] point is in triangle: " << result2 << std::endl;
	std::cout << "[ r ] point is in triangle: " << result3 << std::endl;
	std::cout << "[ s ] point is in triangle: " << result4 << std::endl;
	std::cout << "[ t ] point is in triangle: " << result5 << std::endl;
	std::cout << "[ u ] point is in triangle: " << result6 << std::endl;
	std::cout << "[ v ] point is in triangle: " << result7 << std::endl;
	std::cout << std::endl;
}
