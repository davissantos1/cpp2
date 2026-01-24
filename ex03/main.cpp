/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:25:10 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/24 12:22:48 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) 
{
	Point a(2 , 0);
	Point b(5 , 10);
	Point c(20 , 0);

	Point p1(5 , 0);
	Point p2(5 , 100);
	Point p3(5, 5);
	
	std::cout << "Test for p1 (should be false): " << bsp(a, b, c, p1) << std::endl;
	std::cout << "Test for p2 (should be false): " << bsp(a, b, c, p2) << std::endl;
	std::cout << "Test for p3 (should be true): " << bsp(a, b, c, p3) << std::endl;

	return 0;
}
