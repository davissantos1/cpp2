/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:06:05 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/24 12:23:49 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	x;
		Fixed const y;
	public:
		Point();
		Point(const float x, const float y);
		Point( const Point& other );
		~Point();
		Point&	operator=( const Point& other );
		float	getX() const;
		float	getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
