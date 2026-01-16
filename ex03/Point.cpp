/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:15:38 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/15 23:27:40 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0)
{
}

Point::Point(const float argX, const float argY)
{
	this->x = argX;
	this->y = argY;
}

Point::Point( const Point& other )
{
	other.x = this->x;
	other.y = this->y;
}

Point::~Point()
{
}

Point&	operator=( Point& other )
{
	if (this != other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

