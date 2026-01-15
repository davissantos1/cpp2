/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:25:53 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/13 14:56:09 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout	<< "Copy assignment operator called"
				<< std::endl;

	if (this != &other)
		this->_value = other._value;

	return (*this);
}

Fixed::Fixed() :
	_value(0)
{
	std::cout	<< "Default constructor called"
				<< std::endl;
}

Fixed::Fixed( const Fixed& other )
{
	std::cout	<< "Copy constructor called"
				<< std::endl;
	*this = other;
}

Fixed::Fixed( const int c_int )
{
	std::cout	<< "Int constructor called"
				<<	std::endl;

	this->_value = c_int << _fractional_bits;
}

Fixed::Fixed( const float c_float )
{
	std::cout	<< "Float constructor called"
				<<	std::endl;

	this->_value = (int)((roundf( c_float * (1 << _fractional_bits))));
}

Fixed::~Fixed()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout	<< "setRawBits member function called"
				<< std::endl;

	this->_value = raw;
}

int		Fixed::getRawBits( void ) const
{	
	std::cout	<< "getRawBits member function called"
				<< std::endl;

	return (this->_value);
}

float	Fixed::toFloat( void ) const
{
	return ((float) this->_value) / (1 << _fractional_bits);
}

int		Fixed::toInt( void ) const
{
	return ((int) (this->_value >> _fractional_bits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out	<< fixed.toFloat();
	return (out);
}
