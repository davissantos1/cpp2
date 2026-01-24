/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:15:38 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/24 12:12:50 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(const float argX, const float argY) :x(Fixed(argX)), y(Fixed(argY)) {}

Point::Point( const Point& other ) : x(other.x), y(other.y) {}

Point::~Point() {}

Point&	Point::operator=( const Point& other )
{
	(void) other;
	std::cerr << "Invalid operation." << std::endl;
	return (*this);
}

float	Point::getX() const
{
	return (this->x.toFloat());
}

float	Point::getY() const
{
	return (this->y.toFloat());
}
