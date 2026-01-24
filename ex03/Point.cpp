/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:15:38 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/23 19:18:59 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0)
{
}

Point::Point(const float argX, const float argY) :
	x(Fixed(argX)),
	y(Fixed(argY))
{
}

Point::Point( const Point& other ) :
	x(other.x),
	y(other.y)
{
}

Point::~Point()
{
}

Point&	Point::operator=( const Point& other )
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

