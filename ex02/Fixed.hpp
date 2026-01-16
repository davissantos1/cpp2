/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:13:17 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/15 21:23:54 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int	_value;
		static const int _fractional_bits = 8;
		
	public:
		Fixed();
		~Fixed();
		Fixed( const Fixed& other );
		Fixed( const int c_int );
		Fixed( const float c_float );

		Fixed&	operator=(const Fixed& other);
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed&	min( Fixed& a, Fixed& b );
		static const Fixed&	min( const Fixed& a, const Fixed& b );
		static Fixed&	max( Fixed& a, Fixed& b );
		static const Fixed&	max( const Fixed& a, const Fixed& b );
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
