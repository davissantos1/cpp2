/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:13:20 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/24 12:13:14 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Reduced line equation is y = mx + n, where m is the angular coefficient.

	To calculate m you need 2 points and you do:
							m = (y2 - y1) / (x2 - x1)

	To calculate n you need m and one set of coordinates, so you do:
							n = y1 - mx1
*/

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	// Angular coefficient
	Fixed	mAB = Fixed((b.getY() - a.getY()) / (b.getX() - a.getX()));
	Fixed	mBC = Fixed((c.getY() - b.getY()) / (c.getX() - b.getX()));
	Fixed	mCA = Fixed((a.getY() - c.getY()) / (a.getX() - c.getX()));

	// Linear coefficient
	Fixed	nAB = Fixed(a.getY() - (mAB.toFloat() * a.getX()));
	Fixed	nBC = Fixed(b.getY() - (mBC.toFloat() * b.getX()));
	Fixed	nCA = Fixed(c.getY() - (mCA.toFloat() * c.getX()));
	
	// Point comparison on the line
	Fixed	pAB = Fixed((mAB.toFloat() * point.getX()) + nAB.toFloat() - point.getY());
	Fixed	pBC = Fixed((mBC.toFloat() * point.getX()) + nBC.toFloat() - point.getY());
	Fixed	pCA = Fixed((mCA.toFloat() * point.getX()) + nCA.toFloat() - point.getY());

	if (!pAB.toInt() || !pBC.toInt() || !pCA.toInt())
		return (false);
	if (pAB.toFloat() > 0 && pBC.toFloat() > 0 && pCA.toInt() > 0)
		return (true);
	if (pAB.toFloat() < 0 && pBC.toFloat() < 0 && pCA.toInt() < 0)
		return (true);
	return (false);
}
