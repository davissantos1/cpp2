/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:06:05 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/23 19:19:26 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point(const float x, const float y);
		Point( const Point& other );
		~Point();
		Point&	operator=( const Point& other );
};

#endif
