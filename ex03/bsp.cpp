/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:13:20 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/24 16:19:00 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The idea is to calculate the general line equation for each line, AB, BC and CA,
	then I'd place the other vertice into such equation and the point and compare their
	sign, If the 3 comparisons hold true, then the point is inside the triangle,
	otherwise the point is not inside the triangle.
	
	Ax + By + c = 0

	A = (y1 - y2)
	B = (x2 - x1)
	C = (x1y2 - x2y1)
*/

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	// line AB
	Fixed aAB = Fixed( a.getY() - b.getY() );
	Fixed bAB = Fixed( b.getX() - a.getX() );
	Fixed cAB = Fixed( (a.getX() * b.getY()) - (b.getX() * a.getY()) );
	
	// line BC
	Fixed aBC = Fixed( b.getY() - c.getY() );
	Fixed bBC = Fixed( c.getX() - b.getX() );
	Fixed cBC = Fixed( (b.getX() * c.getY()) - (c.getX() * b.getY()) );

	// line CA
	Fixed aCA = Fixed( c.getY() - a.getY() );
	Fixed bCA = Fixed( a.getX() - c.getX() );
	Fixed cCA = Fixed( (c.getX() * a.getY()) - (a.getX() * c.getY()) );
	
	// point locations
	Fixed pAB = Fixed( (point.getX() * aAB.toFloat()) + (point.getY() * bAB.toFloat()) + cAB.toFloat() );
	Fixed pBC = Fixed( (point.getX() * aBC.toFloat()) + (point.getY() * bBC.toFloat()) + cBC.toFloat() );
	Fixed pCA = Fixed( (point.getX() * aCA.toFloat()) + (point.getY() * bCA.toFloat()) + cCA.toFloat() );

	if (pAB.toFloat() > 0 && pBC.toFloat() > 0 && pCA.toFloat() > 0)
		return (true);
	if (pAB.toFloat() < 0 && pBC.toFloat() < 0 && pCA.toFloat() < 0)
		return (true);
	return (false);
}
