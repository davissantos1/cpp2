/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:13:20 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/23 19:06:10 by dasimoes         ###   ########.fr       */
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
	Fixed	mAB = Fixed((b.y - a.y) / (b.x - a.x));
	Fixed	mBC = Fixed((c.y - b.y) / (c.x - b.x));
	Fixed	mCA = Fixed((a.y - c.y) / (a.x - c.x));

	// Linear coefficient
	Fixed	nAB = Fixed(a.y - (mAB.toFloat() * a.x));
	Fixed	nBC = Fixed(b.y - (mBC.toFloat() * b.x));
	Fixed	nCA = Fixed(c.y - (mCA.toFloat() * c.x));
	
	// Point comparison on the line
	Fixed	pAB = Fixed((mAB.toFloat() * point.x) + nAB.toFloat() - point.y);
	Fixed	pBC = Fixed((mBC.toFloat() * point.x) + nBC.toFloat() - point.y);
	Fixed	pCA = Fixed((mCA.toFloat() * point.x) + nCA.toFloat() - point.y);

	if (!pAB.toInt() || !pBC.toInt() || !pCA.toInt())
		return (false);
	if (pAB.toFloat() > 0 && pBC.toFloat() > 0 && pCA.toInt() > 0)
		return (true);
	if (pAB.toFloat() < 0 && pBC.toFloat() < 0 && pCA.toInt() < 0)
		return (true);
	return (false)
}
